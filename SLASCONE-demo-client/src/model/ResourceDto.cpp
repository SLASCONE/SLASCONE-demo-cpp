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



#include "SlasconeOpenApiClient/model/ResourceDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



ResourceDto::ResourceDto()
{
    m_Uri = utility::conversions::to_string_t("");
    m_UriIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
}

ResourceDto::~ResourceDto()
{
}

void ResourceDto::validate()
{
    // TODO: implement validation
}

web::json::value ResourceDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_UriIsSet)
    {
        val[utility::conversions::to_string_t(U("uri"))] = ModelBase::toJson(m_Uri);
    }
    if(m_NameIsSet)
    {
        val[utility::conversions::to_string_t(U("name"))] = ModelBase::toJson(m_Name);
    }

    return val;
}

bool ResourceDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("uri"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("uri")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setUri;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUri);
            setUri(refVal_setUri);
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
    return ok;
}

void ResourceDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_UriIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("uri")), m_Uri));
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("name")), m_Name));
    }
}

bool ResourceDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("uri"))))
    {
        utility::string_t refVal_setUri;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("uri"))), refVal_setUri );
        setUri(refVal_setUri);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("name"))))
    {
        utility::string_t refVal_setName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("name"))), refVal_setName );
        setName(refVal_setName);
    }
    return ok;
}

utility::string_t ResourceDto::getUri() const
{
    return m_Uri;
}

void ResourceDto::setUri(const utility::string_t& value)
{
    m_Uri = value;
    m_UriIsSet = true;
}

bool ResourceDto::uriIsSet() const
{
    return m_UriIsSet;
}

void ResourceDto::unsetUri()
{
    m_UriIsSet = false;
}
utility::string_t ResourceDto::getName() const
{
    return m_Name;
}

void ResourceDto::setName(const utility::string_t& value)
{
    m_Name = value;
    m_NameIsSet = true;
}

bool ResourceDto::nameIsSet() const
{
    return m_NameIsSet;
}

void ResourceDto::unsetName()
{
    m_NameIsSet = false;
}
}
}
}
}


