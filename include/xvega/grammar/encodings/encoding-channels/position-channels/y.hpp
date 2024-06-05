// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_Y_HPP
#define XVEGA_ENCODING_Y_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/axis.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/impute.hpp"
#include "../../encoding-channel-options/scale.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/stack.hpp"
#include "../../encoding-channel-options/timeunit.hpp"
#include "../../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Y : public xp::xobserved<Y>
    {
        XPROPERTY(std::optional<agg_type>, Y, aggregate);
        XPROPERTY(std::optional<axis_type>, Y, axis);
        XPROPERTY(std::optional<double>, Y, band);
        XPROPERTY(std::optional<bin_type>, Y, bin);
        XPROPERTY(std::optional<field_type>, Y, field);
        XPROPERTY(std::optional<impute_type>, Y, impute);
        XPROPERTY(std::optional<scale_type>, Y, scale);
        XPROPERTY(std::optional<sort_type>, Y, sort);
        XPROPERTY(std::optional<stack_type>, Y, stack);
        XPROPERTY(std::optional<time_unit_type>, Y, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Y, title);
        XPROPERTY(std::optional<std::string>, Y, type);
    };

    XVEGA_API void to_json(nl::json& j, const Y& data);
}

#endif
