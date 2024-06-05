// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_TIMEUNIT_HPP
#define XVEGA_ENCODING_OPTIONS_TIMEUNIT_HPP

#include <optional>
#include <variant>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct TimeUnit : public xp::xobserved<TimeUnit>
    {
        XPROPERTY(std::optional<std::string>, TimeUnit, unit);
        XPROPERTY(std::optional<double>, TimeUnit, maxbins);
        XPROPERTY(std::optional<double>, TimeUnit, step);
        XPROPERTY(std::optional<bool>, TimeUnit, utc);
    };

    XVEGA_API void to_json(nl::json& j, const TimeUnit& data);

    using time_unit_type = std::variant<std::string, TimeUnit>;
}

#endif
