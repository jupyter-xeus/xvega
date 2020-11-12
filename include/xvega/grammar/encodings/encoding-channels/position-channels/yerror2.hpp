// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_YERROR2_HPP
#define XVEGA_ENCODING_YERROR2_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct YError2 : public xp::xobserved<YError2>
    {
        XPROPERTY(xtl::xoptional<agg_type>, YError2, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, YError2, bin);
        XPROPERTY(xtl::xoptional<field_type>, YError2, field);
        XPROPERTY(xtl::xoptional<time_unit_type>, YError2, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, YError2, title);
    };

    XVEGA_API void to_json(nl::json& j, const YError2& data);
}

#endif