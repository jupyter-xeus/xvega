// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_TIMEUNIT_HPP
#define XVEGA_ENCODING_OPTIONS_TIMEUNIT_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../../utils/serialize.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct TimeUnit : public xp::xobserved<TimeUnit>
    {
        XPROPERTY(xtl::xoptional<std::string>, TimeUnit, unit);
        XPROPERTY(xtl::xoptional<double>, TimeUnit, maxbins);
        XPROPERTY(xtl::xoptional<double>, TimeUnit, step);
        XPROPERTY(xtl::xoptional<bool>, TimeUnit, utc);
    };

    void to_json(nl::json& j, const TimeUnit& data);

    using time_unit_type = xtl::variant<std::string, TimeUnit>;
}

#endif