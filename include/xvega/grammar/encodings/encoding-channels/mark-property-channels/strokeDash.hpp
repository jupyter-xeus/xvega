// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_DASH_HPP
#define XVEGA_ENCODING_DASH_HPP

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
    struct StrokeDash : public xp::xobserved<StrokeDash>
    {
        XPROPERTY(xtl::xoptional<agg_type>, StrokeDash, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, StrokeDash, bin);
        // XPROPERTY(xtl::xoptional<condition_type>, StrokeDash, condition);
        XPROPERTY(xtl::xoptional<field_type>, StrokeDash, field);
        XPROPERTY(xtl::xoptional<legend_type>, StrokeDash, legend);
        XPROPERTY(xtl::xoptional<scale_type>, StrokeDash, scale);
        XPROPERTY(xtl::xoptional<sort_type>, StrokeDash, sort);
        XPROPERTY(xtl::xoptional<time_unit_type>, StrokeDash, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, StrokeDash, title);
        XPROPERTY(xtl::xoptional<std::string>, StrokeDash, type);
    };

    XVEGA_API void to_json(nl::json& j, const StrokeDash& data);
}

#endif