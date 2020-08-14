#ifndef XVEGA_ENCODING_OPTIONS_AGGREGATE_HPP
#define XVEGA_ENCODING_OPTIONS_AGGREGATE_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

namespace nl = nlohmann;

namespace xv
{
    struct Aggregate : public xp::xobserved<Aggregate>
    {
        XPROPERTY(xtl::xoptional<std::string>, Aggregate, argmax);
        XPROPERTY(xtl::xoptional<std::string>, Aggregate, argmin);
    };

    void to_json(nl::json& j, const Aggregate& data)
    {
        if(data.argmax().has_value())
        {
            j["argmax"] = data.argmax().value();
        }
        if(data.argmin().has_value())
        {
            j["argmin"] = data.argmin().value();
        }
    }

    using aggType = xtl::variant<Aggregate, std::string>;
}

#endif