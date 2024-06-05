// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_DETAIL_HPP
#define XVEGA_ENCODING_DETAIL_HPP

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
    struct Detail : public xp::xobserved<Detail>
    {
        XPROPERTY(std::optional<agg_type>, Detail, aggregate);
        XPROPERTY(std::optional<bin_type>, Detail, bin);
        XPROPERTY(std::optional<field_type>, Detail, field);
        XPROPERTY(std::optional<time_unit_type>, Detail, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Detail, title);
        XPROPERTY(std::optional<std::string>, Detail, type);
    };

    XVEGA_API void to_json(nl::json& j, const Detail& data);
}

#endif
