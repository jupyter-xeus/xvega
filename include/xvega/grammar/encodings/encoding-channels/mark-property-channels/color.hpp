// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_COLOR_HPP
#define XVEGA_ENCODING_COLOR_HPP

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
    struct Color : public xp::xobserved<Color>
    {
        XPROPERTY(std::optional<agg_type>, Color, aggregate);
        XPROPERTY(std::optional<bin_type>, Color, bin);
        // XPROPERTY(std::optional<condition_type>, Color, condition);
        XPROPERTY(std::optional<field_type>, Color, field);
        XPROPERTY(std::optional<legend_type>, Color, legend);
        XPROPERTY(std::optional<scale_type>, Color, scale);
        XPROPERTY(std::optional<sort_type>, Color, sort);
        XPROPERTY(std::optional<time_unit_type>, Color, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Color, title);
        XPROPERTY(std::optional<std::string>, Color, type);
    };

    XVEGA_API void to_json(nl::json& j, const Color& data);

}
#endif
