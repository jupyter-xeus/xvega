// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_SHAPE_HPP
#define XVEGA_ENCODING_SHAPE_HPP

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
    struct Shape : public xp::xobserved<Shape>
    {
        XPROPERTY(std::optional<agg_type>, Shape, aggregate);
        XPROPERTY(std::optional<bin_type>, Shape, bin);
        // XPROPERTY(std::optional<condition_type>, Shape, condition);
        XPROPERTY(std::optional<field_type>, Shape, field);
        XPROPERTY(std::optional<legend_type>, Shape, legend);
        XPROPERTY(std::optional<scale_type>, Shape, scale);
        XPROPERTY(std::optional<sort_type>, Shape, sort);
        XPROPERTY(std::optional<time_unit_type>, Shape, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Shape, title);
        XPROPERTY(std::optional<std::string>, Shape, type);
    };

    XVEGA_API void to_json(nl::json& j, const Shape& data);
}

#endif
