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



#include "SlasconeOpenApiClient/model/LicenseFeatureDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



LicenseFeatureDto::LicenseFeatureDto()
{
    m_Product_id = utility::conversions::to_string_t("");
    m_Product_idIsSet = false;
    m_Feature_id = utility::conversions::to_string_t("");
    m_Feature_idIsSet = false;
    m_Feature_name = utility::conversions::to_string_t("");
    m_Feature_nameIsSet = false;
    m_Feature_description = utility::conversions::to_string_t("");
    m_Feature_descriptionIsSet = false;
    m_Is_active = false;
    m_Is_activeIsSet = false;
    m_Feature_exceptionsIsSet = false;
}

LicenseFeatureDto::~LicenseFeatureDto()
{
}

void LicenseFeatureDto::validate()
{
    // TODO: implement validation
}

web::json::value LicenseFeatureDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Product_idIsSet)
    {
        val[utility::conversions::to_string_t(U("product_id"))] = ModelBase::toJson(m_Product_id);
    }
    if(m_Feature_idIsSet)
    {
        val[utility::conversions::to_string_t(U("feature_id"))] = ModelBase::toJson(m_Feature_id);
    }
    if(m_Feature_nameIsSet)
    {
        val[utility::conversions::to_string_t(U("feature_name"))] = ModelBase::toJson(m_Feature_name);
    }
    if(m_Feature_descriptionIsSet)
    {
        val[utility::conversions::to_string_t(U("feature_description"))] = ModelBase::toJson(m_Feature_description);
    }
    if(m_Is_activeIsSet)
    {
        val[utility::conversions::to_string_t(U("is_active"))] = ModelBase::toJson(m_Is_active);
    }
    if(m_Feature_exceptionsIsSet)
    {
        val[utility::conversions::to_string_t(U("feature_exceptions"))] = ModelBase::toJson(m_Feature_exceptions);
    }

    return val;
}

bool LicenseFeatureDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("product_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("product_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setProductId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setProductId);
            setProductId(refVal_setProductId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("feature_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("feature_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setFeatureId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setFeatureId);
            setFeatureId(refVal_setFeatureId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("feature_name"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("feature_name")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setFeatureName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setFeatureName);
            setFeatureName(refVal_setFeatureName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("feature_description"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("feature_description")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setFeatureDescription;
            ok &= ModelBase::fromJson(fieldValue, refVal_setFeatureDescription);
            setFeatureDescription(refVal_setFeatureDescription);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("is_active"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("is_active")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsActive;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsActive);
            setIsActive(refVal_setIsActive);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("feature_exceptions"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("feature_exceptions")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<LicenseFeatureExceptionsDto> refVal_setFeatureExceptions;
            ok &= ModelBase::fromJson(fieldValue, refVal_setFeatureExceptions);
            setFeatureExceptions(refVal_setFeatureExceptions);
        }
    }
    return ok;
}

void LicenseFeatureDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_Product_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("product_id")), m_Product_id));
    }
    if(m_Feature_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("feature_id")), m_Feature_id));
    }
    if(m_Feature_nameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("feature_name")), m_Feature_name));
    }
    if(m_Feature_descriptionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("feature_description")), m_Feature_description));
    }
    if(m_Is_activeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("is_active")), m_Is_active));
    }
    if(m_Feature_exceptionsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("feature_exceptions")), m_Feature_exceptions));
    }
}

bool LicenseFeatureDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("product_id"))))
    {
        utility::string_t refVal_setProductId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("product_id"))), refVal_setProductId );
        setProductId(refVal_setProductId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("feature_id"))))
    {
        utility::string_t refVal_setFeatureId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("feature_id"))), refVal_setFeatureId );
        setFeatureId(refVal_setFeatureId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("feature_name"))))
    {
        utility::string_t refVal_setFeatureName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("feature_name"))), refVal_setFeatureName );
        setFeatureName(refVal_setFeatureName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("feature_description"))))
    {
        utility::string_t refVal_setFeatureDescription;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("feature_description"))), refVal_setFeatureDescription );
        setFeatureDescription(refVal_setFeatureDescription);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("is_active"))))
    {
        bool refVal_setIsActive;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("is_active"))), refVal_setIsActive );
        setIsActive(refVal_setIsActive);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("feature_exceptions"))))
    {
        std::shared_ptr<LicenseFeatureExceptionsDto> refVal_setFeatureExceptions;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("feature_exceptions"))), refVal_setFeatureExceptions );
        setFeatureExceptions(refVal_setFeatureExceptions);
    }
    return ok;
}

utility::string_t LicenseFeatureDto::getProductId() const
{
    return m_Product_id;
}

void LicenseFeatureDto::setProductId(const utility::string_t& value)
{
    m_Product_id = value;
    m_Product_idIsSet = true;
}

bool LicenseFeatureDto::productIdIsSet() const
{
    return m_Product_idIsSet;
}

void LicenseFeatureDto::unsetProduct_id()
{
    m_Product_idIsSet = false;
}
utility::string_t LicenseFeatureDto::getFeatureId() const
{
    return m_Feature_id;
}

void LicenseFeatureDto::setFeatureId(const utility::string_t& value)
{
    m_Feature_id = value;
    m_Feature_idIsSet = true;
}

bool LicenseFeatureDto::featureIdIsSet() const
{
    return m_Feature_idIsSet;
}

void LicenseFeatureDto::unsetFeature_id()
{
    m_Feature_idIsSet = false;
}
utility::string_t LicenseFeatureDto::getFeatureName() const
{
    return m_Feature_name;
}

void LicenseFeatureDto::setFeatureName(const utility::string_t& value)
{
    m_Feature_name = value;
    m_Feature_nameIsSet = true;
}

bool LicenseFeatureDto::featureNameIsSet() const
{
    return m_Feature_nameIsSet;
}

void LicenseFeatureDto::unsetFeature_name()
{
    m_Feature_nameIsSet = false;
}
utility::string_t LicenseFeatureDto::getFeatureDescription() const
{
    return m_Feature_description;
}

void LicenseFeatureDto::setFeatureDescription(const utility::string_t& value)
{
    m_Feature_description = value;
    m_Feature_descriptionIsSet = true;
}

bool LicenseFeatureDto::featureDescriptionIsSet() const
{
    return m_Feature_descriptionIsSet;
}

void LicenseFeatureDto::unsetFeature_description()
{
    m_Feature_descriptionIsSet = false;
}
bool LicenseFeatureDto::isIsActive() const
{
    return m_Is_active;
}

void LicenseFeatureDto::setIsActive(bool value)
{
    m_Is_active = value;
    m_Is_activeIsSet = true;
}

bool LicenseFeatureDto::isActiveIsSet() const
{
    return m_Is_activeIsSet;
}

void LicenseFeatureDto::unsetIs_active()
{
    m_Is_activeIsSet = false;
}
std::shared_ptr<LicenseFeatureExceptionsDto> LicenseFeatureDto::getFeatureExceptions() const
{
    return m_Feature_exceptions;
}

void LicenseFeatureDto::setFeatureExceptions(const std::shared_ptr<LicenseFeatureExceptionsDto>& value)
{
    m_Feature_exceptions = value;
    m_Feature_exceptionsIsSet = true;
}

bool LicenseFeatureDto::featureExceptionsIsSet() const
{
    return m_Feature_exceptionsIsSet;
}

void LicenseFeatureDto::unsetFeature_exceptions()
{
    m_Feature_exceptionsIsSet = false;
}
}
}
}
}


