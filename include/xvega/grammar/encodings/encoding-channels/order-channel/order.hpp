// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_ORDER_HPP
#define XVEGA_ENCODING_ORDER_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/timeunit.hpp"
#include "../../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Order : public xp::xobserved<Order>
    {
        XPROPERTY(std::optional<agg_type>, Order, aggregate);
        XPROPERTY(std::optional<bin_type>, Order, bin);
        XPROPERTY(std::optional<field_type>, Order, field);
        XPROPERTY(std::optional<sort_type>, Order, sort);
        XPROPERTY(std::optional<time_unit_type>, Order, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Order, title);
        XPROPERTY(std::optional<std::string>, Order, type);
    };

    XVEGA_API void to_json(nl::json& j, const Order& data);
}

#endif
