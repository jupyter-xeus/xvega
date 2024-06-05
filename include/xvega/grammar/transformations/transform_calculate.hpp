// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_CALCULATE_HPP
#define XVEGA_TRANSFORM_CALCULATE_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../transformations.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_calculate : public transformation<transform_calculate>
    {
        XPROPERTY(std::optional<std::string>, transform_calculate, calculate);
        XPROPERTY(std::optional<std::string>, transform_calculate, as);
    };

    XVEGA_API void to_json(nl::json& j, const transform_calculate& data);
}

#endif
