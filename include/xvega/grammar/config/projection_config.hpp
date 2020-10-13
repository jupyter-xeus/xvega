// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_PROJECTION_CONFIG_HPP
#define XVEGA_PROJECTION_CONFIG_HPP

#include "../../xvega_config.hpp"
#include "xproperty/xobserved.hpp"
#include "../../utils/xeither.hpp"
#include "../../utils/custom_datatypes.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    struct projection_config : public xp::xobserved<projection_config>
    {
        XPROPERTY(xtl::xoptional<std::vector<double>>, projection_config, center);
        XPROPERTY(xtl::xoptional<double>, projection_config, clipAngle);
        XPROPERTY(xtl::xoptional<std::vector<double>>, projection_config, clipExtent);
        XPROPERTY(xtl::xoptional<double>, projection_config, coefficient);
        XPROPERTY(xtl::xoptional<double>, projection_config, distance);
        XPROPERTY(xtl::xoptional<std::vector<double>>, projection_config, extent);
        XPROPERTY(xtl::xoptional<std::vector<any_type>>, projection_config, fit);
        XPROPERTY(xtl::xoptional<double>, projection_config, fraction);
        XPROPERTY(xtl::xoptional<double>, projection_config, lobes);
        XPROPERTY(xtl::xoptional<double>, projection_config, parallel);
        XPROPERTY(xtl::xoptional<std::vector<double>>, projection_config, parallels);
        XPROPERTY(xtl::xoptional<double>, projection_config, pointRadius);
        XPROPERTY(xtl::xoptional<double>, projection_config, precision);
        XPROPERTY(xtl::xoptional<double>, projection_config, radius);
        XPROPERTY(xtl::xoptional<double>, projection_config, ratio);
        XPROPERTY(xtl::xoptional<bool>, projection_config, reflectX);
        XPROPERTY(xtl::xoptional<bool>, projection_config, reflectY);
        XPROPERTY(xtl::xoptional<std::vector<double>>, projection_config, rotate);
        XPROPERTY(xtl::xoptional<double>, projection_config, scale);
        XPROPERTY(xtl::xoptional<std::vector<double>>, projection_config, size);
        XPROPERTY(xtl::xoptional<double>, projection_config, spacing);
        XPROPERTY(xtl::xoptional<double>, projection_config, tilt);
        XPROPERTY(xtl::xoptional<std::vector<double>>, projection_config, translate);
        XPROPERTY(xtl::xoptional<std::string>, projection_config, type);
    };

    XVEGA_API void to_json(nl::json& j, const projection_config& data);
}

#endif
