// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_LONGITUDE_HPP
#define XVEGA_ENCODING_LONGITUDE_HPP

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
    struct Longitude : public xp::xobserved<Longitude>
    {
        XPROPERTY(std::optional<agg_type>, Longitude, aggregate);
        XPROPERTY(std::optional<bin_type>, Longitude, bin);
        XPROPERTY(std::optional<field_type>, Longitude, field);
        XPROPERTY(std::optional<time_unit_type>, Longitude, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Longitude, title);
        XPROPERTY(std::optional<std::string>, Longitude, type);
    };

    XVEGA_API void to_json(nl::json& j, const Longitude& data);
}

#endif
