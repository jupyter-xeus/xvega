// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_REGRESSION_HPP
#define XVEGA_TRANSFORM_REGRESSION_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../transformations.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_regression : public transformation<transform_regression>
    {
        XPROPERTY(std::optional<std::string>, transform_regression, regression);
        XPROPERTY(std::optional<std::string>, transform_regression, on);
        XPROPERTY(std::optional<std::vector<std::string>>, transform_regression, groupby);
        XPROPERTY(std::optional<std::string>, transform_regression, method);
        XPROPERTY(std::optional<double>, transform_regression, order);
        XPROPERTY(std::optional<std::vector<double>>, transform_regression, extent);
        XPROPERTY(std::optional<bool>, transform_regression, params);
        XPROPERTY(std::optional<std::vector<std::string>>, transform_regression, as);
    };

    XVEGA_API void to_json(nl::json& j, const transform_regression& data);
}

#endif
