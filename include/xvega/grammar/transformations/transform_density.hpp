// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_DENSITY_HPP
#define XVEGA_TRANSFORM_DENSITY_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_density : public xp::xobserved<transform_density>
    {
        XPROPERTY(xtl::xoptional<std::string>, transform_density, density);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_density, groupby);
        XPROPERTY(xtl::xoptional<bool>, transform_density, cumulative);
        XPROPERTY(xtl::xoptional<bool>, transform_density, counts);
        XPROPERTY(xtl::xoptional<double>, transform_density, bandwidth);
        XPROPERTY(xtl::xoptional<std::vector<double>>, transform_density, extent);
        XPROPERTY(xtl::xoptional<double>, transform_density, minsteps);
        XPROPERTY(xtl::xoptional<double>, transform_density, maxsteps);
        XPROPERTY(xtl::xoptional<double>, transform_density, steps);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_density, as);
    };

    XVEGA_API void to_json(nl::json& j, const transform_density& data);
}

#endif