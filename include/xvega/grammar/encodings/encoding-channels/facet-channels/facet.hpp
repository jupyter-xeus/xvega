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

    struct Facet : public xp::xobserved<Facet>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Facet, aggregate);
        XPROPERTY(xtl::xoptional<std::string>, Facet, align);
        XPROPERTY(xtl::xoptional<bin_type>, Facet, bin);
        XPROPERTY(xtl::xoptional<std::string>, Facet, bounds);
        XPROPERTY(xtl::xoptional<bool>, Facet, center);
        XPROPERTY(xtl::xoptional<double>, Facet, columns);
        XPROPERTY(xtl::xoptional<field_type>, Facet, field);
        XPROPERTY(xtl::xoptional<Header>, Facet, header);
        XPROPERTY(xtl::xoptional<sort_type>, Facet, sort);
        XPROPERTY(xtl::xoptional<double>, Facet, spacing);
        XPROPERTY(xtl::xoptional<time_unit_type>, Facet, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Facet, title);
        XPROPERTY(xtl::xoptional<std::string>, Facet, type);
    };

    void to_json(nl::json& j, const Facet& data)
    {
        serialize(j, data.aggregate(), "aggregate");
        serialize(j, data.align(), "align");
        serialize(j, data.bin(), "bin");
        serialize(j, data.bin(), "bounds");
        serialize(j, data.center(), "center");
        serialize(j, data.columns(), "columns");
        serialize(j, data.field(), "field");
        serialize(j, data.header(), "header");
        serialize(j, data.sort(), "sort");
        serialize(j, data.spacing(), "spacing");
        serialize(j, data.timeUnit(), "timeUnit");
        serialize(j, data.title(), "title");
        serialize(j, data.type(), "type");
    }
}