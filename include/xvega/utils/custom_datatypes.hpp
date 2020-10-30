// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_DATA_TYPES_HPP
#define XVEGA_DATA_TYPES_HPP

#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <xtl/xoptional.hpp>

#include "xproperty/xobserved.hpp"

#include "nlohmann/json.hpp"

#include "../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{

    using df_type = std::map<std::string, std::vector<xtl::variant<double, int, std::string, std::nullptr_t>>>;

    struct data_frame : public xp::xobserved<data_frame>
    {
        XPROPERTY(xtl::xoptional<df_type>, data_frame, values);
    };

    XVEGA_API void to_json(nl::json& j, const data_frame& data);

    using string_none_type = xtl::variant<std::nullptr_t, std::string>;
    using bool_none_type = xtl::variant<std::nullptr_t, bool>;
    using string_num_type = xtl::variant<double, int, std::string>;
    using bool_object_type = xtl::variant<bool, nl::json>;
    using bool_string_object_type = xtl::variant<bool, nl::json, std::string>;
    using any_type = xtl::variant<std::string, bool, double, int, std::nullptr_t>;

    struct GradientStop : public xp::xobserved<GradientStop>
    {
        XPROPERTY(xtl::xoptional<std::string>, GradientStop, color);
        XPROPERTY(xtl::xoptional<double>, GradientStop, offset);
    };

    XVEGA_API void to_json(nl::json& j, const GradientStop& data);

    struct LinearGradient : public xp::xobserved<LinearGradient>
    {
        XPROPERTY(std::string, LinearGradient, gradient, "linear");
        XPROPERTY(xtl::xoptional<double>, LinearGradient, x1);
        XPROPERTY(xtl::xoptional<double>, LinearGradient, x2);
        XPROPERTY(xtl::xoptional<double>, LinearGradient, y1);
        XPROPERTY(xtl::xoptional<double>, LinearGradient, y2);
        XPROPERTY(std::vector<GradientStop>, LinearGradient, stops);
    };

    XVEGA_API void to_json(nl::json& j, const LinearGradient& data);

    struct RadialGradient : public xp::xobserved<RadialGradient>
    {
        XPROPERTY(std::string, RadialGradient, gradient, "radial");
        XPROPERTY(xtl::xoptional<double>, RadialGradient, x1);
        XPROPERTY(xtl::xoptional<double>, RadialGradient, x2);
        XPROPERTY(xtl::xoptional<double>, RadialGradient, y1);
        XPROPERTY(xtl::xoptional<double>, RadialGradient, y2);
        XPROPERTY(xtl::xoptional<double>, RadialGradient, r1);
        XPROPERTY(xtl::xoptional<double>, RadialGradient, r2);
        XPROPERTY(std::vector<GradientStop>, RadialGradient, stops);
    };

    XVEGA_API void to_json(nl::json& j, const RadialGradient& data);

    struct TooltipContent : public xp::xobserved<TooltipContent>
    {
        XPROPERTY(xtl::xoptional<std::string>, TooltipContent, content);
    };

    XVEGA_API void to_json(nl::json& j, const TooltipContent& data);

    using tooltip_type = xtl::variant<std::string, bool, double, int, std::nullptr_t, TooltipContent>;
    using color_type = xtl::variant<std::string, LinearGradient, RadialGradient>;
    using color_none_type = xtl::variant<std::string, LinearGradient, RadialGradient, std::nullptr_t>;
}

#endif
