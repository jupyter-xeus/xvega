// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_DATA_TYPES_HPP
#define XVEGA_DATA_TYPES_HPP

#include "xproperty/xobserved.hpp"
#include <xtl/xvariant.hpp>
#include "nlohmann/json.hpp"
#include "xtl/xoptional.hpp"
#include "xeither.hpp"
#include <xtl/xjson.hpp>

#include "./serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    using data_frame = std::map<std::string, std::vector<xtl::variant<double, int, std::string>>>;

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

    void to_json(nl::json& j, const GradientStop& data)
    {
        serialize(j, data.color(), "color");
        serialize(j, data.offset(), "offset");
    }

    struct LinearGradient : public xp::xobserved<LinearGradient>
    {
        XPROPERTY(std::string, LinearGradient, gradient, "linear");
        XPROPERTY(xtl::xoptional<double>, LinearGradient, x1);
        XPROPERTY(xtl::xoptional<double>, LinearGradient, x2);
        XPROPERTY(xtl::xoptional<double>, LinearGradient, y1);
        XPROPERTY(xtl::xoptional<double>, LinearGradient, y2);
        XPROPERTY(std::vector<GradientStop>, LinearGradient, stops);
    };

    void to_json(nl::json& j, const LinearGradient& data) {
        j["gradient"] = data.gradient();
        serialize(j, data.x1(), "x1");
        serialize(j, data.x2(), "x2");
        serialize(j, data.y1(), "y1");
        serialize(j, data.y2(), "y2");
        j["stops"] = data.stops();
    }

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

    void to_json(nl::json& j, const RadialGradient& data)
    {
        j["gradient"] = data.gradient();
        serialize(j, data.x1(), "x1");
        serialize(j, data.x2(), "x2");
        serialize(j, data.y1(), "y1");
        serialize(j, data.y2(), "y2");
        serialize(j, data.r1(), "r1");
        serialize(j, data.r2(), "r2");
        j["stops"] = data.stops();
    }

    struct TooltipContent : public xp::xobserved<TooltipContent>
    {
        XPROPERTY(xtl::xoptional<std::string>, TooltipContent, content, xtl::missing<std::string>(), XEITHER_OPTIONAL("encoding", "data"));
    };

    void to_json(nl::json& j, const TooltipContent& data) {
        serialize(j, data.content(), "content");
    }

    using tooltip_type = xtl::variant<std::string, bool, double, int, std::nullptr_t, TooltipContent>;
    using color_type = xtl::variant<std::string, LinearGradient, RadialGradient>;
    using color_none_type = xtl::variant<std::string, LinearGradient, RadialGradient, std::nullptr_t>;
}

#endif