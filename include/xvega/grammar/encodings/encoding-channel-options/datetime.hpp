// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_DATETIME_HPP
#define XVEGA_ENCODING_OPTIONS_DATETIME_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_num_type = xtl::variant<double, int, std::string>;

    struct DateTime : public xp::xobserved<DateTime>
    {
        XPROPERTY(xtl::xoptional<double>, DateTime, year);
        XPROPERTY(xtl::xoptional<double>, DateTime, quarter);
        XPROPERTY(xtl::xoptional<string_num_type>, DateTime, month);
        XPROPERTY(xtl::xoptional<double>, DateTime, date);
        XPROPERTY(xtl::xoptional<string_num_type>, DateTime, day);
        XPROPERTY(xtl::xoptional<double>, DateTime, hours);
        XPROPERTY(xtl::xoptional<double>, DateTime, minutes);
        XPROPERTY(xtl::xoptional<double>, DateTime, seconds);
        XPROPERTY(xtl::xoptional<double>, DateTime, milliseconds);
        XPROPERTY(xtl::xoptional<bool>, DateTime, utc); // Present in Altair Docs, but not in Vega-Lite Docs
    };

    XVEGA_API void to_json(nl::json& j, const DateTime& data);
}

#endif