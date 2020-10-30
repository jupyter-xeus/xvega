// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_LOOKUP_HPP
#define XVEGA_TRANSFORM_LOOKUP_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"

#include "../data/data_source/named_data.hpp"
#include "../data/data_source/inline_data.hpp"
#include "../data/data_source/url_data.hpp"
#include "../data/generator/sequence_generator.hpp"
#include "../data/generator/sphere_generator.hpp"
#include "../data/generator/graticule_generator.hpp"

#include "../selections/selection_single.hpp"
#include "../selections/selection_multi.hpp"
#include "../selections/selection_interval.hpp"

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

    using data_type_lookup = xtl::variant<data_source, generator>;

    struct lookup_data : public xp::xobserved<lookup_data>
    {
        XPROPERTY(xtl::xoptional<data_type_lookup>, lookup_data, data);
        XPROPERTY(xtl::xoptional<std::string>, lookup_data, key);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, lookup_data, fields);
    };

    XVEGA_API void to_json(nl::json& j, const lookup_data& data);

    using selection_type = xtl::variant<
                                selection_single, 
                                selection_multi, 
                                selection_interval
                                >;

    struct lookup_selection : public xp::xobserved<lookup_selection>
    {
        XPROPERTY(xtl::xoptional<selection_type>, lookup_selection, selection);
        XPROPERTY(xtl::xoptional<std::string>, lookup_selection, key);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, lookup_selection, fields);
    };

    XVEGA_API void to_json(nl::json& j, const lookup_selection& data);

    using from_type = xtl::variant<lookup_data, lookup_selection>;

    struct transform_lookup : public xp::xobserved<transform_lookup>
    {
        XPROPERTY(xtl::xoptional<std::string>, transform_lookup, lookup);
        XPROPERTY(xtl::xoptional<from_type>, transform_lookup, from);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_lookup, as);
        XPROPERTY(xtl::xoptional<std::string>, transform_lookup, default_val); // Cannot use "default" as it's reserved
    };

    XVEGA_API void to_json(nl::json& j, const transform_lookup& data);
}

#endif
