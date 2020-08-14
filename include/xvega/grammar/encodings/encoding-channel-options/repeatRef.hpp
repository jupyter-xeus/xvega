#ifndef XVEGA_ENCODING_OPTIONS_REPEATREF_HPP
#define XVEGA_ENCODING_OPTIONS_REPEATREF_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

namespace nl = nlohmann;

namespace xv
{
    struct RepeatRef : public xp::xobserved<RepeatRef>
    {
        XPROPERTY(xtl::xoptional<std::string>, RepeatRef, repeat);
    };

    void to_json(nl::json& j, const RepeatRef& data)
    {
        if(data.repeat().has_value())
        {
            j["repeat"] = data.repeat().value();
        }
    }
}

#endif