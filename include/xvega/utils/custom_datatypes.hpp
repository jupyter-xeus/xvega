// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_DATA_TYPES
#define XVEGA_DATA_TYPES

#include "xproperty/xobserved.hpp"
#include <xtl/xvariant.hpp>
#include "nlohmann/json.hpp"
#include "xtl/xoptional.hpp"
#include "xeither.hpp"
#include <xtl/xjson.hpp>

namespace nl = nlohmann;

namespace xv
{
    using dataFrame = std::map<std::string, std::vector<xtl::variant<double, int, std::string>>>;

    using stringNoneType = xtl::variant<std::nullptr_t, std::string>;
    using boolNoneType = xtl::variant<std::nullptr_t, bool>;
    using stringNumType = xtl::variant<double, int, std::string>;
    using boolObjectType = xtl::variant<bool, nl::json>;
    using boolStringObjectType = xtl::variant<bool, nl::json, std::string>;
    using anyType = xtl::variant<std::string, bool, double, int, std::nullptr_t>;

    struct GradientStop : public xp::xobserved<GradientStop>
    {
        XPROPERTY(xtl::xoptional<std::string>, GradientStop, color);
        XPROPERTY(xtl::xoptional<double>, GradientStop, offset);
    };

    void to_json(nl::json& j, const GradientStop& data)
    {
        if(data.color().has_value())
        {
            j["color"] = data.color().value();
        }
        if(data.offset().has_value())
        {
            j["offset"] = data.offset().value();
        }
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
        if(data.x1().has_value())
        {
            j["x1"] = data.x1().value();
        }
        if(data.x2().has_value())
        {
            j["x2"] = data.x2().value();
        }
        if(data.y1().has_value())
        {
            j["y1"] = data.y1().value();
        }
        if(data.y2().has_value())
        {
            j["y2"] = data.y2().value();
        }
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
        if(data.x1().has_value())
        {
            j["x1"] = data.x1().value();
        }
        if(data.x2().has_value())
        {
            j["x2"] = data.x2().value();
        }
        if(data.y1().has_value())
        {
            j["y1"] = data.y1().value();
        }
        if(data.y2().has_value())
        {
            j["y2"] = data.y2().value();
        }
        if(data.r1().has_value())
        {
            j["r1"] = data.r1().value();
        }
        if(data.r2().has_value())
        {
            j["r2"] = data.r2().value();
        }
        j["stops"] = data.stops();
    }

    struct TooltipContent : public xp::xobserved<TooltipContent>
    {
        XPROPERTY(xtl::xoptional<std::string>, TooltipContent, content, xtl::missing<std::string>(), XEITHER_OPTIONAL("encoding", "data"));
    };

    void to_json(nl::json& j, const TooltipContent& data) {
        if(data.content().has_value())
        {
            j["content"] = data.content().value();
        }
    }

    using tooltipType = xtl::variant<std::string, bool, double, int, std::nullptr_t, TooltipContent>;
    using colorType = xtl::variant<std::string, LinearGradient, RadialGradient>;
    using colorNoneType = xtl::variant<std::string, LinearGradient, RadialGradient, std::nullptr_t>;
}

#endif