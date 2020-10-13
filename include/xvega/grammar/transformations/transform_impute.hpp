// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_IMPUTE_HPP
#define XVEGA_TRANSFORM_IMPUTE_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../../utils/serialize.hpp"
#include "../encodings/encoding-channel-options/impute.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_impute : public xp::xobserved<transform_impute>
    {
        XPROPERTY(xtl::xoptional<std::string>, transform_impute, impute);
        XPROPERTY(xtl::xoptional<std::string>, transform_impute, key);
        XPROPERTY(xtl::xoptional<impute_key_vals_type>, transform_impute, keyvals);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_impute, groupby);
        XPROPERTY(xtl::xoptional<std::vector<num_none_type>>, transform_impute, frame);
        XPROPERTY(xtl::xoptional<std::string>, transform_impute, method);
        XPROPERTY(xtl::xoptional<any_type>, transform_impute, value);
    };

    XVEGA_API void to_json(nl::json& j, const transform_impute& data);
}

#endif