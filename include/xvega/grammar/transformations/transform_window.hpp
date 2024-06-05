// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_WINDOW_HPP
#define XVEGA_TRANSFORM_WINDOW_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "./transform_stack.hpp"
#include "../transformations.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct window_field_def : public xp::xobserved<window_field_def>
    {
        XPROPERTY(std::optional<std::string>, window_field_def, op);
        XPROPERTY(std::optional<std::string>, window_field_def, field);
        XPROPERTY(std::optional<double>, window_field_def, param);
        XPROPERTY(std::optional<std::string>, window_field_def, as);
    };

    XVEGA_API void to_json(nl::json& j, const window_field_def& data);

    struct transform_window : public transformation<transform_window>
    {
        XPROPERTY(std::optional<std::vector<window_field_def>>, transform_window, window);
        XPROPERTY(std::optional<std::vector<num_none_type>>, transform_window, frame);
        XPROPERTY(std::optional<bool>, transform_window, ignorePeers);
        XPROPERTY(std::optional<std::vector<std::string>>, transform_window, groupby);
        XPROPERTY(std::optional<std::vector<sort_field_def>>, transform_window, sort);
    };

    XVEGA_API void to_json(nl::json& j, const transform_window& data);
}

#endif
