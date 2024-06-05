// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_HREF_HPP
#define XVEGA_ENCODING_HREF_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../../../utils/custom_datatypes.hpp"
#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Href : public xp::xobserved<Href>
    {
        XPROPERTY(std::optional<agg_type>, Href, aggregate);
        XPROPERTY(std::optional<bin_type>, Href, bin);
        // XPROPERTY(std::optional<condition_type>, Href, condition);
        XPROPERTY(std::optional<field_type>, Href, field);
        XPROPERTY(std::optional<string_object_type>, Href, format);
        XPROPERTY(std::optional<std::string>, Href, formatType);
        XPROPERTY(std::optional<std::string>, Href, labelExpr);
        XPROPERTY(std::optional<time_unit_type>, Href, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Href, title);
        XPROPERTY(std::optional<std::string>, Href, type);
    };

    XVEGA_API void to_json(nl::json& j, const Href& data);
}

#endif
