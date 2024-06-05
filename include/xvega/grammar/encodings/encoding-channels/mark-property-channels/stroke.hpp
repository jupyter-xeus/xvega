// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_STROKE_HPP
#define XVEGA_ENCODING_STROKE_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

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
    struct Stroke : public xp::xobserved<Stroke>
    {
        XPROPERTY(std::optional<agg_type>, Stroke, aggregate);
        XPROPERTY(std::optional<bin_type>, Stroke, bin);
        // XPROPERTY(std::optional<condition_type>, Stroke, condition);
        XPROPERTY(std::optional<field_type>, Stroke, field);
        XPROPERTY(std::optional<legend_type>, Stroke, legend);
        XPROPERTY(std::optional<scale_type>, Stroke, scale);
        XPROPERTY(std::optional<sort_type>, Stroke, sort);
        XPROPERTY(std::optional<time_unit_type>, Stroke, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Stroke, title);
        XPROPERTY(std::optional<std::string>, Stroke, type);
    };

    XVEGA_API void to_json(nl::json& j, const Stroke& data);
}

#endif
