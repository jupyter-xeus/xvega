// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_STROKE_WIDTH_HPP
#define XVEGA_ENCODING_STROKE_WIDTH_HPP

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
    struct StrokeWidth : public xp::xobserved<StrokeWidth>
    {
        XPROPERTY(std::optional<agg_type>, StrokeWidth, aggregate);
        XPROPERTY(std::optional<bin_type>, StrokeWidth, bin);
        // XPROPERTY(std::optional<condition_type>, StrokeWidth, condition);
        XPROPERTY(std::optional<field_type>, StrokeWidth, field);
        XPROPERTY(std::optional<legend_type>, StrokeWidth, legend);
        XPROPERTY(std::optional<scale_type>, StrokeWidth, scale);
        XPROPERTY(std::optional<sort_type>, StrokeWidth, sort);
        XPROPERTY(std::optional<time_unit_type>, StrokeWidth, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, StrokeWidth, title);
        XPROPERTY(std::optional<std::string>, StrokeWidth, type);
    };

    XVEGA_API void to_json(nl::json& j, const StrokeWidth& data);
}

#endif
