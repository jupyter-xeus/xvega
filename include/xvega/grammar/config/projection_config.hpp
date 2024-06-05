// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_PROJECTION_CONFIG_HPP
#define XVEGA_PROJECTION_CONFIG_HPP

#include <optional>

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    struct projection_config : public xp::xobserved<projection_config>
    {
        XPROPERTY(std::optional<std::vector<double>>, projection_config, center);
        XPROPERTY(std::optional<double>, projection_config, clipAngle);
        XPROPERTY(std::optional<std::vector<double>>, projection_config, clipExtent);
        XPROPERTY(std::optional<double>, projection_config, coefficient);
        XPROPERTY(std::optional<double>, projection_config, distance);
        XPROPERTY(std::optional<std::vector<double>>, projection_config, extent);
        XPROPERTY(std::optional<std::vector<any_type>>, projection_config, fit);
        XPROPERTY(std::optional<double>, projection_config, fraction);
        XPROPERTY(std::optional<double>, projection_config, lobes);
        XPROPERTY(std::optional<double>, projection_config, parallel);
        XPROPERTY(std::optional<std::vector<double>>, projection_config, parallels);
        XPROPERTY(std::optional<double>, projection_config, pointRadius);
        XPROPERTY(std::optional<double>, projection_config, precision);
        XPROPERTY(std::optional<double>, projection_config, radius);
        XPROPERTY(std::optional<double>, projection_config, ratio);
        XPROPERTY(std::optional<bool>, projection_config, reflectX);
        XPROPERTY(std::optional<bool>, projection_config, reflectY);
        XPROPERTY(std::optional<std::vector<double>>, projection_config, rotate);
        XPROPERTY(std::optional<double>, projection_config, scale);
        XPROPERTY(std::optional<std::vector<double>>, projection_config, size);
        XPROPERTY(std::optional<double>, projection_config, spacing);
        XPROPERTY(std::optional<double>, projection_config, tilt);
        XPROPERTY(std::optional<std::vector<double>>, projection_config, translate);
        XPROPERTY(std::optional<std::string>, projection_config, type);
    };

    XVEGA_API void to_json(nl::json& j, const projection_config& data);
}

#endif
