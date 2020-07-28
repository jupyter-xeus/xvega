#ifndef XVEGA_BASIC_HPP
#define XVEGA_BASIC_HPP

#include "../utils/custom_datatypes.hpp"
#include "../grammar/marks.hpp"
#include "../grammar/encodings.hpp"
#include <iostream>

namespace nl = nlohmann;

namespace xv
{
    inline const nl::json& base_vegalite_json()
    {
        static const nl::json json_template = {
            { "$schema", "https://vega.github.io/schema/vega-lite/v4.json" },
        };
        return json_template;
    };

    auto json_template = base_vegalite_json();

    struct Chart : public xp::xobserved<Chart>
    {
        XPROPERTY(dataFrame, Chart, data);
        XPROPERTY(std::vector<Marks>, Chart, marks);
        XPROPERTY(std::vector<Encodings>, Chart, encodings);
        XPROPERTY(xtl::xoptional<double>, Chart, width);
        XPROPERTY(xtl::xoptional<double>, Chart, height);
    };
}

#endif