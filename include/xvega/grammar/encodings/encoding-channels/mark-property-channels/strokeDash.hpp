// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_DASH_HPP
#define XVEGA_ENCODING_DASH_HPP

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
    struct StrokeDash : public xp::xobserved<StrokeDash>
    {
        XPROPERTY(std::optional<agg_type>, StrokeDash, aggregate);
        XPROPERTY(std::optional<bin_type>, StrokeDash, bin);
        // XPROPERTY(std::optional<condition_type>, StrokeDash, condition);
        XPROPERTY(std::optional<field_type>, StrokeDash, field);
        XPROPERTY(std::optional<legend_type>, StrokeDash, legend);
        XPROPERTY(std::optional<scale_type>, StrokeDash, scale);
        XPROPERTY(std::optional<sort_type>, StrokeDash, sort);
        XPROPERTY(std::optional<time_unit_type>, StrokeDash, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, StrokeDash, title);
        XPROPERTY(std::optional<std::string>, StrokeDash, type);
    };

    XVEGA_API void to_json(nl::json& j, const StrokeDash& data);
}

#endif
