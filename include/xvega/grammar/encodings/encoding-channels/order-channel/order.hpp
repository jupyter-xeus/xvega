// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_ORDER_HPP
#define XVEGA_ENCODING_ORDER_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct Order : public xp::xobserved<Order>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Order, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, Order, bin);
        XPROPERTY(xtl::xoptional<field_type>, Order, field);
        XPROPERTY(xtl::xoptional<sort_type>, Order, sort);
        XPROPERTY(xtl::xoptional<time_unit_type>, Order, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Order, title);
        XPROPERTY(xtl::xoptional<std::string>, Order, type);
    };

    XVEGA_API void to_json(nl::json& j, const Order& data);
}

#endif