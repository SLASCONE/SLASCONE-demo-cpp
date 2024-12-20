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



#include "SlasconeOpenApiClient/model/AnalyticalFieldDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



AnalyticalFieldDto::AnalyticalFieldDto()
{
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_Product_id = utility::conversions::to_string_t("");
    m_Product_idIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Description = utility::conversions::to_string_t("");
    m_DescriptionIsSet = false;
    m_TypIsSet = false;
    m_Is_chart_relevant = false;
    m_Is_chart_relevantIsSet = false;
    m_Is_full_logging = false;
    m_Is_full_loggingIsSet = false;
}

AnalyticalFieldDto::~AnalyticalFieldDto()
{
}

void AnalyticalFieldDto::validate()
{
    // TODO: implement validation
}

web::json::value AnalyticalFieldDto::toJson() const
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
    if(m_TypIsSet)
    {
        val[utility::conversions::to_string_t(U("typ"))] = ModelBase::toJson(m_Typ);
    }
    if(m_Is_chart_relevantIsSet)
    {
        val[utility::conversions::to_string_t(U("is_chart_relevant"))] = ModelBase::toJson(m_Is_chart_relevant);
    }
    if(m_Is_full_loggingIsSet)
    {
        val[utility::conversions::to_string_t(U("is_full_logging"))] = ModelBase::toJson(m_Is_full_logging);
    }

    return val;
}

bool AnalyticalFieldDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("typ"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("typ")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<AnalyticalFieldTyp> refVal_setTyp;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTyp);
            setTyp(refVal_setTyp);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("is_chart_relevant"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("is_chart_relevant")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsChartRelevant;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsChartRelevant);
            setIsChartRelevant(refVal_setIsChartRelevant);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("is_full_logging"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("is_full_logging")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsFullLogging;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsFullLogging);
            setIsFullLogging(refVal_setIsFullLogging);
        }
    }
    return ok;
}

void AnalyticalFieldDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_TypIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("typ")), m_Typ));
    }
    if(m_Is_chart_relevantIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("is_chart_relevant")), m_Is_chart_relevant));
    }
    if(m_Is_full_loggingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("is_full_logging")), m_Is_full_logging));
    }
}

bool AnalyticalFieldDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("typ"))))
    {
        std::shared_ptr<AnalyticalFieldTyp> refVal_setTyp;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("typ"))), refVal_setTyp );
        setTyp(refVal_setTyp);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("is_chart_relevant"))))
    {
        bool refVal_setIsChartRelevant;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("is_chart_relevant"))), refVal_setIsChartRelevant );
        setIsChartRelevant(refVal_setIsChartRelevant);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("is_full_logging"))))
    {
        bool refVal_setIsFullLogging;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("is_full_logging"))), refVal_setIsFullLogging );
        setIsFullLogging(refVal_setIsFullLogging);
    }
    return ok;
}

utility::string_t AnalyticalFieldDto::getId() const
{
    return m_Id;
}

void AnalyticalFieldDto::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool AnalyticalFieldDto::idIsSet() const
{
    return m_IdIsSet;
}

void AnalyticalFieldDto::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t AnalyticalFieldDto::getProductId() const
{
    return m_Product_id;
}

void AnalyticalFieldDto::setProductId(const utility::string_t& value)
{
    m_Product_id = value;
    m_Product_idIsSet = true;
}

bool AnalyticalFieldDto::productIdIsSet() const
{
    return m_Product_idIsSet;
}

void AnalyticalFieldDto::unsetProduct_id()
{
    m_Product_idIsSet = false;
}
utility::string_t AnalyticalFieldDto::getName() const
{
    return m_Name;
}

void AnalyticalFieldDto::setName(const utility::string_t& value)
{
    m_Name = value;
    m_NameIsSet = true;
}

bool AnalyticalFieldDto::nameIsSet() const
{
    return m_NameIsSet;
}

void AnalyticalFieldDto::unsetName()
{
    m_NameIsSet = false;
}
utility::string_t AnalyticalFieldDto::getDescription() const
{
    return m_Description;
}

void AnalyticalFieldDto::setDescription(const utility::string_t& value)
{
    m_Description = value;
    m_DescriptionIsSet = true;
}

bool AnalyticalFieldDto::descriptionIsSet() const
{
    return m_DescriptionIsSet;
}

void AnalyticalFieldDto::unsetDescription()
{
    m_DescriptionIsSet = false;
}
std::shared_ptr<AnalyticalFieldTyp> AnalyticalFieldDto::getTyp() const
{
    return m_Typ;
}

void AnalyticalFieldDto::setTyp(const std::shared_ptr<AnalyticalFieldTyp>& value)
{
    m_Typ = value;
    m_TypIsSet = true;
}

bool AnalyticalFieldDto::typIsSet() const
{
    return m_TypIsSet;
}

void AnalyticalFieldDto::unsetTyp()
{
    m_TypIsSet = false;
}
bool AnalyticalFieldDto::isIsChartRelevant() const
{
    return m_Is_chart_relevant;
}

void AnalyticalFieldDto::setIsChartRelevant(bool value)
{
    m_Is_chart_relevant = value;
    m_Is_chart_relevantIsSet = true;
}

bool AnalyticalFieldDto::isChartRelevantIsSet() const
{
    return m_Is_chart_relevantIsSet;
}

void AnalyticalFieldDto::unsetIs_chart_relevant()
{
    m_Is_chart_relevantIsSet = false;
}
bool AnalyticalFieldDto::isIsFullLogging() const
{
    return m_Is_full_logging;
}

void AnalyticalFieldDto::setIsFullLogging(bool value)
{
    m_Is_full_logging = value;
    m_Is_full_loggingIsSet = true;
}

bool AnalyticalFieldDto::isFullLoggingIsSet() const
{
    return m_Is_full_loggingIsSet;
}

void AnalyticalFieldDto::unsetIs_full_logging()
{
    m_Is_full_loggingIsSet = false;
}
}
}
}
}


