/**
 * SLASCONE API
 * Please visit our official [Documentation](https://support.slascone.com/hc/en-us/sections/360004685737-API) and/or our [GitHub repository](https://github.com/slascone/) and/or our [NuGet package](https://www.nuget.org/packages/Slascone.Client/). Always use Version 2 of this API (Version 1.3 is deprecated).
 *
 * The version of the OpenAPI document: v2
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 7.11.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */



#include "SlasconeOpenApiClient/model/DeviceHeartbeatDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



DeviceHeartbeatDto::DeviceHeartbeatDto()
{
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_Software_version = utility::conversions::to_string_t("");
    m_Software_versionIsSet = false;
    m_Operating_system = utility::conversions::to_string_t("");
    m_Operating_systemIsSet = false;
    m_Ip_address = utility::conversions::to_string_t("");
    m_Ip_addressIsSet = false;
    m_Client_id = utility::conversions::to_string_t("");
    m_Client_idIsSet = false;
    m_Country = utility::conversions::to_string_t("");
    m_CountryIsSet = false;
    m_City = utility::conversions::to_string_t("");
    m_CityIsSet = false;
    m_Zip = utility::conversions::to_string_t("");
    m_ZipIsSet = false;
    m_Latitude = utility::conversions::to_string_t("");
    m_LatitudeIsSet = false;
    m_Longitude = utility::conversions::to_string_t("");
    m_LongitudeIsSet = false;
    m_Created_date_utc = utility::datetime();
    m_Created_date_utcIsSet = false;
    m_Device_license_assignment_id = utility::conversions::to_string_t("");
    m_Device_license_assignment_idIsSet = false;
    m_Device_license_id = utility::conversions::to_string_t("");
    m_Device_license_idIsSet = false;
    m_Customer_name = utility::conversions::to_string_t("");
    m_Customer_nameIsSet = false;
    m_Heartbeat_type_id = utility::conversions::to_string_t("");
    m_Heartbeat_type_idIsSet = false;
    m_Heartbeat_typeIsSet = false;
    m_Group_id = utility::conversions::to_string_t("");
    m_Group_idIsSet = false;
    m_Value = 0;
    m_ValueIsSet = false;
}

DeviceHeartbeatDto::~DeviceHeartbeatDto()
{
}

void DeviceHeartbeatDto::validate()
{
    // TODO: implement validation
}

web::json::value DeviceHeartbeatDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t(U("id"))] = ModelBase::toJson(m_Id);
    }
    if(m_Software_versionIsSet)
    {
        val[utility::conversions::to_string_t(U("software_version"))] = ModelBase::toJson(m_Software_version);
    }
    if(m_Operating_systemIsSet)
    {
        val[utility::conversions::to_string_t(U("operating_system"))] = ModelBase::toJson(m_Operating_system);
    }
    if(m_Ip_addressIsSet)
    {
        val[utility::conversions::to_string_t(U("ip_address"))] = ModelBase::toJson(m_Ip_address);
    }
    if(m_Client_idIsSet)
    {
        val[utility::conversions::to_string_t(U("client_id"))] = ModelBase::toJson(m_Client_id);
    }
    if(m_CountryIsSet)
    {
        val[utility::conversions::to_string_t(U("country"))] = ModelBase::toJson(m_Country);
    }
    if(m_CityIsSet)
    {
        val[utility::conversions::to_string_t(U("city"))] = ModelBase::toJson(m_City);
    }
    if(m_ZipIsSet)
    {
        val[utility::conversions::to_string_t(U("zip"))] = ModelBase::toJson(m_Zip);
    }
    if(m_LatitudeIsSet)
    {
        val[utility::conversions::to_string_t(U("latitude"))] = ModelBase::toJson(m_Latitude);
    }
    if(m_LongitudeIsSet)
    {
        val[utility::conversions::to_string_t(U("longitude"))] = ModelBase::toJson(m_Longitude);
    }
    if(m_Created_date_utcIsSet)
    {
        val[utility::conversions::to_string_t(U("created_date_utc"))] = ModelBase::toJson(m_Created_date_utc);
    }
    if(m_Device_license_assignment_idIsSet)
    {
        val[utility::conversions::to_string_t(U("device_license_assignment_id"))] = ModelBase::toJson(m_Device_license_assignment_id);
    }
    if(m_Device_license_idIsSet)
    {
        val[utility::conversions::to_string_t(U("device_license_id"))] = ModelBase::toJson(m_Device_license_id);
    }
    if(m_Customer_nameIsSet)
    {
        val[utility::conversions::to_string_t(U("customer_name"))] = ModelBase::toJson(m_Customer_name);
    }
    if(m_Heartbeat_type_idIsSet)
    {
        val[utility::conversions::to_string_t(U("heartbeat_type_id"))] = ModelBase::toJson(m_Heartbeat_type_id);
    }
    if(m_Heartbeat_typeIsSet)
    {
        val[utility::conversions::to_string_t(U("heartbeat_type"))] = ModelBase::toJson(m_Heartbeat_type);
    }
    if(m_Group_idIsSet)
    {
        val[utility::conversions::to_string_t(U("group_id"))] = ModelBase::toJson(m_Group_id);
    }
    if(m_ValueIsSet)
    {
        val[utility::conversions::to_string_t(U("value"))] = ModelBase::toJson(m_Value);
    }

    return val;
}

bool DeviceHeartbeatDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setId);
            setId(refVal_setId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("software_version"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("software_version")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setSoftwareVersion;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSoftwareVersion);
            setSoftwareVersion(refVal_setSoftwareVersion);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("operating_system"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("operating_system")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setOperatingSystem;
            ok &= ModelBase::fromJson(fieldValue, refVal_setOperatingSystem);
            setOperatingSystem(refVal_setOperatingSystem);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("ip_address"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("ip_address")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setIpAddress;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIpAddress);
            setIpAddress(refVal_setIpAddress);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("client_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("client_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setClientId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setClientId);
            setClientId(refVal_setClientId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("country"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("country")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setCountry;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCountry);
            setCountry(refVal_setCountry);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("city"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("city")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setCity;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCity);
            setCity(refVal_setCity);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("zip"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("zip")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setZip;
            ok &= ModelBase::fromJson(fieldValue, refVal_setZip);
            setZip(refVal_setZip);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("latitude"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("latitude")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLatitude;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLatitude);
            setLatitude(refVal_setLatitude);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("longitude"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("longitude")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLongitude;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLongitude);
            setLongitude(refVal_setLongitude);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("created_date_utc"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("created_date_utc")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setCreatedDateUtc;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCreatedDateUtc);
            setCreatedDateUtc(refVal_setCreatedDateUtc);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("device_license_assignment_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("device_license_assignment_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setDeviceLicenseAssignmentId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setDeviceLicenseAssignmentId);
            setDeviceLicenseAssignmentId(refVal_setDeviceLicenseAssignmentId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("device_license_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("device_license_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setDeviceLicenseId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setDeviceLicenseId);
            setDeviceLicenseId(refVal_setDeviceLicenseId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("customer_name"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("customer_name")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setCustomerName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCustomerName);
            setCustomerName(refVal_setCustomerName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("heartbeat_type_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("heartbeat_type_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setHeartbeatTypeId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setHeartbeatTypeId);
            setHeartbeatTypeId(refVal_setHeartbeatTypeId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("heartbeat_type"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("heartbeat_type")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<HeartbeatTypeDto> refVal_setHeartbeatType;
            ok &= ModelBase::fromJson(fieldValue, refVal_setHeartbeatType);
            setHeartbeatType(refVal_setHeartbeatType);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("group_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("group_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setGroupId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setGroupId);
            setGroupId(refVal_setGroupId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("value"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("value")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setValue;
            ok &= ModelBase::fromJson(fieldValue, refVal_setValue);
            setValue(refVal_setValue);
        }
    }
    return ok;
}

void DeviceHeartbeatDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("id")), m_Id));
    }
    if(m_Software_versionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("software_version")), m_Software_version));
    }
    if(m_Operating_systemIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("operating_system")), m_Operating_system));
    }
    if(m_Ip_addressIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("ip_address")), m_Ip_address));
    }
    if(m_Client_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("client_id")), m_Client_id));
    }
    if(m_CountryIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("country")), m_Country));
    }
    if(m_CityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("city")), m_City));
    }
    if(m_ZipIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("zip")), m_Zip));
    }
    if(m_LatitudeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("latitude")), m_Latitude));
    }
    if(m_LongitudeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("longitude")), m_Longitude));
    }
    if(m_Created_date_utcIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("created_date_utc")), m_Created_date_utc));
    }
    if(m_Device_license_assignment_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("device_license_assignment_id")), m_Device_license_assignment_id));
    }
    if(m_Device_license_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("device_license_id")), m_Device_license_id));
    }
    if(m_Customer_nameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("customer_name")), m_Customer_name));
    }
    if(m_Heartbeat_type_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("heartbeat_type_id")), m_Heartbeat_type_id));
    }
    if(m_Heartbeat_typeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("heartbeat_type")), m_Heartbeat_type));
    }
    if(m_Group_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("group_id")), m_Group_id));
    }
    if(m_ValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("value")), m_Value));
    }
}

bool DeviceHeartbeatDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("id"))))
    {
        utility::string_t refVal_setId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("id"))), refVal_setId );
        setId(refVal_setId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("software_version"))))
    {
        utility::string_t refVal_setSoftwareVersion;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("software_version"))), refVal_setSoftwareVersion );
        setSoftwareVersion(refVal_setSoftwareVersion);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("operating_system"))))
    {
        utility::string_t refVal_setOperatingSystem;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("operating_system"))), refVal_setOperatingSystem );
        setOperatingSystem(refVal_setOperatingSystem);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("ip_address"))))
    {
        utility::string_t refVal_setIpAddress;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("ip_address"))), refVal_setIpAddress );
        setIpAddress(refVal_setIpAddress);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("client_id"))))
    {
        utility::string_t refVal_setClientId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("client_id"))), refVal_setClientId );
        setClientId(refVal_setClientId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("country"))))
    {
        utility::string_t refVal_setCountry;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("country"))), refVal_setCountry );
        setCountry(refVal_setCountry);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("city"))))
    {
        utility::string_t refVal_setCity;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("city"))), refVal_setCity );
        setCity(refVal_setCity);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("zip"))))
    {
        utility::string_t refVal_setZip;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("zip"))), refVal_setZip );
        setZip(refVal_setZip);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("latitude"))))
    {
        utility::string_t refVal_setLatitude;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("latitude"))), refVal_setLatitude );
        setLatitude(refVal_setLatitude);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("longitude"))))
    {
        utility::string_t refVal_setLongitude;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("longitude"))), refVal_setLongitude );
        setLongitude(refVal_setLongitude);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("created_date_utc"))))
    {
        utility::datetime refVal_setCreatedDateUtc;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("created_date_utc"))), refVal_setCreatedDateUtc );
        setCreatedDateUtc(refVal_setCreatedDateUtc);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("device_license_assignment_id"))))
    {
        utility::string_t refVal_setDeviceLicenseAssignmentId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("device_license_assignment_id"))), refVal_setDeviceLicenseAssignmentId );
        setDeviceLicenseAssignmentId(refVal_setDeviceLicenseAssignmentId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("device_license_id"))))
    {
        utility::string_t refVal_setDeviceLicenseId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("device_license_id"))), refVal_setDeviceLicenseId );
        setDeviceLicenseId(refVal_setDeviceLicenseId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("customer_name"))))
    {
        utility::string_t refVal_setCustomerName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("customer_name"))), refVal_setCustomerName );
        setCustomerName(refVal_setCustomerName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("heartbeat_type_id"))))
    {
        utility::string_t refVal_setHeartbeatTypeId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("heartbeat_type_id"))), refVal_setHeartbeatTypeId );
        setHeartbeatTypeId(refVal_setHeartbeatTypeId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("heartbeat_type"))))
    {
        std::shared_ptr<HeartbeatTypeDto> refVal_setHeartbeatType;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("heartbeat_type"))), refVal_setHeartbeatType );
        setHeartbeatType(refVal_setHeartbeatType);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("group_id"))))
    {
        utility::string_t refVal_setGroupId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("group_id"))), refVal_setGroupId );
        setGroupId(refVal_setGroupId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("value"))))
    {
        int32_t refVal_setValue;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("value"))), refVal_setValue );
        setValue(refVal_setValue);
    }
    return ok;
}

utility::string_t DeviceHeartbeatDto::getId() const
{
    return m_Id;
}

void DeviceHeartbeatDto::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool DeviceHeartbeatDto::idIsSet() const
{
    return m_IdIsSet;
}

void DeviceHeartbeatDto::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getSoftwareVersion() const
{
    return m_Software_version;
}

void DeviceHeartbeatDto::setSoftwareVersion(const utility::string_t& value)
{
    m_Software_version = value;
    m_Software_versionIsSet = true;
}

bool DeviceHeartbeatDto::softwareVersionIsSet() const
{
    return m_Software_versionIsSet;
}

void DeviceHeartbeatDto::unsetSoftware_version()
{
    m_Software_versionIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getOperatingSystem() const
{
    return m_Operating_system;
}

void DeviceHeartbeatDto::setOperatingSystem(const utility::string_t& value)
{
    m_Operating_system = value;
    m_Operating_systemIsSet = true;
}

bool DeviceHeartbeatDto::operatingSystemIsSet() const
{
    return m_Operating_systemIsSet;
}

void DeviceHeartbeatDto::unsetOperating_system()
{
    m_Operating_systemIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getIpAddress() const
{
    return m_Ip_address;
}

void DeviceHeartbeatDto::setIpAddress(const utility::string_t& value)
{
    m_Ip_address = value;
    m_Ip_addressIsSet = true;
}

bool DeviceHeartbeatDto::ipAddressIsSet() const
{
    return m_Ip_addressIsSet;
}

void DeviceHeartbeatDto::unsetIp_address()
{
    m_Ip_addressIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getClientId() const
{
    return m_Client_id;
}

void DeviceHeartbeatDto::setClientId(const utility::string_t& value)
{
    m_Client_id = value;
    m_Client_idIsSet = true;
}

bool DeviceHeartbeatDto::clientIdIsSet() const
{
    return m_Client_idIsSet;
}

void DeviceHeartbeatDto::unsetClient_id()
{
    m_Client_idIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getCountry() const
{
    return m_Country;
}

void DeviceHeartbeatDto::setCountry(const utility::string_t& value)
{
    m_Country = value;
    m_CountryIsSet = true;
}

bool DeviceHeartbeatDto::countryIsSet() const
{
    return m_CountryIsSet;
}

void DeviceHeartbeatDto::unsetCountry()
{
    m_CountryIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getCity() const
{
    return m_City;
}

void DeviceHeartbeatDto::setCity(const utility::string_t& value)
{
    m_City = value;
    m_CityIsSet = true;
}

bool DeviceHeartbeatDto::cityIsSet() const
{
    return m_CityIsSet;
}

void DeviceHeartbeatDto::unsetCity()
{
    m_CityIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getZip() const
{
    return m_Zip;
}

void DeviceHeartbeatDto::setZip(const utility::string_t& value)
{
    m_Zip = value;
    m_ZipIsSet = true;
}

bool DeviceHeartbeatDto::zipIsSet() const
{
    return m_ZipIsSet;
}

void DeviceHeartbeatDto::unsetZip()
{
    m_ZipIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getLatitude() const
{
    return m_Latitude;
}

void DeviceHeartbeatDto::setLatitude(const utility::string_t& value)
{
    m_Latitude = value;
    m_LatitudeIsSet = true;
}

bool DeviceHeartbeatDto::latitudeIsSet() const
{
    return m_LatitudeIsSet;
}

void DeviceHeartbeatDto::unsetLatitude()
{
    m_LatitudeIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getLongitude() const
{
    return m_Longitude;
}

void DeviceHeartbeatDto::setLongitude(const utility::string_t& value)
{
    m_Longitude = value;
    m_LongitudeIsSet = true;
}

bool DeviceHeartbeatDto::longitudeIsSet() const
{
    return m_LongitudeIsSet;
}

void DeviceHeartbeatDto::unsetLongitude()
{
    m_LongitudeIsSet = false;
}
utility::datetime DeviceHeartbeatDto::getCreatedDateUtc() const
{
    return m_Created_date_utc;
}

void DeviceHeartbeatDto::setCreatedDateUtc(const utility::datetime& value)
{
    m_Created_date_utc = value;
    m_Created_date_utcIsSet = true;
}

bool DeviceHeartbeatDto::createdDateUtcIsSet() const
{
    return m_Created_date_utcIsSet;
}

void DeviceHeartbeatDto::unsetCreated_date_utc()
{
    m_Created_date_utcIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getDeviceLicenseAssignmentId() const
{
    return m_Device_license_assignment_id;
}

void DeviceHeartbeatDto::setDeviceLicenseAssignmentId(const utility::string_t& value)
{
    m_Device_license_assignment_id = value;
    m_Device_license_assignment_idIsSet = true;
}

bool DeviceHeartbeatDto::deviceLicenseAssignmentIdIsSet() const
{
    return m_Device_license_assignment_idIsSet;
}

void DeviceHeartbeatDto::unsetDevice_license_assignment_id()
{
    m_Device_license_assignment_idIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getDeviceLicenseId() const
{
    return m_Device_license_id;
}

void DeviceHeartbeatDto::setDeviceLicenseId(const utility::string_t& value)
{
    m_Device_license_id = value;
    m_Device_license_idIsSet = true;
}

bool DeviceHeartbeatDto::deviceLicenseIdIsSet() const
{
    return m_Device_license_idIsSet;
}

void DeviceHeartbeatDto::unsetDevice_license_id()
{
    m_Device_license_idIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getCustomerName() const
{
    return m_Customer_name;
}

void DeviceHeartbeatDto::setCustomerName(const utility::string_t& value)
{
    m_Customer_name = value;
    m_Customer_nameIsSet = true;
}

bool DeviceHeartbeatDto::customerNameIsSet() const
{
    return m_Customer_nameIsSet;
}

void DeviceHeartbeatDto::unsetCustomer_name()
{
    m_Customer_nameIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getHeartbeatTypeId() const
{
    return m_Heartbeat_type_id;
}

void DeviceHeartbeatDto::setHeartbeatTypeId(const utility::string_t& value)
{
    m_Heartbeat_type_id = value;
    m_Heartbeat_type_idIsSet = true;
}

bool DeviceHeartbeatDto::heartbeatTypeIdIsSet() const
{
    return m_Heartbeat_type_idIsSet;
}

void DeviceHeartbeatDto::unsetHeartbeat_type_id()
{
    m_Heartbeat_type_idIsSet = false;
}
std::shared_ptr<HeartbeatTypeDto> DeviceHeartbeatDto::getHeartbeatType() const
{
    return m_Heartbeat_type;
}

void DeviceHeartbeatDto::setHeartbeatType(const std::shared_ptr<HeartbeatTypeDto>& value)
{
    m_Heartbeat_type = value;
    m_Heartbeat_typeIsSet = true;
}

bool DeviceHeartbeatDto::heartbeatTypeIsSet() const
{
    return m_Heartbeat_typeIsSet;
}

void DeviceHeartbeatDto::unsetHeartbeat_type()
{
    m_Heartbeat_typeIsSet = false;
}
utility::string_t DeviceHeartbeatDto::getGroupId() const
{
    return m_Group_id;
}

void DeviceHeartbeatDto::setGroupId(const utility::string_t& value)
{
    m_Group_id = value;
    m_Group_idIsSet = true;
}

bool DeviceHeartbeatDto::groupIdIsSet() const
{
    return m_Group_idIsSet;
}

void DeviceHeartbeatDto::unsetGroup_id()
{
    m_Group_idIsSet = false;
}
int32_t DeviceHeartbeatDto::getValue() const
{
    return m_Value;
}

void DeviceHeartbeatDto::setValue(int32_t value)
{
    m_Value = value;
    m_ValueIsSet = true;
}

bool DeviceHeartbeatDto::valueIsSet() const
{
    return m_ValueIsSet;
}

void DeviceHeartbeatDto::unsetValue()
{
    m_ValueIsSet = false;
}
}
}
}
}


