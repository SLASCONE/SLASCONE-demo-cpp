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



#include "SlasconeOpenApiClient/model/ResellerLazyLoadDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



ResellerLazyLoadDto::ResellerLazyLoadDto()
{
    m_ResellersIsSet = false;
    m_Max_count = 0;
    m_Max_countIsSet = false;
    m_Reseller_characterIsSet = false;
}

ResellerLazyLoadDto::~ResellerLazyLoadDto()
{
}

void ResellerLazyLoadDto::validate()
{
    // TODO: implement validation
}

web::json::value ResellerLazyLoadDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_ResellersIsSet)
    {
        val[utility::conversions::to_string_t(U("resellers"))] = ModelBase::toJson(m_Resellers);
    }
    if(m_Max_countIsSet)
    {
        val[utility::conversions::to_string_t(U("max_count"))] = ModelBase::toJson(m_Max_count);
    }
    if(m_Reseller_characterIsSet)
    {
        val[utility::conversions::to_string_t(U("reseller_character"))] = ModelBase::toJson(m_Reseller_character);
    }

    return val;
}

bool ResellerLazyLoadDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("resellers"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("resellers")));
        if(!fieldValue.is_null())
        {
            std::vector<std::shared_ptr<ResellerDto>> refVal_setResellers;
            ok &= ModelBase::fromJson(fieldValue, refVal_setResellers);
            setResellers(refVal_setResellers);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("max_count"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("max_count")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setMaxCount;
            ok &= ModelBase::fromJson(fieldValue, refVal_setMaxCount);
            setMaxCount(refVal_setMaxCount);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("reseller_character"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("reseller_character")));
        if(!fieldValue.is_null())
        {
            std::vector<utility::string_t> refVal_setResellerCharacter;
            ok &= ModelBase::fromJson(fieldValue, refVal_setResellerCharacter);
            setResellerCharacter(refVal_setResellerCharacter);
        }
    }
    return ok;
}

void ResellerLazyLoadDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_ResellersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("resellers")), m_Resellers));
    }
    if(m_Max_countIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("max_count")), m_Max_count));
    }
    if(m_Reseller_characterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("reseller_character")), m_Reseller_character));
    }
}

bool ResellerLazyLoadDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("resellers"))))
    {
        std::vector<std::shared_ptr<ResellerDto>> refVal_setResellers;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("resellers"))), refVal_setResellers );
        setResellers(refVal_setResellers);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("max_count"))))
    {
        int32_t refVal_setMaxCount;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("max_count"))), refVal_setMaxCount );
        setMaxCount(refVal_setMaxCount);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("reseller_character"))))
    {
        std::vector<utility::string_t> refVal_setResellerCharacter;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("reseller_character"))), refVal_setResellerCharacter );
        setResellerCharacter(refVal_setResellerCharacter);
    }
    return ok;
}

std::vector<std::shared_ptr<ResellerDto>>& ResellerLazyLoadDto::getResellers()
{
    return m_Resellers;
}

void ResellerLazyLoadDto::setResellers(const std::vector<std::shared_ptr<ResellerDto>>& value)
{
    m_Resellers = value;
    m_ResellersIsSet = true;
}

bool ResellerLazyLoadDto::resellersIsSet() const
{
    return m_ResellersIsSet;
}

void ResellerLazyLoadDto::unsetResellers()
{
    m_ResellersIsSet = false;
}
int32_t ResellerLazyLoadDto::getMaxCount() const
{
    return m_Max_count;
}

void ResellerLazyLoadDto::setMaxCount(int32_t value)
{
    m_Max_count = value;
    m_Max_countIsSet = true;
}

bool ResellerLazyLoadDto::maxCountIsSet() const
{
    return m_Max_countIsSet;
}

void ResellerLazyLoadDto::unsetMax_count()
{
    m_Max_countIsSet = false;
}
std::vector<utility::string_t>& ResellerLazyLoadDto::getResellerCharacter()
{
    return m_Reseller_character;
}

void ResellerLazyLoadDto::setResellerCharacter(const std::vector<utility::string_t>& value)
{
    m_Reseller_character = value;
    m_Reseller_characterIsSet = true;
}

bool ResellerLazyLoadDto::resellerCharacterIsSet() const
{
    return m_Reseller_characterIsSet;
}

void ResellerLazyLoadDto::unsetReseller_character()
{
    m_Reseller_characterIsSet = false;
}
}
}
}
}


