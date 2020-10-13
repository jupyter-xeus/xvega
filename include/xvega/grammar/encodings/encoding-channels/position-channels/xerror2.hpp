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

    struct XError2 : public xp::xobserved<XError2>
    {
        XPROPERTY(xtl::xoptional<agg_type>, XError2, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, XError2, bin);
        XPROPERTY(xtl::xoptional<field_type>, XError2, field);
        XPROPERTY(xtl::xoptional<time_unit_type>, XError2, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, XError2, title);
    };

    XVEGA_API void to_json(nl::json& j, const XError2& data);
}