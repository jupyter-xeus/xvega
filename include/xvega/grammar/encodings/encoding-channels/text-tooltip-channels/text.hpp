// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_TEXT_HPP
#define XVEGA_ENCODING_TEXT_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/timeunit.hpp"
#include "../../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Text : public xp::xobserved<Text>
    {
        XPROPERTY(std::optional<agg_type>, Text, aggregate);
        XPROPERTY(std::optional<bin_type>, Text, bin);
        // XPROPERTY(std::optional<condition_type>, Text, condition);
        XPROPERTY(std::optional<field_type>, Text, field);
        XPROPERTY(std::optional<string_object_type>, Text, format);
        XPROPERTY(std::optional<std::string>, Text, formatType);
        XPROPERTY(std::optional<std::string>, Text, labelExpr);
        XPROPERTY(std::optional<time_unit_type>, Text, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Text, title);
        XPROPERTY(std::optional<std::string>, Text, type);
    };

    XVEGA_API void to_json(nl::json& j, const Text& data);
}

#endif
