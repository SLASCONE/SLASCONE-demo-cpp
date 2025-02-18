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



#include "SlasconeOpenApiClient/model/CustomerFilterDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



CustomerFilterDto::CustomerFilterDto()
{
    m_Page = 0;
    m_PageIsSet = false;
    m_Page_size = 0;
    m_Page_sizeIsSet = false;
    m_Search_text = utility::conversions::to_string_t("");
    m_Search_textIsSet = false;
    m_Plz_query = utility::conversions::to_string_t("");
    m_Plz_queryIsSet = false;
    m_Customer_typesIsSet = false;
    m_Reseller_typesIsSet = false;
    m_TagsIsSet = false;
    m_Start_character = utility::conversions::to_string_t("");
    m_Start_characterIsSet = false;
    m_Sort_typeIsSet = false;
    m_Descending = false;
    m_DescendingIsSet = false;
}

CustomerFilterDto::~CustomerFilterDto()
{
}

void CustomerFilterDto::validate()
{
    // TODO: implement validation
}

web::json::value CustomerFilterDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_PageIsSet)
    {
        val[utility::conversions::to_string_t(U("page"))] = ModelBase::toJson(m_Page);
    }
    if(m_Page_sizeIsSet)
    {
        val[utility::conversions::to_string_t(U("page_size"))] = ModelBase::toJson(m_Page_size);
    }
    if(m_Search_textIsSet)
    {
        val[utility::conversions::to_string_t(U("search_text"))] = ModelBase::toJson(m_Search_text);
    }
    if(m_Plz_queryIsSet)
    {
        val[utility::conversions::to_string_t(U("plz_query"))] = ModelBase::toJson(m_Plz_query);
    }
    if(m_Customer_typesIsSet)
    {
        val[utility::conversions::to_string_t(U("customer_types"))] = ModelBase::toJson(m_Customer_types);
    }
    if(m_Reseller_typesIsSet)
    {
        val[utility::conversions::to_string_t(U("reseller_types"))] = ModelBase::toJson(m_Reseller_types);
    }
    if(m_TagsIsSet)
    {
        val[utility::conversions::to_string_t(U("tags"))] = ModelBase::toJson(m_Tags);
    }
    if(m_Start_characterIsSet)
    {
        val[utility::conversions::to_string_t(U("start_character"))] = ModelBase::toJson(m_Start_character);
    }
    if(m_Sort_typeIsSet)
    {
        val[utility::conversions::to_string_t(U("sort_type"))] = ModelBase::toJson(m_Sort_type);
    }
    if(m_DescendingIsSet)
    {
        val[utility::conversions::to_string_t(U("descending"))] = ModelBase::toJson(m_Descending);
    }

    return val;
}

bool CustomerFilterDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("page"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("page")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setPage;
            ok &= ModelBase::fromJson(fieldValue, refVal_setPage);
            setPage(refVal_setPage);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("page_size"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("page_size")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setPageSize;
            ok &= ModelBase::fromJson(fieldValue, refVal_setPageSize);
            setPageSize(refVal_setPageSize);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("search_text"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("search_text")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setSearchText;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSearchText);
            setSearchText(refVal_setSearchText);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("plz_query"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("plz_query")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setPlzQuery;
            ok &= ModelBase::fromJson(fieldValue, refVal_setPlzQuery);
            setPlzQuery(refVal_setPlzQuery);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("customer_types"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("customer_types")));
        if(!fieldValue.is_null())
        {
            std::vector<utility::string_t> refVal_setCustomerTypes;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCustomerTypes);
            setCustomerTypes(refVal_setCustomerTypes);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("reseller_types"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("reseller_types")));
        if(!fieldValue.is_null())
        {
            std::vector<utility::string_t> refVal_setResellerTypes;
            ok &= ModelBase::fromJson(fieldValue, refVal_setResellerTypes);
            setResellerTypes(refVal_setResellerTypes);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("tags"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("tags")));
        if(!fieldValue.is_null())
        {
            std::vector<int32_t> refVal_setTags;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTags);
            setTags(refVal_setTags);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("start_character"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("start_character")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setStartCharacter;
            ok &= ModelBase::fromJson(fieldValue, refVal_setStartCharacter);
            setStartCharacter(refVal_setStartCharacter);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("sort_type"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("sort_type")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<SortTypeDto> refVal_setSortType;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSortType);
            setSortType(refVal_setSortType);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("descending"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("descending")));
        if(!fieldValue.is_null())
        {
            bool refVal_setDescending;
            ok &= ModelBase::fromJson(fieldValue, refVal_setDescending);
            setDescending(refVal_setDescending);
        }
    }
    return ok;
}

void CustomerFilterDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_PageIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("page")), m_Page));
    }
    if(m_Page_sizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("page_size")), m_Page_size));
    }
    if(m_Search_textIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("search_text")), m_Search_text));
    }
    if(m_Plz_queryIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("plz_query")), m_Plz_query));
    }
    if(m_Customer_typesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("customer_types")), m_Customer_types));
    }
    if(m_Reseller_typesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("reseller_types")), m_Reseller_types));
    }
    if(m_TagsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("tags")), m_Tags));
    }
    if(m_Start_characterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("start_character")), m_Start_character));
    }
    if(m_Sort_typeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("sort_type")), m_Sort_type));
    }
    if(m_DescendingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("descending")), m_Descending));
    }
}

bool CustomerFilterDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("page"))))
    {
        int32_t refVal_setPage;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("page"))), refVal_setPage );
        setPage(refVal_setPage);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("page_size"))))
    {
        int32_t refVal_setPageSize;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("page_size"))), refVal_setPageSize );
        setPageSize(refVal_setPageSize);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("search_text"))))
    {
        utility::string_t refVal_setSearchText;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("search_text"))), refVal_setSearchText );
        setSearchText(refVal_setSearchText);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("plz_query"))))
    {
        utility::string_t refVal_setPlzQuery;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("plz_query"))), refVal_setPlzQuery );
        setPlzQuery(refVal_setPlzQuery);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("customer_types"))))
    {
        std::vector<utility::string_t> refVal_setCustomerTypes;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("customer_types"))), refVal_setCustomerTypes );
        setCustomerTypes(refVal_setCustomerTypes);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("reseller_types"))))
    {
        std::vector<utility::string_t> refVal_setResellerTypes;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("reseller_types"))), refVal_setResellerTypes );
        setResellerTypes(refVal_setResellerTypes);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("tags"))))
    {
        std::vector<int32_t> refVal_setTags;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("tags"))), refVal_setTags );
        setTags(refVal_setTags);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("start_character"))))
    {
        utility::string_t refVal_setStartCharacter;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("start_character"))), refVal_setStartCharacter );
        setStartCharacter(refVal_setStartCharacter);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("sort_type"))))
    {
        std::shared_ptr<SortTypeDto> refVal_setSortType;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("sort_type"))), refVal_setSortType );
        setSortType(refVal_setSortType);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("descending"))))
    {
        bool refVal_setDescending;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("descending"))), refVal_setDescending );
        setDescending(refVal_setDescending);
    }
    return ok;
}

int32_t CustomerFilterDto::getPage() const
{
    return m_Page;
}

void CustomerFilterDto::setPage(int32_t value)
{
    m_Page = value;
    m_PageIsSet = true;
}

bool CustomerFilterDto::pageIsSet() const
{
    return m_PageIsSet;
}

void CustomerFilterDto::unsetPage()
{
    m_PageIsSet = false;
}
int32_t CustomerFilterDto::getPageSize() const
{
    return m_Page_size;
}

void CustomerFilterDto::setPageSize(int32_t value)
{
    m_Page_size = value;
    m_Page_sizeIsSet = true;
}

bool CustomerFilterDto::pageSizeIsSet() const
{
    return m_Page_sizeIsSet;
}

void CustomerFilterDto::unsetPage_size()
{
    m_Page_sizeIsSet = false;
}
utility::string_t CustomerFilterDto::getSearchText() const
{
    return m_Search_text;
}

void CustomerFilterDto::setSearchText(const utility::string_t& value)
{
    m_Search_text = value;
    m_Search_textIsSet = true;
}

bool CustomerFilterDto::searchTextIsSet() const
{
    return m_Search_textIsSet;
}

void CustomerFilterDto::unsetSearch_text()
{
    m_Search_textIsSet = false;
}
utility::string_t CustomerFilterDto::getPlzQuery() const
{
    return m_Plz_query;
}

void CustomerFilterDto::setPlzQuery(const utility::string_t& value)
{
    m_Plz_query = value;
    m_Plz_queryIsSet = true;
}

bool CustomerFilterDto::plzQueryIsSet() const
{
    return m_Plz_queryIsSet;
}

void CustomerFilterDto::unsetPlz_query()
{
    m_Plz_queryIsSet = false;
}
std::vector<utility::string_t>& CustomerFilterDto::getCustomerTypes()
{
    return m_Customer_types;
}

void CustomerFilterDto::setCustomerTypes(const std::vector<utility::string_t>& value)
{
    m_Customer_types = value;
    m_Customer_typesIsSet = true;
}

bool CustomerFilterDto::customerTypesIsSet() const
{
    return m_Customer_typesIsSet;
}

void CustomerFilterDto::unsetCustomer_types()
{
    m_Customer_typesIsSet = false;
}
std::vector<utility::string_t>& CustomerFilterDto::getResellerTypes()
{
    return m_Reseller_types;
}

void CustomerFilterDto::setResellerTypes(const std::vector<utility::string_t>& value)
{
    m_Reseller_types = value;
    m_Reseller_typesIsSet = true;
}

bool CustomerFilterDto::resellerTypesIsSet() const
{
    return m_Reseller_typesIsSet;
}

void CustomerFilterDto::unsetReseller_types()
{
    m_Reseller_typesIsSet = false;
}
std::vector<int32_t>& CustomerFilterDto::getTags()
{
    return m_Tags;
}

void CustomerFilterDto::setTags(std::vector<int32_t> value)
{
    m_Tags = value;
    m_TagsIsSet = true;
}

bool CustomerFilterDto::tagsIsSet() const
{
    return m_TagsIsSet;
}

void CustomerFilterDto::unsetTags()
{
    m_TagsIsSet = false;
}
utility::string_t CustomerFilterDto::getStartCharacter() const
{
    return m_Start_character;
}

void CustomerFilterDto::setStartCharacter(const utility::string_t& value)
{
    m_Start_character = value;
    m_Start_characterIsSet = true;
}

bool CustomerFilterDto::startCharacterIsSet() const
{
    return m_Start_characterIsSet;
}

void CustomerFilterDto::unsetStart_character()
{
    m_Start_characterIsSet = false;
}
std::shared_ptr<SortTypeDto> CustomerFilterDto::getSortType() const
{
    return m_Sort_type;
}

void CustomerFilterDto::setSortType(const std::shared_ptr<SortTypeDto>& value)
{
    m_Sort_type = value;
    m_Sort_typeIsSet = true;
}

bool CustomerFilterDto::sortTypeIsSet() const
{
    return m_Sort_typeIsSet;
}

void CustomerFilterDto::unsetSort_type()
{
    m_Sort_typeIsSet = false;
}
bool CustomerFilterDto::isDescending() const
{
    return m_Descending;
}

void CustomerFilterDto::setDescending(bool value)
{
    m_Descending = value;
    m_DescendingIsSet = true;
}

bool CustomerFilterDto::descendingIsSet() const
{
    return m_DescendingIsSet;
}

void CustomerFilterDto::unsetDescending()
{
    m_DescendingIsSet = false;
}
}
}
}
}


