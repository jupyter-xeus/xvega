// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_JOIN_AGGREGATE_HPP
#define XVEGA_TRANSFORM_JOIN_AGGREGATE_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../transformations.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct join_aggregate_field_def : public xp::xobserved<join_aggregate_field_def>
    {
        XPROPERTY(std::optional<std::string>, join_aggregate_field_def, as);
        XPROPERTY(std::optional<std::string>, join_aggregate_field_def, field);
        XPROPERTY(std::optional<std::string>, join_aggregate_field_def, op);
    };

    XVEGA_API void to_json(nl::json& j, const join_aggregate_field_def& data);

    struct transform_join_aggregate : public transformation<transform_join_aggregate>
    {
        XPROPERTY(std::optional<std::vector<join_aggregate_field_def>>, transform_join_aggregate, joinaggregate);
        XPROPERTY(std::optional<std::vector<std::string>>, transform_join_aggregate, groupby);
    };

    XVEGA_API void to_json(nl::json& j, const transform_join_aggregate& data);
}

#endif
