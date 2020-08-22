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
#include "../../encoding-channel-options/header.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

#include "../../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct Column : public xp::xobserved<Column>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Column, aggregate);
        XPROPERTY(xtl::xoptional<std::string>, Column, align);
        XPROPERTY(xtl::xoptional<bin_type>, Column, bin);
        XPROPERTY(xtl::xoptional<bool>, Column, center);
        XPROPERTY(xtl::xoptional<field_type>, Column, field);
        XPROPERTY(xtl::xoptional<Header>, Column, header);
        XPROPERTY(xtl::xoptional<sort_type>, Column, sort);
        XPROPERTY(xtl::xoptional<double>, Column, spacing);
        XPROPERTY(xtl::xoptional<time_unit_type>, Column, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Column, title);
        XPROPERTY(xtl::xoptional<std::string>, Column, type);
    };

    void to_json(nl::json& j, const Column& data)
    {
        serialize(j, data.aggregate(), "aggregate");
        serialize(j, data.align(), "align");
        serialize(j, data.bin(), "bin");
        serialize(j, data.center(), "center");
        serialize(j, data.field(), "field");
        serialize(j, data.header(), "header");
        serialize(j, data.sort(), "sort");
        serialize(j, data.spacing(), "spacing");
        serialize(j, data.timeUnit(), "timeUnit");
        serialize(j, data.title(), "title");
        serialize(j, data.type(), "type");
    }
}