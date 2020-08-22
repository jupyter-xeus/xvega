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
#include "../../encoding-channel-options/timeunit.hpp"

#include "../../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct Latitude : public xp::xobserved<Latitude>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Latitude, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, Latitude, bin);
        XPROPERTY(xtl::xoptional<field_type>, Latitude, field);
        XPROPERTY(xtl::xoptional<time_unit_type>, Latitude, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Latitude, title);
        XPROPERTY(xtl::xoptional<std::string>, Latitude, type);
    };

    void to_json(nl::json& j, const Latitude& data)
    {
        serialize(j, data.aggregate(), "aggregate");
        serialize(j, data.bin(), "bin");
        serialize(j, data.field(), "field");
        serialize(j, data.timeUnit(), "timeUnit");
        serialize(j, data.title(), "title");
        serialize(j, data.type(), "type");
    }
}