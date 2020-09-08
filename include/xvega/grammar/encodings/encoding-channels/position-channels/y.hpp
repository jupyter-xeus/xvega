// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/axis.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/impute.hpp"
#include "../../encoding-channel-options/scale.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/stack.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

#include "../../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct Y : public xp::xobserved<Y>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Y, aggregate);
        XPROPERTY(xtl::xoptional<axis_type>, Y, axis);
        XPROPERTY(xtl::xoptional<double>, Y, band);
        XPROPERTY(xtl::xoptional<bin_type>, Y, bin);
        XPROPERTY(xtl::xoptional<field_type>, Y, field);
        XPROPERTY(xtl::xoptional<impute_type>, Y, impute);
        XPROPERTY(xtl::xoptional<scale_type>, Y, scale);
        XPROPERTY(xtl::xoptional<sort_type>, Y, sort);
        XPROPERTY(xtl::xoptional<stack_type>, Y, stack);
        XPROPERTY(xtl::xoptional<time_unit_type>, Y, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Y, title);
        XPROPERTY(xtl::xoptional<std::string>, Y, type);
    };

    void to_json(nl::json& j, const Y& data);
}