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

/*
 * CustomerFilterDto.h
 *
 * 
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_CustomerFilterDto_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_CustomerFilterDto_H_


#include "SlasconeOpenApiClient/ModelBase.h"

#include "SlasconeOpenApiClient/model/SortTypeDto.h"
#include <cpprest/details/basic_types.h>
#include <vector>

namespace org {
namespace openapitools {
namespace client {
namespace model {



/// <summary>
/// 
/// </summary>
class  CustomerFilterDto
    : public ModelBase
{
public:
    CustomerFilterDto();
    virtual ~CustomerFilterDto();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// CustomerFilterDto members

    /// <summary>
    /// 
    /// </summary>
    int32_t getPage() const;
    bool pageIsSet() const;
    void unsetPage();

    void setPage(int32_t value);

    /// <summary>
    /// 
    /// </summary>
    int32_t getPageSize() const;
    bool pageSizeIsSet() const;
    void unsetPage_size();

    void setPageSize(int32_t value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getSearchText() const;
    bool searchTextIsSet() const;
    void unsetSearch_text();

    void setSearchText(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getPlzQuery() const;
    bool plzQueryIsSet() const;
    void unsetPlz_query();

    void setPlzQuery(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::vector<utility::string_t>& getCustomerTypes();
    bool customerTypesIsSet() const;
    void unsetCustomer_types();

    void setCustomerTypes(const std::vector<utility::string_t>& value);

    /// <summary>
    /// 
    /// </summary>
    std::vector<utility::string_t>& getResellerTypes();
    bool resellerTypesIsSet() const;
    void unsetReseller_types();

    void setResellerTypes(const std::vector<utility::string_t>& value);

    /// <summary>
    /// 
    /// </summary>
    std::vector<int32_t>& getTags();
    bool tagsIsSet() const;
    void unsetTags();

    void setTags(std::vector<int32_t> value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getStartCharacter() const;
    bool startCharacterIsSet() const;
    void unsetStart_character();

    void setStartCharacter(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<SortTypeDto> getSortType() const;
    bool sortTypeIsSet() const;
    void unsetSort_type();

    void setSortType(const std::shared_ptr<SortTypeDto>& value);

    /// <summary>
    /// 
    /// </summary>
    bool isDescending() const;
    bool descendingIsSet() const;
    void unsetDescending();

    void setDescending(bool value);


protected:
    int32_t m_Page;
    bool m_PageIsSet;
    int32_t m_Page_size;
    bool m_Page_sizeIsSet;
    utility::string_t m_Search_text;
    bool m_Search_textIsSet;
    utility::string_t m_Plz_query;
    bool m_Plz_queryIsSet;
    std::vector<utility::string_t> m_Customer_types;
    bool m_Customer_typesIsSet;
    std::vector<utility::string_t> m_Reseller_types;
    bool m_Reseller_typesIsSet;
    std::vector<int32_t> m_Tags;
    bool m_TagsIsSet;
    utility::string_t m_Start_character;
    bool m_Start_characterIsSet;
    std::shared_ptr<SortTypeDto> m_Sort_type;
    bool m_Sort_typeIsSet;
    bool m_Descending;
    bool m_DescendingIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_CustomerFilterDto_H_ */
