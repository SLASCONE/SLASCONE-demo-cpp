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



#include "SlasconeOpenApiClient/model/DeviceAnalyticalHeartbeatDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



DeviceAnalyticalHeartbeatDto::DeviceAnalyticalHeartbeatDto()
{
    m_License_assignment_id = utility::conversions::to_string_t("");
    m_License_assignment_idIsSet = false;
    m_Analytical_field_id = utility::conversions::to_string_t("");
    m_Analytical_field_idIsSet = false;
    m_Value = utility::conversions::to_string_t("");
    m_ValueIsSet = false;
    m_Transaction_id = utility::conversions::to_string_t("");
    m_Transaction_idIsSet = false;
    m_Software_version = utility::conversions::to_string_t("");
    m_Software_versionIsSet = false;
    m_Created_date_utc = utility::datetime();
    m_Created_date_utcIsSet = false;
    m_Modified_date_utc = utility::datetime();
    m_Modified_date_utcIsSet = false;
    m_Is_last = false;
    m_Is_lastIsSet = false;
    m_Analytical_fieldIsSet = false;
}

DeviceAnalyticalHeartbeatDto::~DeviceAnalyticalHeartbeatDto()
{
}

void DeviceAnalyticalHeartbeatDto::validate()
{
    // TODO: implement validation
}

web::json::value DeviceAnalyticalHeartbeatDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_License_assignment_idIsSet)
    {
        val[utility::conversions::to_string_t(U("license_assignment_id"))] = ModelBase::toJson(m_License_assignment_id);
    }
    if(m_Analytical_field_idIsSet)
    {
        val[utility::conversions::to_string_t(U("analytical_field_id"))] = ModelBase::toJson(m_Analytical_field_id);
    }
    if(m_ValueIsSet)
    {
        val[utility::conversions::to_string_t(U("value"))] = ModelBase::toJson(m_Value);
    }
    if(m_Transaction_idIsSet)
    {
        val[utility::conversions::to_string_t(U("transaction_id"))] = ModelBase::toJson(m_Transaction_id);
    }
    if(m_Software_versionIsSet)
    {
        val[utility::conversions::to_string_t(U("software_version"))] = ModelBase::toJson(m_Software_version);
    }
    if(m_Created_date_utcIsSet)
    {
        val[utility::conversions::to_string_t(U("created_date_utc"))] = ModelBase::toJson(m_Created_date_utc);
    }
    if(m_Modified_date_utcIsSet)
    {
        val[utility::conversions::to_string_t(U("modified_date_utc"))] = ModelBase::toJson(m_Modified_date_utc);
    }
    if(m_Is_lastIsSet)
    {
        val[utility::conversions::to_string_t(U("is_last"))] = ModelBase::toJson(m_Is_last);
    }
    if(m_Analytical_fieldIsSet)
    {
        val[utility::conversions::to_string_t(U("analytical_field"))] = ModelBase::toJson(m_Analytical_field);
    }

    return val;
}

bool DeviceAnalyticalHeartbeatDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("license_assignment_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("license_assignment_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLicenseAssignmentId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLicenseAssignmentId);
            setLicenseAssignmentId(refVal_setLicenseAssignmentId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("analytical_field_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("analytical_field_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setAnalyticalFieldId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setAnalyticalFieldId);
            setAnalyticalFieldId(refVal_setAnalyticalFieldId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("value"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("value")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setValue;
            ok &= ModelBase::fromJson(fieldValue, refVal_setValue);
            setValue(refVal_setValue);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("transaction_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("transaction_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setTransactionId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTransactionId);
            setTransactionId(refVal_setTransactionId);
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
    if(val.has_field(utility::conversions::to_string_t(U("modified_date_utc"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("modified_date_utc")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setModifiedDateUtc;
            ok &= ModelBase::fromJson(fieldValue, refVal_setModifiedDateUtc);
            setModifiedDateUtc(refVal_setModifiedDateUtc);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("is_last"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("is_last")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsLast;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsLast);
            setIsLast(refVal_setIsLast);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("analytical_field"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("analytical_field")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<AnalyticalFieldDto> refVal_setAnalyticalField;
            ok &= ModelBase::fromJson(fieldValue, refVal_setAnalyticalField);
            setAnalyticalField(refVal_setAnalyticalField);
        }
    }
    return ok;
}

void DeviceAnalyticalHeartbeatDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_License_assignment_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("license_assignment_id")), m_License_assignment_id));
    }
    if(m_Analytical_field_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("analytical_field_id")), m_Analytical_field_id));
    }
    if(m_ValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("value")), m_Value));
    }
    if(m_Transaction_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("transaction_id")), m_Transaction_id));
    }
    if(m_Software_versionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("software_version")), m_Software_version));
    }
    if(m_Created_date_utcIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("created_date_utc")), m_Created_date_utc));
    }
    if(m_Modified_date_utcIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("modified_date_utc")), m_Modified_date_utc));
    }
    if(m_Is_lastIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("is_last")), m_Is_last));
    }
    if(m_Analytical_fieldIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("analytical_field")), m_Analytical_field));
    }
}

bool DeviceAnalyticalHeartbeatDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("license_assignment_id"))))
    {
        utility::string_t refVal_setLicenseAssignmentId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("license_assignment_id"))), refVal_setLicenseAssignmentId );
        setLicenseAssignmentId(refVal_setLicenseAssignmentId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("analytical_field_id"))))
    {
        utility::string_t refVal_setAnalyticalFieldId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("analytical_field_id"))), refVal_setAnalyticalFieldId );
        setAnalyticalFieldId(refVal_setAnalyticalFieldId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("value"))))
    {
        utility::string_t refVal_setValue;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("value"))), refVal_setValue );
        setValue(refVal_setValue);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("transaction_id"))))
    {
        utility::string_t refVal_setTransactionId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("transaction_id"))), refVal_setTransactionId );
        setTransactionId(refVal_setTransactionId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("software_version"))))
    {
        utility::string_t refVal_setSoftwareVersion;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("software_version"))), refVal_setSoftwareVersion );
        setSoftwareVersion(refVal_setSoftwareVersion);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("created_date_utc"))))
    {
        utility::datetime refVal_setCreatedDateUtc;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("created_date_utc"))), refVal_setCreatedDateUtc );
        setCreatedDateUtc(refVal_setCreatedDateUtc);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("modified_date_utc"))))
    {
        utility::datetime refVal_setModifiedDateUtc;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("modified_date_utc"))), refVal_setModifiedDateUtc );
        setModifiedDateUtc(refVal_setModifiedDateUtc);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("is_last"))))
    {
        bool refVal_setIsLast;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("is_last"))), refVal_setIsLast );
        setIsLast(refVal_setIsLast);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("analytical_field"))))
    {
        std::shared_ptr<AnalyticalFieldDto> refVal_setAnalyticalField;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("analytical_field"))), refVal_setAnalyticalField );
        setAnalyticalField(refVal_setAnalyticalField);
    }
    return ok;
}

utility::string_t DeviceAnalyticalHeartbeatDto::getLicenseAssignmentId() const
{
    return m_License_assignment_id;
}

void DeviceAnalyticalHeartbeatDto::setLicenseAssignmentId(const utility::string_t& value)
{
    m_License_assignment_id = value;
    m_License_assignment_idIsSet = true;
}

bool DeviceAnalyticalHeartbeatDto::licenseAssignmentIdIsSet() const
{
    return m_License_assignment_idIsSet;
}

void DeviceAnalyticalHeartbeatDto::unsetLicense_assignment_id()
{
    m_License_assignment_idIsSet = false;
}
utility::string_t DeviceAnalyticalHeartbeatDto::getAnalyticalFieldId() const
{
    return m_Analytical_field_id;
}

void DeviceAnalyticalHeartbeatDto::setAnalyticalFieldId(const utility::string_t& value)
{
    m_Analytical_field_id = value;
    m_Analytical_field_idIsSet = true;
}

bool DeviceAnalyticalHeartbeatDto::analyticalFieldIdIsSet() const
{
    return m_Analytical_field_idIsSet;
}

void DeviceAnalyticalHeartbeatDto::unsetAnalytical_field_id()
{
    m_Analytical_field_idIsSet = false;
}
utility::string_t DeviceAnalyticalHeartbeatDto::getValue() const
{
    return m_Value;
}

void DeviceAnalyticalHeartbeatDto::setValue(const utility::string_t& value)
{
    m_Value = value;
    m_ValueIsSet = true;
}

bool DeviceAnalyticalHeartbeatDto::valueIsSet() const
{
    return m_ValueIsSet;
}

void DeviceAnalyticalHeartbeatDto::unsetValue()
{
    m_ValueIsSet = false;
}
utility::string_t DeviceAnalyticalHeartbeatDto::getTransactionId() const
{
    return m_Transaction_id;
}

void DeviceAnalyticalHeartbeatDto::setTransactionId(const utility::string_t& value)
{
    m_Transaction_id = value;
    m_Transaction_idIsSet = true;
}

bool DeviceAnalyticalHeartbeatDto::transactionIdIsSet() const
{
    return m_Transaction_idIsSet;
}

void DeviceAnalyticalHeartbeatDto::unsetTransaction_id()
{
    m_Transaction_idIsSet = false;
}
utility::string_t DeviceAnalyticalHeartbeatDto::getSoftwareVersion() const
{
    return m_Software_version;
}

void DeviceAnalyticalHeartbeatDto::setSoftwareVersion(const utility::string_t& value)
{
    m_Software_version = value;
    m_Software_versionIsSet = true;
}

bool DeviceAnalyticalHeartbeatDto::softwareVersionIsSet() const
{
    return m_Software_versionIsSet;
}

void DeviceAnalyticalHeartbeatDto::unsetSoftware_version()
{
    m_Software_versionIsSet = false;
}
utility::datetime DeviceAnalyticalHeartbeatDto::getCreatedDateUtc() const
{
    return m_Created_date_utc;
}

void DeviceAnalyticalHeartbeatDto::setCreatedDateUtc(const utility::datetime& value)
{
    m_Created_date_utc = value;
    m_Created_date_utcIsSet = true;
}

bool DeviceAnalyticalHeartbeatDto::createdDateUtcIsSet() const
{
    return m_Created_date_utcIsSet;
}

void DeviceAnalyticalHeartbeatDto::unsetCreated_date_utc()
{
    m_Created_date_utcIsSet = false;
}
utility::datetime DeviceAnalyticalHeartbeatDto::getModifiedDateUtc() const
{
    return m_Modified_date_utc;
}

void DeviceAnalyticalHeartbeatDto::setModifiedDateUtc(const utility::datetime& value)
{
    m_Modified_date_utc = value;
    m_Modified_date_utcIsSet = true;
}

bool DeviceAnalyticalHeartbeatDto::modifiedDateUtcIsSet() const
{
    return m_Modified_date_utcIsSet;
}

void DeviceAnalyticalHeartbeatDto::unsetModified_date_utc()
{
    m_Modified_date_utcIsSet = false;
}
bool DeviceAnalyticalHeartbeatDto::isIsLast() const
{
    return m_Is_last;
}

void DeviceAnalyticalHeartbeatDto::setIsLast(bool value)
{
    m_Is_last = value;
    m_Is_lastIsSet = true;
}

bool DeviceAnalyticalHeartbeatDto::isLastIsSet() const
{
    return m_Is_lastIsSet;
}

void DeviceAnalyticalHeartbeatDto::unsetIs_last()
{
    m_Is_lastIsSet = false;
}
std::shared_ptr<AnalyticalFieldDto> DeviceAnalyticalHeartbeatDto::getAnalyticalField() const
{
    return m_Analytical_field;
}

void DeviceAnalyticalHeartbeatDto::setAnalyticalField(const std::shared_ptr<AnalyticalFieldDto>& value)
{
    m_Analytical_field = value;
    m_Analytical_fieldIsSet = true;
}

bool DeviceAnalyticalHeartbeatDto::analyticalFieldIsSet() const
{
    return m_Analytical_fieldIsSet;
}

void DeviceAnalyticalHeartbeatDto::unsetAnalytical_field()
{
    m_Analytical_fieldIsSet = false;
}
}
}
}
}


