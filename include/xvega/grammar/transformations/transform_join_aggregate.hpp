// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_JOIN_AGGREGATE_HPP
#define XVEGA_TRANSFORM_JOIN_AGGREGATE_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct join_aggregate_field_def : public xp::xobserved<join_aggregate_field_def>
    {
        XPROPERTY(xtl::xoptional<std::string>, join_aggregate_field_def, as);
        XPROPERTY(xtl::xoptional<std::string>, join_aggregate_field_def, field);
        XPROPERTY(xtl::xoptional<std::string>, join_aggregate_field_def, op);
    };

    XVEGA_API void to_json(nl::json& j, const join_aggregate_field_def& data);

    struct transform_join_aggregate : public xp::xobserved<transform_join_aggregate>
    {
        XPROPERTY(xtl::xoptional<std::vector<join_aggregate_field_def>>, transform_join_aggregate, joinaggregate);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_join_aggregate, groupby);
    };

    XVEGA_API void to_json(nl::json& j, const transform_join_aggregate& data);
}

#endif
