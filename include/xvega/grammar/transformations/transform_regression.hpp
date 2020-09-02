// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_REGRESSION_HPP
#define XVEGA_TRANSFORM_REGRESSION_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_regression : public xp::xobserved<transform_regression>
    {
        XPROPERTY(xtl::xoptional<std::string>, transform_regression, regression);
        XPROPERTY(xtl::xoptional<std::string>, transform_regression, on);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_regression, groupby);
        XPROPERTY(xtl::xoptional<std::string>, transform_regression, method);
        XPROPERTY(xtl::xoptional<double>, transform_regression, order);
        XPROPERTY(xtl::xoptional<std::vector<double>>, transform_regression, extent);
        XPROPERTY(xtl::xoptional<bool>, transform_regression, params);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_regression, as);
    };

    void to_json(nl::json& j, const transform_regression& data);
}

#endif