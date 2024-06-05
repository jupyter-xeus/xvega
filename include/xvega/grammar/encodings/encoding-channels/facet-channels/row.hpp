// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_ROW_HPP
#define XVEGA_ENCODING_ROW_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/header.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/timeunit.hpp"
#include "../../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Row : public xp::xobserved<Row>
    {
        XPROPERTY(std::optional<agg_type>, Row, aggregate);
        XPROPERTY(std::optional<std::string>, Row, align);
        XPROPERTY(std::optional<bin_type>, Row, bin);
        XPROPERTY(std::optional<bool>, Row, center);
        XPROPERTY(std::optional<field_type>, Row, field);
        XPROPERTY(std::optional<Header>, Row, header);
        XPROPERTY(std::optional<sort_type>, Row, sort);
        XPROPERTY(std::optional<double>, Row, spacing);
        XPROPERTY(std::optional<time_unit_type>, Row, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Row, title);
        XPROPERTY(std::optional<std::string>, Row, type);
    };

    XVEGA_API void to_json(nl::json& j, const Row& data);
}

#endif
