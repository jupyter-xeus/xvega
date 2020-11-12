// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_SHAPE_HPP
#define XVEGA_ENCODING_SHAPE_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/legend.hpp"
#include "../../encoding-channel-options/scale.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct Shape : public xp::xobserved<Shape>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Shape, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, Shape, bin);
        // XPROPERTY(xtl::xoptional<condition_type>, Shape, condition);
        XPROPERTY(xtl::xoptional<field_type>, Shape, field);
        XPROPERTY(xtl::xoptional<legend_type>, Shape, legend);
        XPROPERTY(xtl::xoptional<scale_type>, Shape, scale);
        XPROPERTY(xtl::xoptional<sort_type>, Shape, sort);
        XPROPERTY(xtl::xoptional<time_unit_type>, Shape, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Shape, title);
        XPROPERTY(xtl::xoptional<std::string>, Shape, type);
    };

    XVEGA_API void to_json(nl::json& j, const Shape& data);
}

#endif