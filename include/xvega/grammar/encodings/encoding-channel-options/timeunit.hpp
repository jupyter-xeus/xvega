#ifndef XVEGA_ENCODING_OPTIONS_TIMEUNIT_HPP
#define XVEGA_ENCODING_OPTIONS_TIMEUNIT_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

namespace nl = nlohmann;

namespace xv
{
    struct TimeUnit : public xp::xobserved<TimeUnit>
    {
        XPROPERTY(xtl::xoptional<std::string>, TimeUnit, unit);
        XPROPERTY(xtl::xoptional<double>, TimeUnit, maxbins);
        XPROPERTY(xtl::xoptional<double>, TimeUnit, step);
        XPROPERTY(xtl::xoptional<bool>, TimeUnit, utc);
    };

    void to_json(nl::json& j, const TimeUnit& data)
    {
        if(data.unit().has_value())
        {
            j["unit"] = data.unit().value();
        }
        if(data.maxbins().has_value())
        {
            j["maxbins"] = data.maxbins().value();
        }
        if(data.step().has_value())
        {
            j["step"] = data.step().value();
        }
        if(data.utc().has_value())
        {
            j["utc"] = data.utc().value();
        }
    }

    using timeUnitType = xtl::variant<std::string, TimeUnit>;
}

#endif