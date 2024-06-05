// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_LOOKUP_HPP
#define XVEGA_TRANSFORM_LOOKUP_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../utils/xany.hpp"
#include "../../xvega_config.hpp"
#include "../transformations.hpp"
#include "../selections.hpp"

#include "../data/data_source/named_data.hpp"
#include "../data/data_source/inline_data.hpp"
#include "../data/data_source/url_data.hpp"
#include "../data/generator/sequence_generator.hpp"
#include "../data/generator/sphere_generator.hpp"
#include "../data/generator/graticule_generator.hpp"

namespace nl = nlohmann;

namespace xv
{
    using data_source = std::variant<
                             named_data, 
                             inline_data,
                             url_data
                             >;

    using generator = std::variant<
                           sequence_generator, 
                           sphere_generator,
                           graticule_generator
                           >;

    using data_type_lookup = std::variant<data_source, generator>;

    struct lookup_data : public xp::xobserved<lookup_data>
    {
        XPROPERTY(std::optional<data_type_lookup>, lookup_data, data);
        XPROPERTY(std::optional<std::string>, lookup_data, key);
        XPROPERTY(std::optional<std::vector<std::string>>, lookup_data, fields);
    };

    XVEGA_API void to_json(nl::json& j, const lookup_data& data);

    using selection_type = xany<selection>;

    struct lookup_selection : public xp::xobserved<lookup_selection>
    {
        XPROPERTY(std::optional<selection_type>, lookup_selection, selection);
        XPROPERTY(std::optional<std::string>, lookup_selection, key);
        XPROPERTY(std::optional<std::vector<std::string>>, lookup_selection, fields);
    };

    XVEGA_API void to_json(nl::json& j, const lookup_selection& data);

    using from_type = std::variant<lookup_data, lookup_selection>;

    struct transform_lookup : public transformation<transform_lookup>
    {
        XPROPERTY(std::optional<std::string>, transform_lookup, lookup);
        XPROPERTY(std::optional<from_type>, transform_lookup, from);
        XPROPERTY(std::optional<std::vector<std::string>>, transform_lookup, as);
        XPROPERTY(std::optional<std::string>, transform_lookup, default_val); // Cannot use "default" as it's reserved
    };

    XVEGA_API void to_json(nl::json& j, const transform_lookup& data);
}

#endif
