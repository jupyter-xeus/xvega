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

    struct Opacity : public xp::xobserved<Opacity>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Opacity, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, Opacity, bin);
        // XPROPERTY(xtl::xoptional<condition_type>, Opacity, condition);
        XPROPERTY(xtl::xoptional<field_type>, Opacity, field);
        XPROPERTY(xtl::xoptional<legend_type>, Opacity, legend);
        XPROPERTY(xtl::xoptional<scale_type>, Opacity, scale);
        XPROPERTY(xtl::xoptional<sort_type>, Opacity, sort);
        XPROPERTY(xtl::xoptional<time_unit_type>, Opacity, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Opacity, title);
        XPROPERTY(xtl::xoptional<std::string>, Opacity, type);
    };

    void to_json(nl::json& j, const Opacity& data)
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