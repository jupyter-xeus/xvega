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

namespace nl = nlohmann;

namespace xv
{
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct Row : public xp::xobserved<Row>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Row, aggregate);
        XPROPERTY(xtl::xoptional<std::string>, Row, align);
        XPROPERTY(xtl::xoptional<bin_type>, Row, bin);
        XPROPERTY(xtl::xoptional<bool>, Row, center);
        XPROPERTY(xtl::xoptional<field_type>, Row, field);
        XPROPERTY(xtl::xoptional<Header>, Row, header);
        XPROPERTY(xtl::xoptional<sort_type>, Row, sort);
        XPROPERTY(xtl::xoptional<double>, Row, spacing);
        XPROPERTY(xtl::xoptional<time_unit_type>, Row, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Row, title);
        XPROPERTY(xtl::xoptional<std::string>, Row, type);
    };

    XVEGA_API void to_json(nl::json& j, const Row& data);
}