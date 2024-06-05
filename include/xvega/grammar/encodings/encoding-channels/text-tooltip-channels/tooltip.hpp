// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_TOOLTIP_HPP
#define XVEGA_ENCODING_TOOLTIP_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

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
        XPROPERTY(std::optional<agg_type>, Tooltip, aggregate);
        XPROPERTY(std::optional<bin_type>, Tooltip, bin);
        // XPROPERTY(std::optional<condition_type>, Tooltip, condition);
        XPROPERTY(std::optional<field_type>, Tooltip, field);
        XPROPERTY(std::optional<string_object_type>, Tooltip, format);
        XPROPERTY(std::optional<std::string>, Tooltip, formatType);
        XPROPERTY(std::optional<std::string>, Tooltip, labelExpr);
        XPROPERTY(std::optional<time_unit_type>, Tooltip, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Tooltip, title);
        XPROPERTY(std::optional<std::string>, Tooltip, type);
    };

    XVEGA_API void to_json(nl::json& j, const Tooltip& data);
}

#endif
