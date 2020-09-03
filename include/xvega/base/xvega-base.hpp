// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BASIC_HPP
#define XVEGA_BASIC_HPP

#include <iostream>

#include "../xvega_config.hpp"

#include "../utils/custom_datatypes.hpp"
#include "../grammar/marks.hpp"
#include "../grammar/encodings.hpp"
#include "../grammar/selections.hpp"

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

#include "../grammar/selections/selection_single.hpp"
#include "../grammar/selections/selection_multi.hpp"
#include "../grammar/selections/selection_interval.hpp"

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

    using selection_type = xtl::variant<
                                selection_single, 
                                selection_multi, 
                                selection_interval
                                >;

    const nl::json& base_vegalite_json();

    struct Chart : public xp::xobserved<Chart>
    {
        XPROPERTY(data_frame, Chart, data);
        XPROPERTY(std::vector<marks_type>, Chart, marks);
        XPROPERTY(std::vector<Encodings>, Chart, encodings);
        XPROPERTY(std::vector<selection_type>, Chart, selections); // matrix
        XPROPERTY(xtl::xoptional<double>, Chart, width);
        XPROPERTY(xtl::xoptional<double>, Chart, height);
    };
}

#endif