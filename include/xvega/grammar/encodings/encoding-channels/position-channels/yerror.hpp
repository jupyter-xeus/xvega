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

    struct YError : public xp::xobserved<YError>
    {
        XPROPERTY(xtl::xoptional<agg_type>, YError, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, YError, bin);
        XPROPERTY(xtl::xoptional<field_type>, YError, field);
        XPROPERTY(xtl::xoptional<time_unit_type>, YError, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, YError, title);
    };

    void to_json(nl::json& j, const YError& data)
    {
        serialize(j, data.aggregate(), "aggregate");
        serialize(j, data.bin(), "bin");
        serialize(j, data.field(), "field");
        serialize(j, data.timeUnit(), "timeUnit");
        serialize(j, data.title(), "title");
    }
}