// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_GRATICULE_GENERATOR_HPP
#define XVEGA_GRATICULE_GENERATOR_HPP

#include <optional>
#include <variant>

#include "xproperty/xobserved.hpp"

#include "nlohmann/json.hpp"

#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct graticule_params : public xp::xobserved<graticule_params>
    {
        XPROPERTY(std::optional<std::vector<double>>, graticule_params, extent);
        XPROPERTY(std::optional<std::vector<double>>, graticule_params, extentMajor);
        XPROPERTY(std::optional<std::vector<double>>, graticule_params, extentMinor);
        XPROPERTY(std::optional<double>, graticule_params, precision);
        XPROPERTY(std::optional<std::vector<double>>, graticule_params, step);
        XPROPERTY(std::optional<std::vector<double>>, graticule_params, stepMajor);
        XPROPERTY(std::optional<std::vector<double>>, graticule_params, stepMinor);
    };

    XVEGA_API void to_json(nl::json& j, const graticule_params& data);

    using graticule_type = std::variant<bool, graticule_params>;

    struct graticule_generator : public xp::xobserved<graticule_generator>
    {
        XPROPERTY(std::optional<graticule_type>, graticule_generator, graticule);
        XPROPERTY(std::optional<std::string>, graticule_generator, name);
    };

    XVEGA_API void to_json(nl::json& j, const graticule_generator& data);
}

#endif
