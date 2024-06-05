// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_X2_HPP
#define XVEGA_ENCODING_X2_HPP

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
    struct X2 : public xp::xobserved<X2>
    {
        XPROPERTY(std::optional<agg_type>, X2, aggregate);
        XPROPERTY(std::optional<bin_type>, X2, bin);
        XPROPERTY(std::optional<field_type>, X2, field);
        XPROPERTY(std::optional<time_unit_type>, X2, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, X2, title);
    };

    XVEGA_API void to_json(nl::json& j, const X2& data);
}

#endif
