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

    struct X : public xp::xobserved<X>
    {
        XPROPERTY(xtl::xoptional<agg_type>, X, aggregate);
        XPROPERTY(xtl::xoptional<axis_type>, X, axis);
        XPROPERTY(xtl::xoptional<double>, X, band);
        XPROPERTY(xtl::xoptional<bin_type>, X, bin);
        XPROPERTY(xtl::xoptional<field_type>, X, field);
        XPROPERTY(xtl::xoptional<impute_type>, X, impute);
        XPROPERTY(xtl::xoptional<scale_type>, X, scale);
        XPROPERTY(xtl::xoptional<sort_type>, X, sort);
        XPROPERTY(xtl::xoptional<stack_type>, X, stack);
        XPROPERTY(xtl::xoptional<time_unit_type>, X, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, X, title);
        XPROPERTY(xtl::xoptional<std::string>, X, type);
    };

    void to_json(nl::json& j, const X& data)
    {
        serialize(j, data.aggregate(), "aggregate");
        serialize(j, data.axis(), "axis");
        serialize(j, data.band(), "band");
        serialize(j, data.bin(), "bin");
        serialize(j, data.field(), "field");
        serialize(j, data.impute(), "impute");
        serialize(j, data.scale(), "scale");
        serialize(j, data.sort(), "sort");
        serialize(j, data.stack(), "stack");
        serialize(j, data.timeUnit(), "timeUnit");
        serialize(j, data.title(), "title");
        serialize(j, data.type(), "type");
    }
}