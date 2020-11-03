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
#include "../utils/any_serializable.hpp"

#include "../grammar/marks.hpp"
#include "../grammar/encodings.hpp"
#include "../grammar/selections.hpp"
#include "../grammar/transformations.hpp"
#include "../grammar/config.hpp"

#include "../grammar/data/data_source/named_data.hpp"
#include "../grammar/data/data_source/inline_data.hpp"
#include "../grammar/data/data_source/url_data.hpp"

#include "../grammar/data/generator/sequence_generator.hpp"
#include "../grammar/data/generator/sphere_generator.hpp"
#include "../grammar/data/generator/graticule_generator.hpp"

namespace nl = nlohmann;

namespace xv
{
    using data_source = xtl::variant<named_data, inline_data, url_data>;

    using generator = xtl::variant<
                           sequence_generator, 
                           sphere_generator,
                           graticule_generator
                           >;

    using data_type = xtl::variant<data_source, generator, data_frame>;
    using marks_type = xany_vega<mark>;
    using selection_type = xany_vega<selection>;
    using transform_type = xany_vega<transformation>;

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
