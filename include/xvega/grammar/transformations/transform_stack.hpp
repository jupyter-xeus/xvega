// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_STACK_HPP
#define XVEGA_TRANSFORM_STACK_HPP

#include <xproperty/xobserved.hpp>

#include <xtl/xoptional.hpp>
#include <xtl/xjson.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../transformations.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct sort_field_def : public xp::xobserved<sort_field_def>
    {
        XPROPERTY(xtl::xoptional<std::string>, sort_field_def, field);
        XPROPERTY(xtl::xoptional<string_none_type>, sort_field_def, order);
    };

    XVEGA_API void to_json(nl::json& j, const sort_field_def& data);

    struct transform_stack : public transformation<transform_stack>
    {
        XPROPERTY(xtl::xoptional<std::string>, transform_stack, stack);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_stack, groupby);
        XPROPERTY(xtl::xoptional<std::string>, transform_stack, offset);
        XPROPERTY(xtl::xoptional<std::vector<sort_field_def>>, transform_stack, sort);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_stack, as);
    };

    XVEGA_API void to_json(nl::json& j, const transform_stack& data);
}

#endif