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



#include "SlasconeOpenApiClient/model/ProblemDetails.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



ProblemDetails::ProblemDetails()
{
    m_Type = utility::conversions::to_string_t("");
    m_TypeIsSet = false;
    m_Title = utility::conversions::to_string_t("");
    m_TitleIsSet = false;
    m_Status = 0;
    m_StatusIsSet = false;
    m_Detail = utility::conversions::to_string_t("");
    m_DetailIsSet = false;
    m_Instance = utility::conversions::to_string_t("");
    m_InstanceIsSet = false;
}

ProblemDetails::~ProblemDetails()
{
}

void ProblemDetails::validate()
{
    // TODO: implement validation
}

web::json::value ProblemDetails::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_TypeIsSet)
    {
        val[utility::conversions::to_string_t(U("type"))] = ModelBase::toJson(m_Type);
    }
    if(m_TitleIsSet)
    {
        val[utility::conversions::to_string_t(U("title"))] = ModelBase::toJson(m_Title);
    }
    if(m_StatusIsSet)
    {
        val[utility::conversions::to_string_t(U("status"))] = ModelBase::toJson(m_Status);
    }
    if(m_DetailIsSet)
    {
        val[utility::conversions::to_string_t(U("detail"))] = ModelBase::toJson(m_Detail);
    }
    if(m_InstanceIsSet)
    {
        val[utility::conversions::to_string_t(U("instance"))] = ModelBase::toJson(m_Instance);
    }

    return val;
}

bool ProblemDetails::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("type"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("type")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setType;
            ok &= ModelBase::fromJson(fieldValue, refVal_setType);
            setType(refVal_setType);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("title"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("title")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setTitle;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTitle);
            setTitle(refVal_setTitle);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("status"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("status")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setStatus;
            ok &= ModelBase::fromJson(fieldValue, refVal_setStatus);
            setStatus(refVal_setStatus);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("detail"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("detail")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setDetail;
            ok &= ModelBase::fromJson(fieldValue, refVal_setDetail);
            setDetail(refVal_setDetail);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("instance"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("instance")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setInstance;
            ok &= ModelBase::fromJson(fieldValue, refVal_setInstance);
            setInstance(refVal_setInstance);
        }
    }
    return ok;
}

void ProblemDetails::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("type")), m_Type));
    }
    if(m_TitleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("title")), m_Title));
    }
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("status")), m_Status));
    }
    if(m_DetailIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("detail")), m_Detail));
    }
    if(m_InstanceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("instance")), m_Instance));
    }
}

bool ProblemDetails::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("type"))))
    {
        utility::string_t refVal_setType;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("type"))), refVal_setType );
        setType(refVal_setType);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("title"))))
    {
        utility::string_t refVal_setTitle;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("title"))), refVal_setTitle );
        setTitle(refVal_setTitle);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("status"))))
    {
        int32_t refVal_setStatus;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("status"))), refVal_setStatus );
        setStatus(refVal_setStatus);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("detail"))))
    {
        utility::string_t refVal_setDetail;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("detail"))), refVal_setDetail );
        setDetail(refVal_setDetail);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("instance"))))
    {
        utility::string_t refVal_setInstance;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("instance"))), refVal_setInstance );
        setInstance(refVal_setInstance);
    }
    return ok;
}

utility::string_t ProblemDetails::getType() const
{
    return m_Type;
}

void ProblemDetails::setType(const utility::string_t& value)
{
    m_Type = value;
    m_TypeIsSet = true;
}

bool ProblemDetails::typeIsSet() const
{
    return m_TypeIsSet;
}

void ProblemDetails::unsetType()
{
    m_TypeIsSet = false;
}
utility::string_t ProblemDetails::getTitle() const
{
    return m_Title;
}

void ProblemDetails::setTitle(const utility::string_t& value)
{
    m_Title = value;
    m_TitleIsSet = true;
}

bool ProblemDetails::titleIsSet() const
{
    return m_TitleIsSet;
}

void ProblemDetails::unsetTitle()
{
    m_TitleIsSet = false;
}
int32_t ProblemDetails::getStatus() const
{
    return m_Status;
}

void ProblemDetails::setStatus(int32_t value)
{
    m_Status = value;
    m_StatusIsSet = true;
}

bool ProblemDetails::statusIsSet() const
{
    return m_StatusIsSet;
}

void ProblemDetails::unsetStatus()
{
    m_StatusIsSet = false;
}
utility::string_t ProblemDetails::getDetail() const
{
    return m_Detail;
}

void ProblemDetails::setDetail(const utility::string_t& value)
{
    m_Detail = value;
    m_DetailIsSet = true;
}

bool ProblemDetails::detailIsSet() const
{
    return m_DetailIsSet;
}

void ProblemDetails::unsetDetail()
{
    m_DetailIsSet = false;
}
utility::string_t ProblemDetails::getInstance() const
{
    return m_Instance;
}

void ProblemDetails::setInstance(const utility::string_t& value)
{
    m_Instance = value;
    m_InstanceIsSet = true;
}

bool ProblemDetails::instanceIsSet() const
{
    return m_InstanceIsSet;
}

void ProblemDetails::unsetInstance()
{
    m_InstanceIsSet = false;
}
}
}
}
}


