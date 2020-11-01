// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_VIEW_CONFIG_HPP
#define XVEGA_VIEW_CONFIG_HPP

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    using num_object_type = xtl::variant<double, int, nl::json>;

    struct view_config : public xp::xobserved<view_config>
    {
        XPROPERTY(xtl::xoptional<bool>, view_config, clip);
        XPROPERTY(xtl::xoptional<double>, view_config, continuousHeight);
        XPROPERTY(xtl::xoptional<double>, view_config, continuousWidth);
        XPROPERTY(xtl::xoptional<double>, view_config, cornerRadius);
        XPROPERTY(xtl::xoptional<std::string>, view_config, cursor);
        XPROPERTY(xtl::xoptional<num_object_type>, view_config, discreteHeight);
        XPROPERTY(xtl::xoptional<num_object_type>, view_config, discreteWidth);
        XPROPERTY(xtl::xoptional<string_none_type>, view_config, fill);
        XPROPERTY(xtl::xoptional<double>, view_config, fillOpacity);
        XPROPERTY(xtl::xoptional<double>, view_config, height);
        XPROPERTY(xtl::xoptional<double>, view_config, opacity);
        XPROPERTY(xtl::xoptional<double>, view_config, step);
        XPROPERTY(xtl::xoptional<string_none_type>, view_config, stroke);
        XPROPERTY(xtl::xoptional<std::string>, view_config, strokeCap);
        XPROPERTY(xtl::xoptional<std::vector<double>>, view_config, strokeDash);
        XPROPERTY(xtl::xoptional<double>, view_config, strokeDashOffset);
        XPROPERTY(xtl::xoptional<std::string>, view_config, strokeJoin);
        XPROPERTY(xtl::xoptional<double>, view_config, strokeMiterLimit);
        XPROPERTY(xtl::xoptional<double>, view_config, strokeOpacity);
        XPROPERTY(xtl::xoptional<double>, view_config, strokeWidth);
        XPROPERTY(xtl::xoptional<double>, view_config, width);
    };

    XVEGA_API void to_json(nl::json& j, const view_config& data);
}

#endif
