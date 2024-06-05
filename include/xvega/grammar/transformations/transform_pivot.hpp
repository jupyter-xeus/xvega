// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_PIVOT_HPP
#define XVEGA_TRANSFORM_PIVOT_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../transformations.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_pivot : public transformation<transform_pivot>
    {
        XPROPERTY(std::optional<std::string>, transform_pivot, pivot);
        XPROPERTY(std::optional<std::string>, transform_pivot, value);
        XPROPERTY(std::optional<std::vector<std::string>>, transform_pivot, groupby);
        XPROPERTY(std::optional<double>, transform_pivot, limit);
        XPROPERTY(std::optional<std::string>, transform_pivot, op);
    };

    XVEGA_API void to_json(nl::json& j, const transform_pivot& data);
}

#endif
