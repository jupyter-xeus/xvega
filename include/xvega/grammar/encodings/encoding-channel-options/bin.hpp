#ifndef XVEGA_ENCODING_OPTIONS_BIN_HPP
#define XVEGA_ENCODING_OPTIONS_BIN_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

namespace nl = nlohmann;

namespace xv
{
    struct Bin : public xp::xobserved<Bin>
    {
        XPROPERTY(xtl::xoptional<double>, Bin, anchor);
        XPROPERTY(xtl::xoptional<double>, Bin, base);
        XPROPERTY(xtl::xoptional<bool>, Bin, binned);
        XPROPERTY(xtl::xoptional<std::vector<double>>, Bin, divide);
        XPROPERTY(xtl::xoptional<std::vector<double>>, Bin, extent); // Need to confirm if it's a list of 2-element arrays OR just a 2 element tuple
        XPROPERTY(xtl::xoptional<double>, Bin, maxbins);
        XPROPERTY(xtl::xoptional<double>, Bin, minstep);
        XPROPERTY(xtl::xoptional<bool>, Bin, nice);
        XPROPERTY(xtl::xoptional<double>, Bin, step);
        XPROPERTY(xtl::xoptional<std::vector<double>>, Bin, steps);
    };

    void to_json(nl::json& j, const Bin& data)
    {
        if(data.anchor().has_value())
        {
            j["anchor"] = data.anchor().value();
        }
        if(data.base().has_value())
        {
            j["base"] = data.base().value();
        }
        if(data.binned().has_value())
        {
            j["binned"] = data.binned().value();
        }
        if(data.divide().has_value())
        {
            j["divide"] = data.divide().value();
        }
        if(data.extent().has_value())
        {
            j["extent"] = data.extent().value();
        }
        if(data.maxbins().has_value())
        {
            j["maxbins"] = data.maxbins().value();
        }
        if(data.minstep().has_value())
        {
            j["minstep"] = data.minstep().value();
        }
        if(data.nice().has_value())
        {
            j["nice"] = data.nice().value();
        }
        if(data.step().has_value())
        {
            j["step"] = data.step().value();
        }
        if(data.steps().has_value())
        {
            j["steps"] = data.steps().value();
        }
    }

    using binType = xtl::variant<bool, Bin, std::string, std::nullptr_t>;
}

#endif