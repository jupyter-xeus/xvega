// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_VIEW_CONFIG_HPP
#define XVEGA_VIEW_CONFIG_HPP

#include <optional>

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    struct view_config : public xp::xobserved<view_config>
    {
        XPROPERTY(std::optional<bool>, view_config, clip);
        XPROPERTY(std::optional<double>, view_config, continuousHeight);
        XPROPERTY(std::optional<double>, view_config, continuousWidth);
        XPROPERTY(std::optional<double>, view_config, cornerRadius);
        XPROPERTY(std::optional<std::string>, view_config, cursor);
        XPROPERTY(std::optional<num_object_type>, view_config, discreteHeight);
        XPROPERTY(std::optional<num_object_type>, view_config, discreteWidth);
        XPROPERTY(std::optional<string_none_type>, view_config, fill);
        XPROPERTY(std::optional<double>, view_config, fillOpacity);
        XPROPERTY(std::optional<double>, view_config, height);
        XPROPERTY(std::optional<double>, view_config, opacity);
        XPROPERTY(std::optional<double>, view_config, step);
        XPROPERTY(std::optional<string_none_type>, view_config, stroke);
        XPROPERTY(std::optional<std::string>, view_config, strokeCap);
        XPROPERTY(std::optional<std::vector<double>>, view_config, strokeDash);
        XPROPERTY(std::optional<double>, view_config, strokeDashOffset);
        XPROPERTY(std::optional<std::string>, view_config, strokeJoin);
        XPROPERTY(std::optional<double>, view_config, strokeMiterLimit);
        XPROPERTY(std::optional<double>, view_config, strokeOpacity);
        XPROPERTY(std::optional<double>, view_config, strokeWidth);
        XPROPERTY(std::optional<double>, view_config, width);
    };

    XVEGA_API void to_json(nl::json& j, const view_config& data);
}

#endif
