// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_IMPUTE_HPP
#define XVEGA_TRANSFORM_IMPUTE_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../transformations.hpp"
#include "../encodings/encoding-channel-options/impute.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_impute : public transformation<transform_impute>
    {
        XPROPERTY(std::optional<std::string>, transform_impute, impute);
        XPROPERTY(std::optional<std::string>, transform_impute, key);
        XPROPERTY(std::optional<impute_key_vals_type>, transform_impute, keyvals);
        XPROPERTY(std::optional<std::vector<std::string>>, transform_impute, groupby);
        XPROPERTY(std::optional<std::vector<num_none_type>>, transform_impute, frame);
        XPROPERTY(std::optional<std::string>, transform_impute, method);
        XPROPERTY(std::optional<any_type>, transform_impute, value);
    };

    XVEGA_API void to_json(nl::json& j, const transform_impute& data);
}

#endif
