// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_TIMEUNIT_HPP
#define XVEGA_TRANSFORM_TIMEUNIT_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../transformations.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_timeunit : public transformation<transform_timeunit>
    {
        XPROPERTY(std::optional<std::string>, transform_timeunit, field);
        XPROPERTY(std::optional<std::string>, transform_timeunit, as);
        XPROPERTY(std::optional<std::string>, transform_timeunit, timeUnit);
    };

    XVEGA_API void to_json(nl::json& j, const transform_timeunit& data);
}

#endif
