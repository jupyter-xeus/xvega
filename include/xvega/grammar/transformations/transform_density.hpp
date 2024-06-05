// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_DENSITY_HPP
#define XVEGA_TRANSFORM_DENSITY_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../transformations.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_density : public transformation<transform_density>
    {
        XPROPERTY(std::optional<std::string>, transform_density, density);
        XPROPERTY(std::optional<std::vector<std::string>>, transform_density, groupby);
        XPROPERTY(std::optional<bool>, transform_density, cumulative);
        XPROPERTY(std::optional<bool>, transform_density, counts);
        XPROPERTY(std::optional<double>, transform_density, bandwidth);
        XPROPERTY(std::optional<std::vector<double>>, transform_density, extent);
        XPROPERTY(std::optional<double>, transform_density, minsteps);
        XPROPERTY(std::optional<double>, transform_density, maxsteps);
        XPROPERTY(std::optional<double>, transform_density, steps);
        XPROPERTY(std::optional<std::vector<std::string>>, transform_density, as);
    };

    XVEGA_API void to_json(nl::json& j, const transform_density& data);
}

#endif
