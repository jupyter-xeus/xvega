// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_STROKE_OPACITY_HPP
#define XVEGA_ENCODING_STROKE_OPACITY_HPP

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
    struct StrokeOpacity : public xp::xobserved<StrokeOpacity>
    {
        XPROPERTY(std::optional<agg_type>, StrokeOpacity, aggregate);
        XPROPERTY(std::optional<bin_type>, StrokeOpacity, bin);
        // XPROPERTY(std::optional<condition_type>, StrokeOpacity, condition);
        XPROPERTY(std::optional<field_type>, StrokeOpacity, field);
        XPROPERTY(std::optional<legend_type>, StrokeOpacity, legend);
        XPROPERTY(std::optional<scale_type>, StrokeOpacity, scale);
        XPROPERTY(std::optional<sort_type>, StrokeOpacity, sort);
        XPROPERTY(std::optional<time_unit_type>, StrokeOpacity, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, StrokeOpacity, title);
        XPROPERTY(std::optional<std::string>, StrokeOpacity, type);
    };

    XVEGA_API void to_json(nl::json& j, const StrokeOpacity& data);
}

#endif
