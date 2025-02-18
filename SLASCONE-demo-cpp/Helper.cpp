#include "Helper.h"
#include <fstream>
#include <future>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "LicenseXmlValidator/LicenseXmlValidator.h"

using namespace std;
using namespace web::http::client;
using namespace org::openapitools::client::api;
using namespace utility::conversions;
using namespace SLASCONE_demo_cpp;

// CHANGE these values according to your environment at: https://my.slascone.com/info

//Use this to connect to the Argus Demo 
const string baseUrl = "https://api.slascone.com";

//Use this instead to connect to the SaaS environment
//const string baseUrl = "https://api365.slascone.com";

// ISV ID
const string isvId = "2af5fe02-6207-4214-946e-b00ac5309f53"; // Find your own Isv Id at : https://my.slascone.com/administration/apikeys

// Product ID
const string productId = "b18657cc-1f7c-43fa-e3a4-08da6fa41ad3"; // Find your own product id key at : https://my.slascone.com/products

// Provisioning key header
const string provisioningKeyHeader = "ProvisioningKey";

// Provisioning key
const string provisioningKey = "NfEpJ2DFfgczdYqOjvmlgP2O/4VlqmRHXNE9xDXbqZcOwXTbH3TFeBAKKbEzga7D7ashHxFtZOR142LYgKWdNocibDgN75/P58YNvUZafLdaie7eGwI/2gX/XuDPtqDW";

const string licenseKey = "27180460-29df-4a5a-a0a1-78c85ab6cee0"; // Just for demo, do not change this

// CHANGE these values according to your environment at: https://my.slascone.com/administration/signature
const string pemKey =
R"(-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAwpigzm+cZIyw6x253YRD
mroGQyo0rO9qpOdbNAkE/FMSX+At5CQT/Cyr0eZTo2h+MO5gn5a6dwg2SYB/K1Yt
yuiKqnaEUfoPnG51KLrj8hi9LoZyIenfsQnxPz+r8XGCUPeS9MhBEVvT4ba0x9Ew
R+krU87VqfI3KNpFQVdLPaZxN4STTEZaet7nReeNtnnZFYaUt5XeNPB0b0rGfrps
y7drmZz81dlWoRcLrBRpkf6XrOTX4yFxe/3HJ8mpukuvdweUBFoQ0xOHmG9pNQ31
AHGtgLYGjbKcW4xYmpDGl0txfcipAr1zMj7X3oCO9lHcFRnXdzx+TTeJYxQX2XVb
hQIDAQAB
-----END PUBLIC KEY-----)";

/**
 * Helper:
 * 
 */
Helper::Helper(/* args */)
{
    // Build an Api configuration
	shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration);
    
    // Set URL to the API server
	apiConfig->setBaseUrl(baseUrl);

    // Set timeout to 15 seconds
    shared_ptr<http_client_config> httpConfig(new http_client_config);
    httpConfig->set_timeout(chrono::seconds(15));
	apiConfig->setHttpConfig(*httpConfig);

    // Set provisioning key for authentication
	apiConfig->setApiKey(provisioningKeyHeader, provisioningKey);

    // Build the SLACONE client
    apiClient = make_shared<SlasconeApiClient>(pemKey.c_str(), apiConfig);

    // Create the data gathering API instance
    dataGatheringApi = make_unique<DataGatheringApi>(apiClient);

    // Create the provisioning API instance
    provisioningApi = make_unique<ProvisioningApi>(apiClient);
}

Helper::~Helper()
{
    // Free the provisioning API instance
    provisioningApi.reset();

    // Clean up the OpenSSL library
    ERR_free_strings();
}

const char* licenseInfoFileName = "licenseInfo.json";

/**
 * activate_license:
 * 
 * Activate a license
 * 
 * @return 0 on success or a negative value if an error occurs.
 */
int Helper::activate_license()
{
    // Reset memorized license info
    licenseInfoDto = nullptr;

    // Build the request body
    shared_ptr<ActivateClientDto> activateLicense = make_shared<ActivateClientDto>();
    activateLicense->setProductId(productId);
    activateLicense->setLicenseKey(licenseKey);
    activateLicense->setClientId(get_device_id());
    activateLicense->setClientName("SLASCONE C++ sample");
    activateLicense->setSoftwareVersion("24.11");

    // Create a promise and future
    auto promise = make_shared<std::promise<shared_ptr<LicenseInfoDto>>>();
    future<shared_ptr<LicenseInfoDto>> future = promise->get_future();

    provisioningApi->activateLicense(isvId, activateLicense)
        .then([promise](pplx::task<shared_ptr<LicenseInfoDto>> licenseInfo) mutable
              {
                try {
                    auto licenseInfoDto = licenseInfo.get();
                    promise->set_value(licenseInfoDto);
                }
                catch (...) {
                    auto ex = current_exception();
                    promise->set_exception(ex);
                } });

    try
    {
        // Get the result
        licenseInfoDto = future.get();
    }
    catch (const ApiException &e)
    {
        // Handle API errors
        handle_api_exception(e);
    }
    catch (const exception &e)
    {
        cout << "activateLicense() exception: " << e.what() << endl;
    }

    if (licenseInfoDto != nullptr)
    {
        // Successfull activation
        print_license(licenseInfoDto);
    }
    else
    {
        cout << "Error: licenseInfoDto is null." << endl;
        return -1;
    }

    return 0;
}

/**
 * send_license_heartbeat:
 * 
 * Send a license heartbeat
 * 
 * @return 0 on success or a negative value if an error occurs.
 */
int Helper::send_license_heartbeat()
{
    // Reset memorized license info
    licenseInfoDto = nullptr;

    // Build the request body
	shared_ptr<AddHeartbeatDto> addHeartbeat = make_shared<AddHeartbeatDto>();
    addHeartbeat->setProductId(productId);
    addHeartbeat->setClientId(get_device_id());
	addHeartbeat->setSoftwareVersion("24.11");
	addHeartbeat->setOperatingSystem(get_os_name());

    // Create a promise and future
    auto promise = make_shared<std::promise<shared_ptr<LicenseInfoDto>>>();
    future<shared_ptr<LicenseInfoDto>> future = promise->get_future();

    provisioningApi->addHeartbeat(isvId, addHeartbeat)
        .then([promise](pplx::task<shared_ptr<LicenseInfoDto>> licenseInfo) mutable
              {
				try {
					auto licenseInfoDto = licenseInfo.get();
					promise->set_value(licenseInfoDto);
				}
				catch (...) {
                    auto ex = current_exception();
					promise->set_exception(ex);
				} });

    try
    {
        licenseInfoDto = future.get();
    }
    catch (const ApiException &e)
    {
        // Handle API errors
        handle_api_exception(e);
    }
    catch (const exception &e)
    {
        cout << "addHeartbeat() exception: " << e.what() << endl;
    }

    if (licenseInfoDto != nullptr)
	{
        // Successfull heartbeat
		print_license(licenseInfoDto);
	}
	else
	{
		cout << "Error: licenseInfoDto is null." << endl;
        return -1;
	}

    return 0;
}

/**
 * find_temp_offline_license:
 * 
 * Find a temporary offline license
 */
int Helper::find_temp_offline_license()
{
    shared_ptr<LicenseInfoDto> licenseInfoDto = std::make_shared<LicenseInfoDto>();

    if (0 == apiClient->TryGetLicenseInfo(licenseInfoDto))
    {
        print_license(licenseInfoDto);
        this->licenseInfoDto = licenseInfoDto;
    }
    else
    {
        cout << "Error: No license info available." << endl;
        cout << "       Please activate the license first or send a license heartbeat." << endl;
        return -1;
    }

    return 0;
}

/**
 * unassign_token:
 * 
 * Unassign a token
 * 
 * @return 0 on success or a negative value if an error occurs.
 */
int Helper::unassign_token()
{
    // Check licenseInfoDto
    if (licenseInfoDto == nullptr)
    {
        cout << "Error: No license info available." << endl;
        cout << "       Please activate the license first or send a license heartbeat." << endl;
        return -1;
    }

    // Build the request body
    shared_ptr<UnassignDto> unassignToken = make_shared<UnassignDto>();
    unassignToken->setTokenKey(licenseInfoDto->getTokenKey());

    // Create a promise and future
    auto promise = make_shared<std::promise<string>>();
    future<string> future = promise->get_future();

    provisioningApi->unassignLicense(isvId, unassignToken)
        .then([promise](pplx::task<string> response) mutable
              {
                try {
                    promise->set_value(response.get());
                }
                catch (...) {
                    auto ex = current_exception();
                    promise->set_exception(ex);
                } });

    try
    {        
        cout << "unassignLicense() response: " << future.get() << endl;

        // Reset memorized license info and temporary offline license
        licenseInfoDto = nullptr;
    }
    catch (const ApiException &e)
    {
        // Handle API errors
        handle_api_exception(e);
        return -1;
    }
    catch (const exception &e)
    {
        cout << "unassignLicense() exception: " << e.what() << endl;
        return -1;
    }

    return 0;
}

int Helper::send_analytical_heartbeat()
{
    // Check licenseInfoDto
    if (licenseInfoDto == nullptr)
    {
        cout << "Error: No license info available." << endl;
        cout << "       Please activate the license first or send a license heartbeat." << endl;
        return -1;
    }

    // Build the request body
    shared_ptr<AnalyticalFieldValueDto> analyticalFieldValueDto = make_shared<AnalyticalFieldValueDto>();
    analyticalFieldValueDto->setAnalyticalFieldId("a5db0ec7-e951-4e97-9b52-3fb7e3c838d8");
    analyticalFieldValueDto->setValue("Analytical heartbeat value");
    vector<shared_ptr<AnalyticalFieldValueDto>> analyticalFieldValues;
    analyticalFieldValues.push_back(analyticalFieldValueDto);

    shared_ptr<AnalyticalHeartbeatDto> addAnalyticalHeartbeat = make_shared<AnalyticalHeartbeatDto>();
    addAnalyticalHeartbeat->setAnalyticalHeartbeat(analyticalFieldValues);
    addAnalyticalHeartbeat->setClientId(get_device_id());   
    addAnalyticalHeartbeat->setTokenKey(licenseInfoDto->getTokenKey());

    // Create a promise and future
    auto promise = make_shared<std::promise<string>>();
    future<string> future = promise->get_future();

    dataGatheringApi->addAnalyticalHeartbeat(isvId, addAnalyticalHeartbeat)
        .then([promise](pplx::task<string> response) mutable
              {
                try {
                    promise->set_value(response.get());
                }
                catch (...) {
                    auto ex = current_exception();
                    promise->set_exception(ex);
                } });

    try
    {
        cout << "addAnalyticalHeartbeat() response: " << future.get() << endl;
    }
    catch (const ApiException &e)
    {
        // Handle API errors
        handle_api_exception(e);
        return -1;
    }
    catch (const exception &e)
    {
        cout << "addAnalyticalHeartbeat() exception: " << e.what() << endl;
        return -1;
    }

    return 0;
}

int Helper::send_usage_heartbeat()
{
    // Check licenseInfoDto
    if (licenseInfoDto == nullptr)
    {
        cout << "Error: No license info available." << endl;
        cout << "       Please activate the license first or send a license heartbeat." << endl;
        return -1;
    }

    // Build the request body
    vector<shared_ptr<UsageHeartbeatValueDto>> usageHeartbeatValues;
    shared_ptr<UsageHeartbeatValueDto> usageHeartbeatValueDto = make_shared<UsageHeartbeatValueDto>();
    usageHeartbeatValueDto->setUsageModuleId("114fa2f5-3c34-42f3-82e6-226ebe54544b");
    usageHeartbeatValueDto->setUsageFeatureId("4b17640f-8aab-4205-be39-d9f9cabca2f1");
    usageHeartbeatValueDto->setValue(3.0);
    usageHeartbeatValues.push_back(usageHeartbeatValueDto);

    shared_ptr<FullUsageHeartbeatDto> addUsageHeartbeat = make_shared<FullUsageHeartbeatDto>();
    addUsageHeartbeat->setClientId(get_device_id());
    addUsageHeartbeat->setTokenKey(licenseInfoDto->getTokenKey());
    addUsageHeartbeat-> setUsageHeartbeat(usageHeartbeatValues);

    // Create a promise and future
    auto promise = make_shared<std::promise<string>>();
    future<string> future = promise->get_future();

    dataGatheringApi->addUsageHeartbeat(isvId, addUsageHeartbeat)
        .then([promise](pplx::task<string> response) mutable
              {
                try {
                    promise->set_value(response.get());
                }
                catch (...) {
                    auto ex = current_exception();
                    promise->set_exception(ex);
                } });

    try
    {
        cout << "addUsageHeartbeat() response: " << future.get() << endl;
    }
    catch (const ApiException &e)
    {
        // Handle API errors
        handle_api_exception(e);
        return -1;
    }
    catch (const exception &e)
    {
        cout << "addUsageHeartbeat() exception: " << e.what() << endl;
        return -1;
    }

    return 0;
}

int Helper::send_consumption_heartbeat()
{
    // Build the request body
    vector<shared_ptr<ConsumptionHeartbeatValueDto>> consumptionHeartbeatValues;
    shared_ptr<ConsumptionHeartbeatValueDto> consumptionHeartbeatValueDto = make_shared<ConsumptionHeartbeatValueDto>();
    consumptionHeartbeatValueDto->setLimitationId("a3814c76-7418-4ea9-a772-08db30da1bdc");
    consumptionHeartbeatValueDto->setValue(1.0);
    consumptionHeartbeatValues.push_back(consumptionHeartbeatValueDto);

    shared_ptr<FullConsumptionHeartbeatDto> addConsumptionHeartbeat = make_shared<FullConsumptionHeartbeatDto>();
    addConsumptionHeartbeat->setClientId(get_device_id());
    addConsumptionHeartbeat->setConsumptionHeartbeat(consumptionHeartbeatValues);

    // Create a promise and future
    auto promise = make_shared<std::promise<vector<shared_ptr<ConsumptionDto>>>>();
    future<vector<shared_ptr<ConsumptionDto>>> future = promise->get_future();

    dataGatheringApi->addConsumptionHeartbeat(isvId, addConsumptionHeartbeat)
        .then([promise](pplx::task<vector<shared_ptr<ConsumptionDto>>> response) mutable
              {
                try {
                    promise->set_value(response.get());
                }
                catch (...) {
                    auto ex = current_exception();
                    promise->set_exception(ex);
                } });

    try
    {
        vector<shared_ptr<ConsumptionDto>> consumptions = future.get();
        for (auto consumption : consumptions)
        {
            cout << "addConsumptionHeartbeat() limitation id: " <<  consumption-> getLimitationId() << endl;

            auto transactionId = consumption->getTransactionId();

            // Check if the transaction ID is null or empty
            if (transactionId.empty())
            {
                cout << "                          consumption limit reached!" << endl;
            }
            else
            {
                cout << "                          transaction id: " << transactionId << endl;
                cout << "                          remaining: " << consumption->getRemaining() << endl;
                cout << "                          next reset date: " << consumption->getNextResetDateUtc().to_string() << endl;
            }
        }
    }
    catch (const ApiException &e)
    {
        // Handle API errors
        handle_api_exception(e);
        return -1;
    }
    catch (const exception &e)
    {
        cout << "addConsumptionHeartbeat() exception: " << e.what() << endl;
        return -1;
    }
    return 0;
}

const char* sessionStatusFileName = "sessionStatus.json";

/**
 * open_session:
 * 
 * Open a session
 * 
 * @return 0 on success or a negative value if an error occurs.
 */
int Helper::open_session()
{
    // Check licenseInfoDto
    if (licenseInfoDto == nullptr)
    {
        cout << "Error: No license info available." << endl;
        cout << "       Please activate the license first or send a license heartbeat." << endl;
        return -1;
    }

    // Build the request body
    shared_ptr<SessionRequestDto> sessionRequest = make_shared<SessionRequestDto>();
    sessionRequest->setLicenseId(licenseInfoDto->getLicenseKey());
    sessionRequest->setClientId(get_device_id());

    // Create a UUID as session ID
    boost::uuids::random_generator generator;
    boost::uuids::uuid new_uuid = generator();
    sessionRequest->setSessionId(to_string(new_uuid));

    // Create a promise and future
    auto promise = make_shared<std::promise<shared_ptr<SessionStatusDto>>>();
    future<shared_ptr<SessionStatusDto>> future = promise->get_future();

    provisioningApi->openSession(isvId, sessionRequest)
        .then([promise](pplx::task<shared_ptr<SessionStatusDto>> response) mutable
              {
                try {
                    promise->set_value(response.get());
                }
                catch (...) {
                    auto ex = current_exception();
                    promise->set_exception(ex);
                } });

    try
    {
        auto sessionStatusDto = future.get();
        cout << "Session valid unitl: " << sessionStatusDto->getSessionValidUntil().to_string() << endl;
        // Store in stack
        sessionIds.push(sessionRequest->getSessionId());
    }
    catch (const ApiException &e)
    {
        // Handle API errors
        handle_api_exception(e);
        return -1;
    }
    catch (const exception &e)
    {
        cout << "openSession() exception: " << e.what() << endl;
        return -1;
    }

    return 0;
}

/**
 * find_open_session:
 * 
 * Find an open session
 * 
 * @return 0 on success or a negative value if an error occurs.
 */
int Helper::find_open_session()
{
    shared_ptr<SessionRequestDto> sessionRequestDto = make_shared<SessionRequestDto>();
    shared_ptr<SessionStatusDto> sessionStatusDto = make_shared<SessionStatusDto>();

    if (0 <= apiClient->TryGetOpenSession(sessionRequestDto, sessionStatusDto))
    {
        // Check the 'sessionValidUntil' timestamp if the session is still valid
        if (utility::datetime::utc_now() <= sessionStatusDto->getSessionValidUntil())
        {
           cout << "Found open session; session ID: " << sessionRequestDto->getSessionId() << endl;
           cout << "                    client ID: " << sessionRequestDto->getClientId() << endl;
           cout << "                    session valid unitl: " << sessionStatusDto->getSessionValidUntil().to_string() << endl;
        }
        else
        {
            cout << "Error: Session is expired." << endl;
            cout << "       Please open a new session." << endl;
            return -1;
        }
    }
    else
    {
        cout << "Error: No session status available." << endl;
        cout << "       Please open a session first." << endl;
        return -1;
    }

    return 0;
}

/**
 * close_session:
 * 
 * Close a session
 * 
 * @return 0 on success or a negative value if an error occurs.
 */
int Helper::close_session()
{
    // Check licenseInfoDto
    if (licenseInfoDto == nullptr)
    {
        cout << "Error: No license info available." << endl;
        cout << "       Please activate the license first or send a license heartbeat." << endl;
        return -1;
    }

    // Check if there is an open session
    if (sessionIds.empty())
    {
        cout << "Error: No open session available." << endl;
        cout << "       Please open a session first." << endl;
        return -1;
    }

    // Build the request body
    shared_ptr<SessionRequestDto> sessionRequest = make_shared<SessionRequestDto>();
    sessionRequest->setLicenseId(licenseInfoDto->getLicenseKey());
    sessionRequest->setClientId(get_device_id());
    sessionRequest->setSessionId(sessionIds.top());

    // Create a promise and future
    auto promise = make_shared<std::promise<string>>();
    future<string> future = promise->get_future();

    provisioningApi->closeSession(isvId, sessionRequest)
        .then([promise](pplx::task<string> response)
              {
                try {
                    promise->set_value(response.get());
                }
                catch (...) {
                    auto ex = current_exception();
                    promise->set_exception(ex);
                } });

    try
    {
        cout << "closeSession() response: " << future.get() << endl;
        // Remove from stack
        sessionIds.pop();
    }
    catch (const ApiException &e)
    {
        // Handle API errors
        handle_api_exception(e);
        return -1;
    }
    catch (const exception &e)
    {
        cout << "closeSession() exception: " << e.what() << endl;
        return -1;
    }

    return 0;
}

/**
 * get_license_by_id:
 * 
 * Get a license by ID
 * 
 * @return 0 on success or a negative value if an error occurs.
 */
int Helper::get_license_by_id()
{
    shared_ptr<GetLicensesByLicenseKeyDto> getLicenses = make_shared<GetLicensesByLicenseKeyDto>();
    getLicenses->setLicenseKey("27180460-29df-4a5a-a0a1-78c85ab6cee0");
    getLicenses->setProductId(productId);

    provisioningApi->getLicensesByLicenseKeyAsync(isvId, getLicenses)
        .then([this](pplx::task<vector<shared_ptr<LicenseDto>>> licenses)
              {
					try {
						auto licenseDtos = licenses.get();

						for (auto licenseDto : licenseDtos)
						{
							Helper::print_license(licenseDto);
						}
					}
					catch (const exception& e) {
						cout << "getLicensesByLicenseKeyAsync() exception: " << e.what() << endl;
					} })
        .wait();

    return 0;
}

/**
 * verify_file:
 * @xml_file:           the signed XML file name.
 *
 * Verifies XML signature in #xml_file using public key from #key_file.
 *
 * Returns 0 on success or a negative value if an error occurs.
 */
int Helper::verify_file(const char* xml_file) {
    LicenseXmlValidator::LicenseXmlValidator validator;
    return validator.verify_file(xml_file, pemKey.c_str(), pemKey.length());
}

/**
 * get_os_name:
 * 
 * Get the operating system name
 * 
 * @return the operating system name or an empty string if an error occurs.
 */
string Helper::get_os_name()
{
    #if defined(_WIN32) || defined(_WIN64)
        return "Windows";
    #elif defined(__linux__)
        // Use the output of the command 'uname -sr' to get the Linux distribution name and version
        string command = "uname -sr";
        char buffer[128];
        FILE* pipe = popen(command.c_str(), "r");
        if (pipe == nullptr)
        {
            cout << "Error: popen() failed." << endl;
            return "";
        }
        string os_name = fgets(buffer, 128, pipe);
        // Trim ending line feed/carriage return
        os_name.erase(os_name.find_last_not_of("\n\r") + 1);
        return os_name;
    #elif defined(__APPLE__) || defined(__MACH__)
        return "macOS";
    #elif defined(__unix__)
        return "Unix";
    #else
        return "Unknown operating system";
    #endif
}

/**
 * get_device_id:
 * 
 * Get the device ID
 * 
 * @return the device ID or an empty string if an error occurs.
 * 
 * Note: The device ID is the HOSTNAME environment variable.
 */
string Helper::get_device_id()
{
    // Read HOSTNAME environment variable
    // (contains the container ID if running in a container)
    const char* hostname = getenv("HOSTNAME");
    if (hostname == nullptr)
    {
        cout << "Error: HOSTNAME environment variable not set." << endl;
        return "";
    }

    return hostname;
}

int Helper::handle_api_exception(const ApiException &e)
{
    // Handle API errors
    shared_ptr<istream> content = e.getContent();
    ErrorResultObjects errorResultObjects;
    string jsonStr((istreambuf_iterator<char>(*content)), istreambuf_iterator<char>());
    errorResultObjects.fromJson(web::json::value::parse(jsonStr));

    auto errorId = errorResultObjects.getId();
    cout << "API error ID: " << errorId << endl;
    cout << "API error message: " << errorResultObjects.getMessage() << endl;

    if (2006 == errorId)
    {
        cout << "You have to activate a license first before you can send a license heartbeat." << endl;
    }

    return 0;
}

int Helper::print_license(shared_ptr<LicenseDto> licenseDto)
{
    if (licenseDto != nullptr)
    {
        cout << "License key: " << to_utf8string(licenseDto->getId()) << endl;
        cout << "Legacy license key: " << to_utf8string(licenseDto->getLegacyLicenseKey()) << endl;
        cout << "License name: " << to_utf8string(licenseDto->getName()) << endl;
        cout << "Product name: " << to_utf8string(licenseDto->getProductId()) << endl;
        cout << "License valid: " << licenseDto->isIsValid() << endl;
        cout << "Expiration date: " << to_utf8string(licenseDto->getExpirationDateUtc().to_string()) << endl;
        cout << "Customer company name: " << to_utf8string(licenseDto->getCustomer()->getCompanyName()) << endl;
        cout << "Customer number: " << to_utf8string(licenseDto->getCustomer()->getCustomerNumber()) << endl;

        auto features = licenseDto->getLicenseFeatures();
        for (auto feature : features)
        {
            cout << " - Feature name: " << to_utf8string(feature->getFeatureName()) << endl;
            cout << "   Feature description: " << to_utf8string(feature->getFeatureDescription()) << endl;
        }

        auto limitations = licenseDto->getLicenseLimitations();
        for (auto limitation : limitations)
        {
            cout << " - Limitation name: " << to_utf8string(limitation->getLimitationName()) << endl;
            cout << "   Limitation description: " << to_utf8string(limitation->getLimitationDescription()) << endl;
            cout << "   Limitation value: " << limitation->getLimit() << endl;
        }

        auto constrainedVariables = licenseDto->getLicenseConstrainedVariables();
        for (auto constrainedVariable : constrainedVariables)
        {
            cout << " - Constrained variable name: " << to_utf8string(constrainedVariable->getVariableName()) << endl;
            cout << "   Constrained variable description: " << to_utf8string(constrainedVariable->getVariableDescription()) << endl;
            cout << "   Constrained variable value: ";            
            for (auto value : constrainedVariable->getValues())
            {
                cout << to_utf8string(value);
            }
            cout << endl;
        }

        auto variables = licenseDto->getLicenseVariables();
        for (auto variable : variables)
        {
            cout << " - Variable name: " << to_utf8string(variable->getVariableName()) << endl;
            cout << "   Variable description: " << to_utf8string(variable->getVariableDescription()) << endl;
            cout << "   Variable value: " << to_utf8string(variable->getValue()) << endl;
        }
        return 0;
    }

    return -1;
}

int Helper::print_license(shared_ptr<LicenseInfoDto> licenseInfoDto)
{
    if (licenseInfoDto != nullptr)
    {
        cout << "License key: " << to_utf8string(licenseInfoDto->getLicenseKey()) << endl;
        cout << "Legacy license key: " << to_utf8string(licenseInfoDto->getLegacyLicenseKey()) << endl;
        cout << "Token key: " << to_utf8string(licenseInfoDto->getTokenKey()) << endl;
        cout << "License name: " << to_utf8string(licenseInfoDto->getLicenseName()) << endl;
        cout << "Product name: " << to_utf8string(licenseInfoDto->getProductName()) << endl;
        cout << "Template name: " << to_utf8string(licenseInfoDto->getTemplateName()) << endl;
        cout << "License valid: " << licenseInfoDto->isIsLicenseValid() << endl;
        cout << "Expiration date: " << to_utf8string(licenseInfoDto->getExpirationDateUtc().to_string()) << endl;

        auto customer = licenseInfoDto->getCustomer();
        cout << "Customer company name: " << to_utf8string(customer->getCompanyName()) << endl;
        cout << "Customer number: " << to_utf8string(customer->getCustomerNumber()) << endl;

        cout << "Session period: " << licenseInfoDto->getSessionPeriod() << endl;
        cout << "Heartbeat period: " << licenseInfoDto->getHeartbeatPeriod() << endl;
        cout << "Freeride: " << licenseInfoDto->getFreeride() << endl;

        auto features = licenseInfoDto->getFeatures();
        for (auto feature : features)
        {
            cout << " - Feature name: " << to_utf8string(feature->getName()) << endl;
            cout << "   Feature description: " << to_utf8string(feature->getDescription()) << endl;
        }

        auto limitations = licenseInfoDto->getLimitations();
        for (auto limitation : limitations)
        {
            cout << " - Limitation name: " << to_utf8string(limitation->getName()) << endl;
            cout << "   Limitation description: " << to_utf8string(limitation->getDescription()) << endl;
            cout << "   Limitation value: " << limitation->getValue() << endl;
        }

        auto constrainedVariables = licenseInfoDto->getConstrainedVariables();
        for (auto constrainedVariable : constrainedVariables)
        {
            cout << " - Constrained variable name: " << to_utf8string(constrainedVariable->getName()) << endl;
            cout << "   Constrained variable description: " << to_utf8string(constrainedVariable->getDescription()) << endl;
            cout << "   Constrained variable value: ";            
            for (auto value : constrainedVariable->getValue())
            {
                cout << to_utf8string(value);
            }
            cout << endl;
        }

        auto variables = licenseInfoDto->getVariables();
        for (auto variable : variables)
        {
            cout << " - Variable name: " << to_utf8string(variable->getName()) << endl;
            cout << "   Variable description: " << to_utf8string(variable->getDescription()) << endl;
            cout << "   Variable value: " << to_utf8string(variable->getValue()) << endl;
        }

        return 0;
    }

    return -1;
}
