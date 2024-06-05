// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPACITY_HPP
#define XVEGA_ENCODING_OPACITY_HPP

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
    struct Opacity : public xp::xobserved<Opacity>
    {
        XPROPERTY(std::optional<agg_type>, Opacity, aggregate);
        XPROPERTY(std::optional<bin_type>, Opacity, bin);
        // XPROPERTY(std::optional<condition_type>, Opacity, condition);
        XPROPERTY(std::optional<field_type>, Opacity, field);
        XPROPERTY(std::optional<legend_type>, Opacity, legend);
        XPROPERTY(std::optional<scale_type>, Opacity, scale);
        XPROPERTY(std::optional<sort_type>, Opacity, sort);
        XPROPERTY(std::optional<time_unit_type>, Opacity, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Opacity, title);
        XPROPERTY(std::optional<std::string>, Opacity, type);
    };

    XVEGA_API void to_json(nl::json& j, const Opacity& data);
}

#endif
