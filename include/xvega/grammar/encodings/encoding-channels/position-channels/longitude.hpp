// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_LONGITUDE_HPP
#define XVEGA_ENCODING_LONGITUDE_HPP

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

    struct Longitude : public xp::xobserved<Longitude>
    {
        XPROPERTY(xtl::xoptional<agg_type>, Longitude, aggregate);
        XPROPERTY(xtl::xoptional<bin_type>, Longitude, bin);
        XPROPERTY(xtl::xoptional<field_type>, Longitude, field);
        XPROPERTY(xtl::xoptional<time_unit_type>, Longitude, timeUnit);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Longitude, title);
        XPROPERTY(xtl::xoptional<std::string>, Longitude, type);
    };

    XVEGA_API void to_json(nl::json& j, const Longitude& data);
}

#endif