#ifndef XVEGA_ENCODING_OPTIONS_VALUE_HPP
#define XVEGA_ENCODING_OPTIONS_VALUE_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

namespace nl = nlohmann;

namespace xv
{
    using anyType = xtl::variant<std::string, bool, double, int, std::nullptr_t>;

    struct Value
    {
        xtl::xoptional<anyType> value;

        Value(anyType val)
        {
            value = val;
        }
    };

    void to_json(nl::json& j, const Value& data)
    {
        if(data.value.has_value())
        {
            j["value"] = data.value.value();
        }
    }
}

#endif