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



#include "SlasconeOpenApiClient/model/LicenseFeatureExceptionDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



LicenseFeatureExceptionDto::LicenseFeatureExceptionDto()
{
    m_Start_date_utc = utility::datetime();
    m_Start_date_utcIsSet = false;
    m_End_date_utc = utility::datetime();
    m_End_date_utcIsSet = false;
    m_Temporary_is_active = false;
    m_Temporary_is_activeIsSet = false;
}

LicenseFeatureExceptionDto::~LicenseFeatureExceptionDto()
{
}

void LicenseFeatureExceptionDto::validate()
{
    // TODO: implement validation
}

web::json::value LicenseFeatureExceptionDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Start_date_utcIsSet)
    {
        val[utility::conversions::to_string_t(U("start_date_utc"))] = ModelBase::toJson(m_Start_date_utc);
    }
    if(m_End_date_utcIsSet)
    {
        val[utility::conversions::to_string_t(U("end_date_utc"))] = ModelBase::toJson(m_End_date_utc);
    }
    if(m_Temporary_is_activeIsSet)
    {
        val[utility::conversions::to_string_t(U("temporary_is_active"))] = ModelBase::toJson(m_Temporary_is_active);
    }

    return val;
}

bool LicenseFeatureExceptionDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("start_date_utc"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("start_date_utc")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setStartDateUtc;
            ok &= ModelBase::fromJson(fieldValue, refVal_setStartDateUtc);
            setStartDateUtc(refVal_setStartDateUtc);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("end_date_utc"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("end_date_utc")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setEndDateUtc;
            ok &= ModelBase::fromJson(fieldValue, refVal_setEndDateUtc);
            setEndDateUtc(refVal_setEndDateUtc);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("temporary_is_active"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("temporary_is_active")));
        if(!fieldValue.is_null())
        {
            bool refVal_setTemporaryIsActive;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTemporaryIsActive);
            setTemporaryIsActive(refVal_setTemporaryIsActive);
        }
    }
    return ok;
}

void LicenseFeatureExceptionDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_Start_date_utcIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("start_date_utc")), m_Start_date_utc));
    }
    if(m_End_date_utcIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("end_date_utc")), m_End_date_utc));
    }
    if(m_Temporary_is_activeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("temporary_is_active")), m_Temporary_is_active));
    }
}

bool LicenseFeatureExceptionDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("start_date_utc"))))
    {
        utility::datetime refVal_setStartDateUtc;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("start_date_utc"))), refVal_setStartDateUtc );
        setStartDateUtc(refVal_setStartDateUtc);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("end_date_utc"))))
    {
        utility::datetime refVal_setEndDateUtc;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("end_date_utc"))), refVal_setEndDateUtc );
        setEndDateUtc(refVal_setEndDateUtc);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("temporary_is_active"))))
    {
        bool refVal_setTemporaryIsActive;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("temporary_is_active"))), refVal_setTemporaryIsActive );
        setTemporaryIsActive(refVal_setTemporaryIsActive);
    }
    return ok;
}

utility::datetime LicenseFeatureExceptionDto::getStartDateUtc() const
{
    return m_Start_date_utc;
}

void LicenseFeatureExceptionDto::setStartDateUtc(const utility::datetime& value)
{
    m_Start_date_utc = value;
    m_Start_date_utcIsSet = true;
}

bool LicenseFeatureExceptionDto::startDateUtcIsSet() const
{
    return m_Start_date_utcIsSet;
}

void LicenseFeatureExceptionDto::unsetStart_date_utc()
{
    m_Start_date_utcIsSet = false;
}
utility::datetime LicenseFeatureExceptionDto::getEndDateUtc() const
{
    return m_End_date_utc;
}

void LicenseFeatureExceptionDto::setEndDateUtc(const utility::datetime& value)
{
    m_End_date_utc = value;
    m_End_date_utcIsSet = true;
}

bool LicenseFeatureExceptionDto::endDateUtcIsSet() const
{
    return m_End_date_utcIsSet;
}

void LicenseFeatureExceptionDto::unsetEnd_date_utc()
{
    m_End_date_utcIsSet = false;
}
bool LicenseFeatureExceptionDto::isTemporaryIsActive() const
{
    return m_Temporary_is_active;
}

void LicenseFeatureExceptionDto::setTemporaryIsActive(bool value)
{
    m_Temporary_is_active = value;
    m_Temporary_is_activeIsSet = true;
}

bool LicenseFeatureExceptionDto::temporaryIsActiveIsSet() const
{
    return m_Temporary_is_activeIsSet;
}

void LicenseFeatureExceptionDto::unsetTemporary_is_active()
{
    m_Temporary_is_activeIsSet = false;
}
}
}
}
}


