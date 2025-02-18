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



#include "SlasconeOpenApiClient/model/ProvisioningLimitationDto.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



ProvisioningLimitationDto::ProvisioningLimitationDto()
{
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_Description = utility::conversions::to_string_t("");
    m_DescriptionIsSet = false;
    m_Value = 0;
    m_ValueIsSet = false;
    m_Remaining = 0.0;
    m_RemainingIsSet = false;
    m_Consumption_reset_modeIsSet = false;
    m_Consumption_reset_period_days = 0;
    m_Consumption_reset_period_daysIsSet = false;
}

ProvisioningLimitationDto::~ProvisioningLimitationDto()
{
}

void ProvisioningLimitationDto::validate()
{
    // TODO: implement validation
}

web::json::value ProvisioningLimitationDto::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t(U("id"))] = ModelBase::toJson(m_Id);
    }
    if(m_NameIsSet)
    {
        val[utility::conversions::to_string_t(U("name"))] = ModelBase::toJson(m_Name);
    }
    if(m_DescriptionIsSet)
    {
        val[utility::conversions::to_string_t(U("description"))] = ModelBase::toJson(m_Description);
    }
    if(m_ValueIsSet)
    {
        val[utility::conversions::to_string_t(U("value"))] = ModelBase::toJson(m_Value);
    }
    if(m_RemainingIsSet)
    {
        val[utility::conversions::to_string_t(U("remaining"))] = ModelBase::toJson(m_Remaining);
    }
    if(m_Consumption_reset_modeIsSet)
    {
        val[utility::conversions::to_string_t(U("consumption_reset_mode"))] = ModelBase::toJson(m_Consumption_reset_mode);
    }
    if(m_Consumption_reset_period_daysIsSet)
    {
        val[utility::conversions::to_string_t(U("consumption_reset_period_days"))] = ModelBase::toJson(m_Consumption_reset_period_days);
    }

    return val;
}

bool ProvisioningLimitationDto::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("value"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("value")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setValue;
            ok &= ModelBase::fromJson(fieldValue, refVal_setValue);
            setValue(refVal_setValue);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("remaining"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("remaining")));
        if(!fieldValue.is_null())
        {
            double refVal_setRemaining;
            ok &= ModelBase::fromJson(fieldValue, refVal_setRemaining);
            setRemaining(refVal_setRemaining);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("consumption_reset_mode"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("consumption_reset_mode")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<ConsumptionResetPeriod> refVal_setConsumptionResetMode;
            ok &= ModelBase::fromJson(fieldValue, refVal_setConsumptionResetMode);
            setConsumptionResetMode(refVal_setConsumptionResetMode);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("consumption_reset_period_days"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("consumption_reset_period_days")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setConsumptionResetPeriodDays;
            ok &= ModelBase::fromJson(fieldValue, refVal_setConsumptionResetPeriodDays);
            setConsumptionResetPeriodDays(refVal_setConsumptionResetPeriodDays);
        }
    }
    return ok;
}

void ProvisioningLimitationDto::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("name")), m_Name));
    }
    if(m_DescriptionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("description")), m_Description));
    }
    if(m_ValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("value")), m_Value));
    }
    if(m_RemainingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("remaining")), m_Remaining));
    }
    if(m_Consumption_reset_modeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("consumption_reset_mode")), m_Consumption_reset_mode));
    }
    if(m_Consumption_reset_period_daysIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("consumption_reset_period_days")), m_Consumption_reset_period_days));
    }
}

bool ProvisioningLimitationDto::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("value"))))
    {
        int32_t refVal_setValue;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("value"))), refVal_setValue );
        setValue(refVal_setValue);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("remaining"))))
    {
        double refVal_setRemaining;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("remaining"))), refVal_setRemaining );
        setRemaining(refVal_setRemaining);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("consumption_reset_mode"))))
    {
        std::shared_ptr<ConsumptionResetPeriod> refVal_setConsumptionResetMode;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("consumption_reset_mode"))), refVal_setConsumptionResetMode );
        setConsumptionResetMode(refVal_setConsumptionResetMode);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("consumption_reset_period_days"))))
    {
        int32_t refVal_setConsumptionResetPeriodDays;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("consumption_reset_period_days"))), refVal_setConsumptionResetPeriodDays );
        setConsumptionResetPeriodDays(refVal_setConsumptionResetPeriodDays);
    }
    return ok;
}

utility::string_t ProvisioningLimitationDto::getId() const
{
    return m_Id;
}

void ProvisioningLimitationDto::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool ProvisioningLimitationDto::idIsSet() const
{
    return m_IdIsSet;
}

void ProvisioningLimitationDto::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t ProvisioningLimitationDto::getName() const
{
    return m_Name;
}

void ProvisioningLimitationDto::setName(const utility::string_t& value)
{
    m_Name = value;
    m_NameIsSet = true;
}

bool ProvisioningLimitationDto::nameIsSet() const
{
    return m_NameIsSet;
}

void ProvisioningLimitationDto::unsetName()
{
    m_NameIsSet = false;
}
utility::string_t ProvisioningLimitationDto::getDescription() const
{
    return m_Description;
}

void ProvisioningLimitationDto::setDescription(const utility::string_t& value)
{
    m_Description = value;
    m_DescriptionIsSet = true;
}

bool ProvisioningLimitationDto::descriptionIsSet() const
{
    return m_DescriptionIsSet;
}

void ProvisioningLimitationDto::unsetDescription()
{
    m_DescriptionIsSet = false;
}
int32_t ProvisioningLimitationDto::getValue() const
{
    return m_Value;
}

void ProvisioningLimitationDto::setValue(int32_t value)
{
    m_Value = value;
    m_ValueIsSet = true;
}

bool ProvisioningLimitationDto::valueIsSet() const
{
    return m_ValueIsSet;
}

void ProvisioningLimitationDto::unsetValue()
{
    m_ValueIsSet = false;
}
double ProvisioningLimitationDto::getRemaining() const
{
    return m_Remaining;
}

void ProvisioningLimitationDto::setRemaining(double value)
{
    m_Remaining = value;
    m_RemainingIsSet = true;
}

bool ProvisioningLimitationDto::remainingIsSet() const
{
    return m_RemainingIsSet;
}

void ProvisioningLimitationDto::unsetRemaining()
{
    m_RemainingIsSet = false;
}
std::shared_ptr<ConsumptionResetPeriod> ProvisioningLimitationDto::getConsumptionResetMode() const
{
    return m_Consumption_reset_mode;
}

void ProvisioningLimitationDto::setConsumptionResetMode(const std::shared_ptr<ConsumptionResetPeriod>& value)
{
    m_Consumption_reset_mode = value;
    m_Consumption_reset_modeIsSet = true;
}

bool ProvisioningLimitationDto::consumptionResetModeIsSet() const
{
    return m_Consumption_reset_modeIsSet;
}

void ProvisioningLimitationDto::unsetConsumption_reset_mode()
{
    m_Consumption_reset_modeIsSet = false;
}
int32_t ProvisioningLimitationDto::getConsumptionResetPeriodDays() const
{
    return m_Consumption_reset_period_days;
}

void ProvisioningLimitationDto::setConsumptionResetPeriodDays(int32_t value)
{
    m_Consumption_reset_period_days = value;
    m_Consumption_reset_period_daysIsSet = true;
}

bool ProvisioningLimitationDto::consumptionResetPeriodDaysIsSet() const
{
    return m_Consumption_reset_period_daysIsSet;
}

void ProvisioningLimitationDto::unsetConsumption_reset_period_days()
{
    m_Consumption_reset_period_daysIsSet = false;
}
}
}
}
}


