#ifndef XVEGA_DATA_TYPES
#define XVEGA_DATA_TYPES

#include "xproperty/xobserved.hpp"
#include <xtl/xvariant.hpp>
#include "nlohmann/json.hpp"
#include "xtl/xoptional.hpp"
#include "xeither.hpp"

namespace nl = nlohmann;

struct GradientStop : public xp::xobserved<GradientStop>
{
    XPROPERTY(xtl::xoptional<std::string>, GradientStop, color);
    XPROPERTY(xtl::xoptional<double>, GradientStop, offset);
};

struct LinearGradient : public xp::xobserved<LinearGradient>
{
    XPROPERTY(std::string, LinearGradient, gradient, "linear");
    XPROPERTY(xtl::xoptional<double>, LinearGradient, x1);
    XPROPERTY(xtl::xoptional<double>, LinearGradient, x2);
    XPROPERTY(xtl::xoptional<double>, LinearGradient, y1);
    XPROPERTY(xtl::xoptional<double>, LinearGradient, y2);
    XPROPERTY(std::vector<GradientStop>, LinearGradient, stops);
};

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

struct TooltipContent : public xp::xobserved<TooltipContent>
{
    XPROPERTY(xtl::xoptional<std::string>, TooltipContent, content, xtl::missing<std::string>(), XEITHER_OPTIONAL("encoding", "data"));
};

typedef xtl::variant<std::nullptr_t, std::string> stringNoneType;
typedef xtl::variant<std::nullptr_t, bool> boolNoneType;
typedef xtl::variant<double, bool> boolNumType;
typedef xtl::variant<std::string, bool> boolStringType;
typedef xtl::variant<double, std::string> stringNumType;
typedef xtl::variant<std::string, bool, double, std::nullptr_t, TooltipContent> tooltipType;
typedef xtl::variant<double, std::string, nl::json> stringNumObjectType;
typedef xtl::variant<std::string, LinearGradient, RadialGradient> colorType;
typedef xtl::variant<std::string, LinearGradient, RadialGradient, std::nullptr_t> colorNoneType;
typedef std::map<std::string, std::vector<xtl::variant<double, std::string>>> dataFrame;
typedef xtl::variant<bool, nl::json> boolObjectType;
typedef xtl::variant<bool, nl::json, std::string> boolStringObjectType;
typedef xtl::variant<std::string, bool, double, std::nullptr_t> anyType;

#endif