// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BASIC_HPP
#define XVEGA_BASIC_HPP

#include "../utils/custom_datatypes.hpp"
#include "../grammar/marks.hpp"
#include "../grammar/encodings.hpp"
#include <iostream>

#include "../grammar/marks/mark_arc.hpp"
#include "../grammar/marks/mark_area.hpp"
#include "../grammar/marks/mark_bar.hpp"
#include "../grammar/marks/mark_circle.hpp"
#include "../grammar/marks/mark_geoshape.hpp"
#include "../grammar/marks/mark_image.hpp"
#include "../grammar/marks/mark_line.hpp"
#include "../grammar/marks/mark_point.hpp"
#include "../grammar/marks/mark_rect.hpp"
#include "../grammar/marks/mark_rule.hpp"
#include "../grammar/marks/mark_square.hpp"
#include "../grammar/marks/mark_text.hpp"
#include "../grammar/marks/mark_tick.hpp"
#include "../grammar/marks/mark_trail.hpp"

namespace nl = nlohmann;

namespace xv
{
    using marks_type = xtl::variant<
                            mark_arc, 
                            mark_area, 
                            mark_bar, 
                            mark_circle, 
                            mark_geoshape, 
                            mark_image, 
                            mark_line, 
                            mark_point, 
                            mark_rect, 
                            mark_rule, 
                            mark_square, 
                            mark_text, 
                            mark_tick, 
                            mark_trail
                            >;

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
        XPROPERTY(std::vector<marks_type>, Chart, marks);
        XPROPERTY(std::vector<Encodings>, Chart, encodings);
        XPROPERTY(xtl::xoptional<double>, Chart, width);
        XPROPERTY(xtl::xoptional<double>, Chart, height);
    };
}

#endif