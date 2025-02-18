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



#include "SlasconeOpenApiClient/model/ConsumptionHeartbeatDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



ConsumptionHeartbeatDto::ConsumptionHeartbeatDto()
{
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_Value = 0.0;
    m_ValueIsSet = false;
    m_Remaining = 0.0;
    m_RemainingIsSet = false;
    m_Assignment_id = utility::conversions::to_string_t("");
    m_Assignment_idIsSet = false;
    m_Client_id = utility::conversions::to_string_t("");
    m_Client_idIsSet = false;
    m_License_id = utility::conversions::to_string_t("");
    m_License_idIsSet = false;
    m_Limitation_id = utility::conversions::to_string_t("");
    m_Limitation_idIsSet = false;
    m_LimitationIsSet = false;
    m_User_id = utility::conversions::to_string_t("");
    m_User_idIsSet = false;
    m_License_userIsSet = false;
    m_Created_date_utc = utility::datetime();
    m_Created_date_utcIsSet = false;
}

ConsumptionHeartbeatDto::~ConsumptionHeartbeatDto()
{
}

void ConsumptionHeartbeatDto::validate()
{
    // TODO: implement validation
}

web::json::value ConsumptionHeartbeatDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t(U("id"))] = ModelBase::toJson(m_Id);
    }
    if(m_ValueIsSet)
    {
        val[utility::conversions::to_string_t(U("value"))] = ModelBase::toJson(m_Value);
    }
    if(m_RemainingIsSet)
    {
        val[utility::conversions::to_string_t(U("remaining"))] = ModelBase::toJson(m_Remaining);
    }
    if(m_Assignment_idIsSet)
    {
        val[utility::conversions::to_string_t(U("assignment_id"))] = ModelBase::toJson(m_Assignment_id);
    }
    if(m_Client_idIsSet)
    {
        val[utility::conversions::to_string_t(U("client_id"))] = ModelBase::toJson(m_Client_id);
    }
    if(m_License_idIsSet)
    {
        val[utility::conversions::to_string_t(U("license_id"))] = ModelBase::toJson(m_License_id);
    }
    if(m_Limitation_idIsSet)
    {
        val[utility::conversions::to_string_t(U("limitation_id"))] = ModelBase::toJson(m_Limitation_id);
    }
    if(m_LimitationIsSet)
    {
        val[utility::conversions::to_string_t(U("limitation"))] = ModelBase::toJson(m_Limitation);
    }
    if(m_User_idIsSet)
    {
        val[utility::conversions::to_string_t(U("user_id"))] = ModelBase::toJson(m_User_id);
    }
    if(m_License_userIsSet)
    {
        val[utility::conversions::to_string_t(U("license_user"))] = ModelBase::toJson(m_License_user);
    }
    if(m_Created_date_utcIsSet)
    {
        val[utility::conversions::to_string_t(U("created_date_utc"))] = ModelBase::toJson(m_Created_date_utc);
    }

    return val;
}

bool ConsumptionHeartbeatDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("value"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("value")));
        if(!fieldValue.is_null())
        {
            double refVal_setValue;
            ok &= ModelBase::fromJson(fieldValue, refVal_setValue);
            setValue(refVal_setValue);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("remaining"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("remaining")));
        if(!fieldValue.is_null())
        {
            double refVal_setRemaining;
            ok &= ModelBase::fromJson(fieldValue, refVal_setRemaining);
            setRemaining(refVal_setRemaining);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("assignment_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("assignment_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setAssignmentId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setAssignmentId);
            setAssignmentId(refVal_setAssignmentId);
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
    if(val.has_field(utility::conversions::to_string_t(U("license_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("license_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLicenseId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLicenseId);
            setLicenseId(refVal_setLicenseId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("limitation_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("limitation_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLimitationId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLimitationId);
            setLimitationId(refVal_setLimitationId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("limitation"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("limitation")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<LimitationDto> refVal_setLimitation;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLimitation);
            setLimitation(refVal_setLimitation);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("user_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("user_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setUserId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUserId);
            setUserId(refVal_setUserId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("license_user"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("license_user")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<LicenseUserDto> refVal_setLicenseUser;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLicenseUser);
            setLicenseUser(refVal_setLicenseUser);
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
    return ok;
}

void ConsumptionHeartbeatDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_ValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("value")), m_Value));
    }
    if(m_RemainingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("remaining")), m_Remaining));
    }
    if(m_Assignment_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("assignment_id")), m_Assignment_id));
    }
    if(m_Client_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("client_id")), m_Client_id));
    }
    if(m_License_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("license_id")), m_License_id));
    }
    if(m_Limitation_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("limitation_id")), m_Limitation_id));
    }
    if(m_LimitationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("limitation")), m_Limitation));
    }
    if(m_User_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("user_id")), m_User_id));
    }
    if(m_License_userIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("license_user")), m_License_user));
    }
    if(m_Created_date_utcIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("created_date_utc")), m_Created_date_utc));
    }
}

bool ConsumptionHeartbeatDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("value"))))
    {
        double refVal_setValue;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("value"))), refVal_setValue );
        setValue(refVal_setValue);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("remaining"))))
    {
        double refVal_setRemaining;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("remaining"))), refVal_setRemaining );
        setRemaining(refVal_setRemaining);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("assignment_id"))))
    {
        utility::string_t refVal_setAssignmentId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("assignment_id"))), refVal_setAssignmentId );
        setAssignmentId(refVal_setAssignmentId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("client_id"))))
    {
        utility::string_t refVal_setClientId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("client_id"))), refVal_setClientId );
        setClientId(refVal_setClientId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("license_id"))))
    {
        utility::string_t refVal_setLicenseId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("license_id"))), refVal_setLicenseId );
        setLicenseId(refVal_setLicenseId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("limitation_id"))))
    {
        utility::string_t refVal_setLimitationId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("limitation_id"))), refVal_setLimitationId );
        setLimitationId(refVal_setLimitationId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("limitation"))))
    {
        std::shared_ptr<LimitationDto> refVal_setLimitation;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("limitation"))), refVal_setLimitation );
        setLimitation(refVal_setLimitation);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("user_id"))))
    {
        utility::string_t refVal_setUserId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("user_id"))), refVal_setUserId );
        setUserId(refVal_setUserId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("license_user"))))
    {
        std::shared_ptr<LicenseUserDto> refVal_setLicenseUser;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("license_user"))), refVal_setLicenseUser );
        setLicenseUser(refVal_setLicenseUser);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("created_date_utc"))))
    {
        utility::datetime refVal_setCreatedDateUtc;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("created_date_utc"))), refVal_setCreatedDateUtc );
        setCreatedDateUtc(refVal_setCreatedDateUtc);
    }
    return ok;
}

utility::string_t ConsumptionHeartbeatDto::getId() const
{
    return m_Id;
}

void ConsumptionHeartbeatDto::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool ConsumptionHeartbeatDto::idIsSet() const
{
    return m_IdIsSet;
}

void ConsumptionHeartbeatDto::unsetId()
{
    m_IdIsSet = false;
}
double ConsumptionHeartbeatDto::getValue() const
{
    return m_Value;
}

void ConsumptionHeartbeatDto::setValue(double value)
{
    m_Value = value;
    m_ValueIsSet = true;
}

bool ConsumptionHeartbeatDto::valueIsSet() const
{
    return m_ValueIsSet;
}

void ConsumptionHeartbeatDto::unsetValue()
{
    m_ValueIsSet = false;
}
double ConsumptionHeartbeatDto::getRemaining() const
{
    return m_Remaining;
}

void ConsumptionHeartbeatDto::setRemaining(double value)
{
    m_Remaining = value;
    m_RemainingIsSet = true;
}

bool ConsumptionHeartbeatDto::remainingIsSet() const
{
    return m_RemainingIsSet;
}

void ConsumptionHeartbeatDto::unsetRemaining()
{
    m_RemainingIsSet = false;
}
utility::string_t ConsumptionHeartbeatDto::getAssignmentId() const
{
    return m_Assignment_id;
}

void ConsumptionHeartbeatDto::setAssignmentId(const utility::string_t& value)
{
    m_Assignment_id = value;
    m_Assignment_idIsSet = true;
}

bool ConsumptionHeartbeatDto::assignmentIdIsSet() const
{
    return m_Assignment_idIsSet;
}

void ConsumptionHeartbeatDto::unsetAssignment_id()
{
    m_Assignment_idIsSet = false;
}
utility::string_t ConsumptionHeartbeatDto::getClientId() const
{
    return m_Client_id;
}

void ConsumptionHeartbeatDto::setClientId(const utility::string_t& value)
{
    m_Client_id = value;
    m_Client_idIsSet = true;
}

bool ConsumptionHeartbeatDto::clientIdIsSet() const
{
    return m_Client_idIsSet;
}

void ConsumptionHeartbeatDto::unsetClient_id()
{
    m_Client_idIsSet = false;
}
utility::string_t ConsumptionHeartbeatDto::getLicenseId() const
{
    return m_License_id;
}

void ConsumptionHeartbeatDto::setLicenseId(const utility::string_t& value)
{
    m_License_id = value;
    m_License_idIsSet = true;
}

bool ConsumptionHeartbeatDto::licenseIdIsSet() const
{
    return m_License_idIsSet;
}

void ConsumptionHeartbeatDto::unsetLicense_id()
{
    m_License_idIsSet = false;
}
utility::string_t ConsumptionHeartbeatDto::getLimitationId() const
{
    return m_Limitation_id;
}

void ConsumptionHeartbeatDto::setLimitationId(const utility::string_t& value)
{
    m_Limitation_id = value;
    m_Limitation_idIsSet = true;
}

bool ConsumptionHeartbeatDto::limitationIdIsSet() const
{
    return m_Limitation_idIsSet;
}

void ConsumptionHeartbeatDto::unsetLimitation_id()
{
    m_Limitation_idIsSet = false;
}
std::shared_ptr<LimitationDto> ConsumptionHeartbeatDto::getLimitation() const
{
    return m_Limitation;
}

void ConsumptionHeartbeatDto::setLimitation(const std::shared_ptr<LimitationDto>& value)
{
    m_Limitation = value;
    m_LimitationIsSet = true;
}

bool ConsumptionHeartbeatDto::limitationIsSet() const
{
    return m_LimitationIsSet;
}

void ConsumptionHeartbeatDto::unsetLimitation()
{
    m_LimitationIsSet = false;
}
utility::string_t ConsumptionHeartbeatDto::getUserId() const
{
    return m_User_id;
}

void ConsumptionHeartbeatDto::setUserId(const utility::string_t& value)
{
    m_User_id = value;
    m_User_idIsSet = true;
}

bool ConsumptionHeartbeatDto::userIdIsSet() const
{
    return m_User_idIsSet;
}

void ConsumptionHeartbeatDto::unsetUser_id()
{
    m_User_idIsSet = false;
}
std::shared_ptr<LicenseUserDto> ConsumptionHeartbeatDto::getLicenseUser() const
{
    return m_License_user;
}

void ConsumptionHeartbeatDto::setLicenseUser(const std::shared_ptr<LicenseUserDto>& value)
{
    m_License_user = value;
    m_License_userIsSet = true;
}

bool ConsumptionHeartbeatDto::licenseUserIsSet() const
{
    return m_License_userIsSet;
}

void ConsumptionHeartbeatDto::unsetLicense_user()
{
    m_License_userIsSet = false;
}
utility::datetime ConsumptionHeartbeatDto::getCreatedDateUtc() const
{
    return m_Created_date_utc;
}

void ConsumptionHeartbeatDto::setCreatedDateUtc(const utility::datetime& value)
{
    m_Created_date_utc = value;
    m_Created_date_utcIsSet = true;
}

bool ConsumptionHeartbeatDto::createdDateUtcIsSet() const
{
    return m_Created_date_utcIsSet;
}

void ConsumptionHeartbeatDto::unsetCreated_date_utc()
{
    m_Created_date_utcIsSet = false;
}
}
}
}
}


