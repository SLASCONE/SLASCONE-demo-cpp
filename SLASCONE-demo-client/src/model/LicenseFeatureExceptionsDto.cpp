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



#include "SlasconeOpenApiClient/model/LicenseFeatureExceptionsDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



LicenseFeatureExceptionsDto::LicenseFeatureExceptionsDto()
{
    m_Original_is_active = false;
    m_Original_is_activeIsSet = false;
    m_ExceptionsIsSet = false;
}

LicenseFeatureExceptionsDto::~LicenseFeatureExceptionsDto()
{
}

void LicenseFeatureExceptionsDto::validate()
{
    // TODO: implement validation
}

web::json::value LicenseFeatureExceptionsDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Original_is_activeIsSet)
    {
        val[utility::conversions::to_string_t(U("original_is_active"))] = ModelBase::toJson(m_Original_is_active);
    }
    if(m_ExceptionsIsSet)
    {
        val[utility::conversions::to_string_t(U("exceptions"))] = ModelBase::toJson(m_Exceptions);
    }

    return val;
}

bool LicenseFeatureExceptionsDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("original_is_active"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("original_is_active")));
        if(!fieldValue.is_null())
        {
            bool refVal_setOriginalIsActive;
            ok &= ModelBase::fromJson(fieldValue, refVal_setOriginalIsActive);
            setOriginalIsActive(refVal_setOriginalIsActive);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("exceptions"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("exceptions")));
        if(!fieldValue.is_null())
        {
            std::vector<std::shared_ptr<LicenseFeatureExceptionDto>> refVal_setExceptions;
            ok &= ModelBase::fromJson(fieldValue, refVal_setExceptions);
            setExceptions(refVal_setExceptions);
        }
    }
    return ok;
}

void LicenseFeatureExceptionsDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_Original_is_activeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("original_is_active")), m_Original_is_active));
    }
    if(m_ExceptionsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("exceptions")), m_Exceptions));
    }
}

bool LicenseFeatureExceptionsDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("original_is_active"))))
    {
        bool refVal_setOriginalIsActive;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("original_is_active"))), refVal_setOriginalIsActive );
        setOriginalIsActive(refVal_setOriginalIsActive);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("exceptions"))))
    {
        std::vector<std::shared_ptr<LicenseFeatureExceptionDto>> refVal_setExceptions;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("exceptions"))), refVal_setExceptions );
        setExceptions(refVal_setExceptions);
    }
    return ok;
}

bool LicenseFeatureExceptionsDto::isOriginalIsActive() const
{
    return m_Original_is_active;
}

void LicenseFeatureExceptionsDto::setOriginalIsActive(bool value)
{
    m_Original_is_active = value;
    m_Original_is_activeIsSet = true;
}

bool LicenseFeatureExceptionsDto::originalIsActiveIsSet() const
{
    return m_Original_is_activeIsSet;
}

void LicenseFeatureExceptionsDto::unsetOriginal_is_active()
{
    m_Original_is_activeIsSet = false;
}
std::vector<std::shared_ptr<LicenseFeatureExceptionDto>>& LicenseFeatureExceptionsDto::getExceptions()
{
    return m_Exceptions;
}

void LicenseFeatureExceptionsDto::setExceptions(const std::vector<std::shared_ptr<LicenseFeatureExceptionDto>>& value)
{
    m_Exceptions = value;
    m_ExceptionsIsSet = true;
}

bool LicenseFeatureExceptionsDto::exceptionsIsSet() const
{
    return m_ExceptionsIsSet;
}

void LicenseFeatureExceptionsDto::unsetExceptions()
{
    m_ExceptionsIsSet = false;
}
}
}
}
}

