// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_COLUMN_HPP
#define XVEGA_ENCODING_COLUMN_HPP

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
    struct Column : public xp::xobserved<Column>
    {
        XPROPERTY(std::optional<agg_type>, Column, aggregate);
        XPROPERTY(std::optional<std::string>, Column, align);
        XPROPERTY(std::optional<bin_type>, Column, bin);
        XPROPERTY(std::optional<bool>, Column, center);
        XPROPERTY(std::optional<field_type>, Column, field);
        XPROPERTY(std::optional<Header>, Column, header);
        XPROPERTY(std::optional<sort_type>, Column, sort);
        XPROPERTY(std::optional<double>, Column, spacing);
        XPROPERTY(std::optional<time_unit_type>, Column, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, Column, title);
        XPROPERTY(std::optional<std::string>, Column, type);
    };

    XVEGA_API void to_json(nl::json& j, const Column& data);
}

#endif
