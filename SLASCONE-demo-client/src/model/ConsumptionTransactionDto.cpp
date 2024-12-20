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



#include "SlasconeOpenApiClient/model/ConsumptionTransactionDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



ConsumptionTransactionDto::ConsumptionTransactionDto()
{
    m_Limitation_id = utility::conversions::to_string_t("");
    m_Limitation_idIsSet = false;
    m_Transaction_id = utility::conversions::to_string_t("");
    m_Transaction_idIsSet = false;
}

ConsumptionTransactionDto::~ConsumptionTransactionDto()
{
}

void ConsumptionTransactionDto::validate()
{
    // TODO: implement validation
}

web::json::value ConsumptionTransactionDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_Limitation_idIsSet)
    {
        val[utility::conversions::to_string_t(U("limitation_id"))] = ModelBase::toJson(m_Limitation_id);
    }
    if(m_Transaction_idIsSet)
    {
        val[utility::conversions::to_string_t(U("transaction_id"))] = ModelBase::toJson(m_Transaction_id);
    }

    return val;
}

bool ConsumptionTransactionDto::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("limitation_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("limitation_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLimitationId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLimitationId);
            setLimitationId(refVal_setLimitationId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("transaction_id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("transaction_id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setTransactionId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTransactionId);
            setTransactionId(refVal_setTransactionId);
        }
    }
    return ok;
}

void ConsumptionTransactionDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_Limitation_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("limitation_id")), m_Limitation_id));
    }
    if(m_Transaction_idIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("transaction_id")), m_Transaction_id));
    }
}

bool ConsumptionTransactionDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("limitation_id"))))
    {
        utility::string_t refVal_setLimitationId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("limitation_id"))), refVal_setLimitationId );
        setLimitationId(refVal_setLimitationId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("transaction_id"))))
    {
        utility::string_t refVal_setTransactionId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("transaction_id"))), refVal_setTransactionId );
        setTransactionId(refVal_setTransactionId);
    }
    return ok;
}

utility::string_t ConsumptionTransactionDto::getLimitationId() const
{
    return m_Limitation_id;
}

void ConsumptionTransactionDto::setLimitationId(const utility::string_t& value)
{
    m_Limitation_id = value;
    m_Limitation_idIsSet = true;
}

bool ConsumptionTransactionDto::limitationIdIsSet() const
{
    return m_Limitation_idIsSet;
}

void ConsumptionTransactionDto::unsetLimitation_id()
{
    m_Limitation_idIsSet = false;
}
utility::string_t ConsumptionTransactionDto::getTransactionId() const
{
    return m_Transaction_id;
}

void ConsumptionTransactionDto::setTransactionId(const utility::string_t& value)
{
    m_Transaction_id = value;
    m_Transaction_idIsSet = true;
}

bool ConsumptionTransactionDto::transactionIdIsSet() const
{
    return m_Transaction_idIsSet;
}

void ConsumptionTransactionDto::unsetTransaction_id()
{
    m_Transaction_idIsSet = false;
}
}
}
}
}


