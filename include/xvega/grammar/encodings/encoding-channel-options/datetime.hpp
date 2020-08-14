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

namespace nl = nlohmann;

namespace xv
{

    using stringNumType = xtl::variant<double, int, std::string>;

    struct DateTime : public xp::xobserved<DateTime>
    {
        XPROPERTY(xtl::xoptional<double>, DateTime, year);
        XPROPERTY(xtl::xoptional<double>, DateTime, quarter);
        XPROPERTY(xtl::xoptional<stringNumType>, DateTime, month);
        XPROPERTY(xtl::xoptional<double>, DateTime, date);
        XPROPERTY(xtl::xoptional<stringNumType>, DateTime, day);
        XPROPERTY(xtl::xoptional<double>, DateTime, hours);
        XPROPERTY(xtl::xoptional<double>, DateTime, minutes);
        XPROPERTY(xtl::xoptional<double>, DateTime, seconds);
        XPROPERTY(xtl::xoptional<double>, DateTime, milliseconds);
        XPROPERTY(xtl::xoptional<bool>, DateTime, utc); // Present in Altair Docs, but not in Vega-Lite Docs
    };

    void to_json(nl::json& j, const DateTime& data)
    {
        if(data.year().has_value())
        {
            j["year"] = data.year().value();
        }
        if(data.quarter().has_value())
        {
            j["quarter"] = data.quarter().value();
        }
        if(data.month().has_value())
        {
            j["month"] = data.month().value();
        }
        if(data.date().has_value())
        {
            j["date"] = data.date().value();
        }
        if(data.day().has_value())
        {
            j["day"] = data.day().value();
        }
        if(data.hours().has_value())
        {
            j["hours"] = data.hours().value();
        }
        if(data.minutes().has_value())
        {
            j["minutes"] = data.minutes().value();
        }
        if(data.seconds().has_value())
        {
            j["seconds"] = data.seconds().value();
        }
        if(data.milliseconds().has_value())
        {
            j["milliseconds"] = data.milliseconds().value();
        }
        if(data.utc().has_value())
        {
            j["utc"] = data.utc().value();
        }
    }
}

#endif