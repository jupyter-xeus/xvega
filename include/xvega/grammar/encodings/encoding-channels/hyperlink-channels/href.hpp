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
    using string_object_type = xtl::variant<nl::json, std::string>;

    struct Href : public xp::xobserved<Href>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Href, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, Href, bin);
        // XPROPERTY(xtl::xoptional<condition_type>, Href, condition);
        XPROPERTY(xtl::xoptional<field_type>, Href, field);
        XPROPERTY(xtl::xoptional<string_object_type>, Href, format);
        XPROPERTY(xtl::xoptional<std::string>, Href, formatType);
        XPROPERTY(xtl::xoptional<std::string>, Href, labelExpr);
        XPROPERTY(xtl::xoptional<time_unit_type>, Href, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Href, title);
        XPROPERTY(xtl::xoptional<std::string>, Href, type);
    };

    XVEGA_API void to_json(nl::json& j, const Href& data);
}