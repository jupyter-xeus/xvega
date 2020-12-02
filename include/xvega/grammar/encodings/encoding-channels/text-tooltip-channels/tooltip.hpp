// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_TOOLTIP_HPP
#define XVEGA_ENCODING_TOOLTIP_HPP

#include <xproperty/xobserved.hpp>

#include <xtl/xoptional.hpp>
#include <xtl/xjson.hpp>

#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/timeunit.hpp"
#include "../../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Tooltip : public xp::xobserved<Tooltip>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Tooltip, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, Tooltip, bin);
        // XPROPERTY(xtl::xoptional<condition_type>, Tooltip, condition);
        XPROPERTY(xtl::xoptional<field_type>, Tooltip, field);
        XPROPERTY(xtl::xoptional<string_object_type>, Tooltip, format);
        XPROPERTY(xtl::xoptional<std::string>, Tooltip, formatType);
        XPROPERTY(xtl::xoptional<std::string>, Tooltip, labelExpr);
        XPROPERTY(xtl::xoptional<time_unit_type>, Tooltip, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Tooltip, title);
        XPROPERTY(xtl::xoptional<std::string>, Tooltip, type);
    };

    XVEGA_API void to_json(nl::json& j, const Tooltip& data);
}

#endif