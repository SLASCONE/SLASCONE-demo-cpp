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



#include "SlasconeOpenApiClient/model/LimitationDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



LimitationDto::LimitationDto()
{
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_Product_id = utility::conversions::to_string_t("");
    m_Product_idIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Description = utility::conversions::to_string_t("");
    m_DescriptionIsSet = false;
    m_Is_aggregatable = false;
    m_Is_aggregatableIsSet = false;
}

LimitationDto::~LimitationDto()
{
}

void LimitationDto::validate()
{
    // TODO: implement validation
}

web::json::value LimitationDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t(U("id"))] = ModelBase::toJson(m_Id);
    }
    if(m_Product_idIsSet)
    {
        val[utility::conversions::to_string_t(U("product_id"))] = ModelBase::toJson(m_Product_id);
    }
    if(m_NameIsSet)
    {
        val[utility::conversions::to_string_t(U("name"))] = ModelBase::toJson(m_Name);
    }
    if(m_DescriptionIsSet)
    {
        val[utility::conversions::to_string_t(U("description"))] = ModelBase::toJson(m_Description);
    }
    if(m_Is_aggregatableIsSet)
    {
        val[utility::conversions::to_string_t(U("is_aggregatable"))] = ModelBase::toJson(m_Is_aggregatable);
    }

    return val;
}

bool LimitationDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("name"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("name")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setName);
            setName(refVal_setName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("description"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("description")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setDescription;
            ok &= ModelBase::fromJson(fieldValue, refVal_setDescription);
            setDescription(refVal_setDescription);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("is_aggregatable"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("is_aggregatable")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsAggregatable;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsAggregatable);
            setIsAggregatable(refVal_setIsAggregatable);
        }
    }
    return ok;
}

void LimitationDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_Product_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("product_id")), m_Product_id));
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("name")), m_Name));
    }
    if(m_DescriptionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("description")), m_Description));
    }
    if(m_Is_aggregatableIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("is_aggregatable")), m_Is_aggregatable));
    }
}

bool LimitationDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("product_id"))))
    {
        utility::string_t refVal_setProductId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("product_id"))), refVal_setProductId );
        setProductId(refVal_setProductId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("name"))))
    {
        utility::string_t refVal_setName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("name"))), refVal_setName );
        setName(refVal_setName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("description"))))
    {
        utility::string_t refVal_setDescription;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("description"))), refVal_setDescription );
        setDescription(refVal_setDescription);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("is_aggregatable"))))
    {
        bool refVal_setIsAggregatable;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("is_aggregatable"))), refVal_setIsAggregatable );
        setIsAggregatable(refVal_setIsAggregatable);
    }
    return ok;
}

utility::string_t LimitationDto::getId() const
{
    return m_Id;
}

void LimitationDto::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool LimitationDto::idIsSet() const
{
    return m_IdIsSet;
}

void LimitationDto::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t LimitationDto::getProductId() const
{
    return m_Product_id;
}

void LimitationDto::setProductId(const utility::string_t& value)
{
    m_Product_id = value;
    m_Product_idIsSet = true;
}

bool LimitationDto::productIdIsSet() const
{
    return m_Product_idIsSet;
}

void LimitationDto::unsetProduct_id()
{
    m_Product_idIsSet = false;
}
utility::string_t LimitationDto::getName() const
{
    return m_Name;
}

void LimitationDto::setName(const utility::string_t& value)
{
    m_Name = value;
    m_NameIsSet = true;
}

bool LimitationDto::nameIsSet() const
{
    return m_NameIsSet;
}

void LimitationDto::unsetName()
{
    m_NameIsSet = false;
}
utility::string_t LimitationDto::getDescription() const
{
    return m_Description;
}

void LimitationDto::setDescription(const utility::string_t& value)
{
    m_Description = value;
    m_DescriptionIsSet = true;
}

bool LimitationDto::descriptionIsSet() const
{
    return m_DescriptionIsSet;
}

void LimitationDto::unsetDescription()
{
    m_DescriptionIsSet = false;
}
bool LimitationDto::isIsAggregatable() const
{
    return m_Is_aggregatable;
}

void LimitationDto::setIsAggregatable(bool value)
{
    m_Is_aggregatable = value;
    m_Is_aggregatableIsSet = true;
}

bool LimitationDto::isAggregatableIsSet() const
{
    return m_Is_aggregatableIsSet;
}

void LimitationDto::unsetIs_aggregatable()
{
    m_Is_aggregatableIsSet = false;
}
}
}
}
}


