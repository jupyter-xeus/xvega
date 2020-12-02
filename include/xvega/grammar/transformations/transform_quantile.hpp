// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_QUANTILE_HPP
#define XVEGA_TRANSFORM_QUANTILE_HPP

#include <xproperty/xobserved.hpp>

#include <xtl/xoptional.hpp>
#include <xtl/xjson.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../transformations.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_quantile : public transformation<transform_quantile>
    {
        XPROPERTY(xtl::xoptional<std::string>, transform_quantile, quantile);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_quantile, groupby);
        XPROPERTY(xtl::xoptional<std::vector<double>>, transform_quantile, probs);
        XPROPERTY(xtl::xoptional<double>, transform_quantile, step);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_quantile, as);
    };

    XVEGA_API void to_json(nl::json& j, const transform_quantile& data);
}

#endif