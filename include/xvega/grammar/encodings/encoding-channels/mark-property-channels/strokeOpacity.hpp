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
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/legend.hpp"
#include "../../encoding-channel-options/scale.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

#include "../../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct StrokeOpacity : public xp::xobserved<StrokeOpacity>
    {
        XPROPERTY(xtl::xoptional<agg_type>, StrokeOpacity, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, StrokeOpacity, bin);
        // XPROPERTY(xtl::xoptional<condition_type>, StrokeOpacity, condition);
        XPROPERTY(xtl::xoptional<field_type>, StrokeOpacity, field);
        XPROPERTY(xtl::xoptional<legend_type>, StrokeOpacity, legend);
        XPROPERTY(xtl::xoptional<scale_type>, StrokeOpacity, scale);
        XPROPERTY(xtl::xoptional<sort_type>, StrokeOpacity, sort);
        XPROPERTY(xtl::xoptional<time_unit_type>, StrokeOpacity, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, StrokeOpacity, title);
        XPROPERTY(xtl::xoptional<std::string>, StrokeOpacity, type);
    };

    void to_json(nl::json& j, const StrokeOpacity& data)
    {
        serialize(j, data.aggregate(), "aggregate");
        serialize(j, data.bin(), "bin");
        // serialize(j, data.condition(), "condition");
        serialize(j, data.field(), "field");
        serialize(j, data.legend(), "legend");
        serialize(j, data.scale(), "scale");
        serialize(j, data.sort(), "sort");
        serialize(j, data.timeUnit(), "timeUnit");
        serialize(j, data.title(), "title");
        serialize(j, data.type(), "type");
    }
}