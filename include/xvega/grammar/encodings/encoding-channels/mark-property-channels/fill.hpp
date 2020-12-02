// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_FILL_HPP
#define XVEGA_ENCODING_FILL_HPP

#include <xproperty/xobserved.hpp>

#include <xtl/xoptional.hpp>
#include <xtl/xjson.hpp>

#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/legend.hpp"
#include "../../encoding-channel-options/scale.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/timeunit.hpp"
#include "../../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Fill : public xp::xobserved<Fill>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Fill, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, Fill, bin);
        // XPROPERTY(xtl::xoptional<condition_type>, Fill, condition);
        XPROPERTY(xtl::xoptional<field_type>, Fill, field);
        XPROPERTY(xtl::xoptional<legend_type>, Fill, legend);
        XPROPERTY(xtl::xoptional<scale_type>, Fill, scale);
        XPROPERTY(xtl::xoptional<sort_type>, Fill, sort);
        XPROPERTY(xtl::xoptional<time_unit_type>, Fill, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Fill, title);
        XPROPERTY(xtl::xoptional<std::string>, Fill, type);
    };

    XVEGA_API void to_json(nl::json& j, const Fill& data);
}

#endif