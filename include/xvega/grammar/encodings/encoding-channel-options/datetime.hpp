// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_DATETIME_HPP
#define XVEGA_ENCODING_OPTIONS_DATETIME_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../../xvega_config.hpp"
#include "../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct DateTime : public xp::xobserved<DateTime>
    {
        XPROPERTY(std::optional<double>, DateTime, year);
        XPROPERTY(std::optional<double>, DateTime, quarter);
        XPROPERTY(std::optional<string_num_type>, DateTime, month);
        XPROPERTY(std::optional<double>, DateTime, date);
        XPROPERTY(std::optional<string_num_type>, DateTime, day);
        XPROPERTY(std::optional<double>, DateTime, hours);
        XPROPERTY(std::optional<double>, DateTime, minutes);
        XPROPERTY(std::optional<double>, DateTime, seconds);
        XPROPERTY(std::optional<double>, DateTime, milliseconds);
        XPROPERTY(std::optional<bool>, DateTime, utc); // Present in Altair Docs, but not in Vega-Lite Docs
    };

    XVEGA_API void to_json(nl::json& j, const DateTime& data);
}

#endif
