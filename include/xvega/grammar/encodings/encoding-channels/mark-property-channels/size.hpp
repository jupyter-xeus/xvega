// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_SIZE_HPP
#define XVEGA_ENCODING_SIZE_HPP

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
    struct Size : public xp::xobserved<Size>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Size, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, Size, bin);
        // XPROPERTY(xtl::xoptional<condition_type>, Size, condition);
        XPROPERTY(xtl::xoptional<field_type>, Size, field);
        XPROPERTY(xtl::xoptional<legend_type>, Size, legend);
        XPROPERTY(xtl::xoptional<scale_type>, Size, scale);
        XPROPERTY(xtl::xoptional<sort_type>, Size, sort);
        XPROPERTY(xtl::xoptional<time_unit_type>, Size, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Size, title);
        XPROPERTY(xtl::xoptional<std::string>, Size, type);
    };

    XVEGA_API void to_json(nl::json& j, const Size& data);
}

#endif