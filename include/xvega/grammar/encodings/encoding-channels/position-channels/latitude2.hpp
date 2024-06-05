// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_LATITUDE2_HPP
#define XVEGA_ENCODING_LATITUDE2_HPP

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
    struct Latitude2 : public xp::xobserved<Latitude2>
    {
        XPROPERTY(std::optional<agg_type>, Latitude2, aggregate);
        XPROPERTY(std::optional<bin_type>, Latitude2, bin);
        XPROPERTY(std::optional<field_type>, Latitude2, field);
        XPROPERTY(std::optional<time_unit_type>, Latitude2, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Latitude2, title);
    };

    XVEGA_API void to_json(nl::json& j, const Latitude2& data);
}

#endif
