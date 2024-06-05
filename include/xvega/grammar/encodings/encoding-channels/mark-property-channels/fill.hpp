// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_FILL_HPP
#define XVEGA_ENCODING_FILL_HPP

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
    struct Fill : public xp::xobserved<Fill>
    {
        XPROPERTY(std::optional<agg_type>, Fill, aggregate);
        XPROPERTY(std::optional<bin_type>, Fill, bin);
        // XPROPERTY(std::optional<condition_type>, Fill, condition);
        XPROPERTY(std::optional<field_type>, Fill, field);
        XPROPERTY(std::optional<legend_type>, Fill, legend);
        XPROPERTY(std::optional<scale_type>, Fill, scale);
        XPROPERTY(std::optional<sort_type>, Fill, sort);
        XPROPERTY(std::optional<time_unit_type>, Fill, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Fill, title);
        XPROPERTY(std::optional<std::string>, Fill, type);
    };

    XVEGA_API void to_json(nl::json& j, const Fill& data);
}

#endif
