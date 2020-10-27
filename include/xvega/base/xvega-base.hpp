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
#include "../utils/serialize.hpp"
#include "../grammar/marks.hpp"
#include "../grammar/encodings.hpp"
#include "../grammar/selections.hpp"
#include "../grammar/config.hpp"

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

#include "../grammar/data/data_source/named_data.hpp"
#include "../grammar/data/data_source/inline_data.hpp"
#include "../grammar/data/data_source/url_data.hpp"
#include "../grammar/data/generator/sequence_generator.hpp"
#include "../grammar/data/generator/sphere_generator.hpp"
#include "../grammar/data/generator/graticule_generator.hpp"

#include "../grammar/transformations/transform_aggregate.hpp"
#include "../grammar/transformations/transform_bin.hpp"
#include "../grammar/transformations/transform_calculate.hpp"
#include "../grammar/transformations/transform_density.hpp"
#include "../grammar/transformations/transform_flatten.hpp"
#include "../grammar/transformations/transform_fold.hpp"
#include "../grammar/transformations/transform_impute.hpp"
#include "../grammar/transformations/transform_join_aggregate.hpp"
#include "../grammar/transformations/transform_loess.hpp"
#include "../grammar/transformations/transform_lookup.hpp"
#include "../grammar/transformations/transform_pivot.hpp"
#include "../grammar/transformations/transform_quantile.hpp"
#include "../grammar/transformations/transform_regression.hpp"
#include "../grammar/transformations/transform_sample.hpp"
#include "../grammar/transformations/transform_stack.hpp"
#include "../grammar/transformations/transform_timeunit.hpp"
#include "../grammar/transformations/transform_window.hpp"

namespace nl = nlohmann;

namespace xv
{
    using data_source = xtl::variant<
                             named_data, 
                             inline_data,
                             url_data
                             >;

    using generator = xtl::variant<
                           sequence_generator, 
                           sphere_generator,
                           graticule_generator
                           >;

    using data_type = xtl::variant<data_source, generator, data_frame>;

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

    using transform_type = xtl::variant<
                                transform_aggregate,
                                transform_bin,
                                transform_calculate,
                                transform_density,
                                transform_flatten,
                                transform_fold,
                                transform_impute,
                                transform_join_aggregate,
                                transform_loess,
                                transform_lookup,
                                transform_pivot,
                                transform_quantile,
                                transform_regression,
                                transform_sample,
                                transform_stack,
                                transform_timeunit,
                                transform_window
                                >;

    struct Chart : public xp::xobserved<Chart>
    {
        XPROPERTY(data_type, Chart, data);
        XPROPERTY(marks_type, Chart, mark);
        XPROPERTY(xtl::xoptional<Encodings>, Chart, encoding);
        XPROPERTY(std::vector<selection_type>, Chart, selections);
        XPROPERTY(std::vector<transform_type>, Chart, transformations);
        XPROPERTY(xtl::xoptional<double>, Chart, width);
        XPROPERTY(xtl::xoptional<double>, Chart, height);
        XPROPERTY(xtl::xoptional<Config>, Chart, config);
    };

    XVEGA_API void to_json(nl::json& j, const Chart& data);
}

#endif
