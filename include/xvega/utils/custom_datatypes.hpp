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
    typedef xtl::variant<std::nullptr_t, std::string> stringNoneType;
    typedef xtl::variant<std::nullptr_t, bool> boolNoneType;
    typedef xtl::variant<double, int, bool> boolNumType;
    typedef xtl::variant<std::string, bool> boolStringType;
    typedef xtl::variant<double, int, std::string> stringNumType;
    typedef xtl::variant<double, int, std::string, nl::json> stringNumObjectType;
    typedef std::map<std::string, std::vector<xtl::variant<double, int, std::string>>> dataFrame;
    typedef xtl::variant<bool, nl::json> boolObjectType;
    typedef xtl::variant<bool, nl::json, std::string> boolStringObjectType;
    typedef xtl::variant<nl::json, std::string> stringObjectType;
    typedef xtl::variant<std::string, bool, double, int, std::nullptr_t> anyType;

    struct Aggregate : public xp::xobserved<Aggregate>
    {
        XPROPERTY(xtl::xoptional<std::string>, Aggregate, argmax);
        XPROPERTY(xtl::xoptional<std::string>, Aggregate, argmin);
    };

    void to_json(nl::json& j, const Aggregate& data)
    {
        if(data.argmax().has_value())
        {
            j["argmax"] = data.argmax().value();
        }
        if(data.argmin().has_value())
        {
            j["argmin"] = data.argmin().value();
        }
    }

    struct Axis : public xp::xobserved<Axis>
    {
        // General Axis Properties
        XPROPERTY(xtl::xoptional<bool>, Axis, aria);
        XPROPERTY(xtl::xoptional<double>, Axis, bandPosition);
        XPROPERTY(xtl::xoptional<std::string>, Axis, description);
        XPROPERTY(xtl::xoptional<double>, Axis, maxExtent);
        XPROPERTY(xtl::xoptional<double>, Axis, minExtent);
        XPROPERTY(xtl::xoptional<std::string>, Axis, orient);
        XPROPERTY(xtl::xoptional<double>, Axis, offset);
        XPROPERTY(xtl::xoptional<double>, Axis, position);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, Axis, style);
        XPROPERTY(xtl::xoptional<double>, Axis, translate);
        XPROPERTY(xtl::xoptional<double>, Axis, zindex);

        // Domain Axis Properties
        XPROPERTY(xtl::xoptional<bool>, Axis, domain);
        XPROPERTY(xtl::xoptional<std::string>, Axis, domainCap);
        XPROPERTY(xtl::xoptional<stringNoneType>, Axis, domainColor);
        XPROPERTY(xtl::xoptional<double>, Axis, domainOpacity);
        XPROPERTY(xtl::xoptional<double>, Axis, domainWidth);
        XPROPERTY(xtl::xoptional<std::vector<double>>, Axis, domainDash);
        XPROPERTY(xtl::xoptional<double>, Axis, domainDashOffset);

        // Label Axis Properties
        XPROPERTY(xtl::xoptional<stringObjectType>, Axis, format);
        XPROPERTY(xtl::xoptional<std::string>, Axis, formatType);
        XPROPERTY(xtl::xoptional<bool>, Axis, labels);

    };

    struct DateTime : public xp::xobserved<DateTime>
    {
        XPROPERTY(xtl::xoptional<double>, DateTime, year);
        XPROPERTY(xtl::xoptional<double>, DateTime, quarter);
        XPROPERTY(xtl::xoptional<stringNumType>, DateTime, month);
        XPROPERTY(xtl::xoptional<double>, DateTime, date);
        XPROPERTY(xtl::xoptional<stringNumType>, DateTime, day);
        XPROPERTY(xtl::xoptional<double>, DateTime, hours);
        XPROPERTY(xtl::xoptional<double>, DateTime, minutes);
        XPROPERTY(xtl::xoptional<double>, DateTime, seconds);
        XPROPERTY(xtl::xoptional<double>, DateTime, milliseconds);
    };

    void to_json(nl::json& j, const DateTime& data)
    {
        if(data.year().has_value())
        {
            j["year"] = data.year().value();
        }
        if(data.quarter().has_value())
        {
            j["quarter"] = data.quarter().value();
        }
        if(data.month().has_value())
        {
            j["month"] = data.month().value();
        }
        if(data.date().has_value())
        {
            j["date"] = data.date().value();
        }
        if(data.day().has_value())
        {
            j["day"] = data.day().value();
        }
        if(data.hours().has_value())
        {
            j["hours"] = data.hours().value();
        }
        if(data.minutes().has_value())
        {
            j["minutes"] = data.minutes().value();
        }
        if(data.seconds().has_value())
        {
            j["seconds"] = data.seconds().value();
        }
        if(data.milliseconds().has_value())
        {
            j["milliseconds"] = data.milliseconds().value();
        }
    }

    struct TimeUnit : public xp::xobserved<TimeUnit>
    {
        XPROPERTY(xtl::xoptional<std::string>, TimeUnit, unit);
        XPROPERTY(xtl::xoptional<double>, TimeUnit, maxbins);
        XPROPERTY(xtl::xoptional<double>, TimeUnit, step);
        XPROPERTY(xtl::xoptional<bool>, TimeUnit, utc);
    };

    void to_json(nl::json& j, const TimeUnit& data)
    {
        if(data.unit().has_value())
        {
            j["unit"] = data.unit().value();
        }
        if(data.maxbins().has_value())
        {
            j["maxbins"] = data.maxbins().value();
        }
        if(data.step().has_value())
        {
            j["step"] = data.step().value();
        }
        if(data.utc().has_value())
        {
            j["utc"] = data.utc().value();
        }
    }

    typedef xtl::variant<std::string, double, int, bool, DateTime> fieldPredicateEqualType;
    typedef xtl::variant<std::string, double, int, DateTime> fieldPredicateType;
    typedef xtl::variant<std::vector<double>, std::vector<int>, std::vector<DateTime>, std::vector<std::nullptr_t>> fieldPredicateRangeType;
    typedef xtl::variant<std::vector<std::string>, std::vector<double>, std::vector<int>, std::vector<bool>, std::vector<DateTime>> fieldPredicateOneOfType;

    struct FieldPredicate : public xp::xobserved<FieldPredicate>
    {
        XPROPERTY(xtl::xoptional<std::string>, FieldPredicate, field);
        XPROPERTY(xtl::xoptional<TimeUnit>, FieldPredicate, timeUnit);
        XPROPERTY(xtl::xoptional<fieldPredicateEqualType>, FieldPredicate, equal);
        XPROPERTY(xtl::xoptional<fieldPredicateType>, FieldPredicate, lt);
        XPROPERTY(xtl::xoptional<fieldPredicateType>, FieldPredicate, lte);
        XPROPERTY(xtl::xoptional<fieldPredicateType>, FieldPredicate, gt);
        XPROPERTY(xtl::xoptional<fieldPredicateType>, FieldPredicate, gte);
        XPROPERTY(xtl::xoptional<fieldPredicateRangeType>, FieldPredicate, range);
        XPROPERTY(xtl::xoptional<fieldPredicateOneOfType>, FieldPredicate, oneOf);
        XPROPERTY(xtl::xoptional<bool>, FieldPredicate, valid);
    };

    void to_json(nl::json& j, const FieldPredicate& data)
    {
        if(data.field().has_value())
        {
            j["field"] = data.field().value();
        }
        if(data.timeUnit().has_value())
        {
            j["timeUnit"] = data.timeUnit().value();
        }
        if(data.equal().has_value())
        {
            j["equal"] = data.equal().value();
        }
        if(data.lt().has_value())
        {
            j["lt"] = data.lt().value();
        }
        if(data.lte().has_value())
        {
            j["lte"] = data.lte().value();
        }
        if(data.gt().has_value())
        {
            j["gt"] = data.gt().value();
        }
        if(data.gte().has_value())
        {
            j["gte"] = data.gte().value();
        }
        if(data.range().has_value())
        {
            j["range"] = data.range().value();
        }
        if(data.oneOf().has_value())
        {
            j["oneOf"] = data.oneOf().value();
        }
        if(data.valid().has_value())
        {
            j["valid"] = data.valid().value();
        }
    }

    struct SelectionPredicate : public xp::xobserved<SelectionPredicate>
    {
        XPROPERTY(xtl::xoptional<stringObjectType>, SelectionPredicate, selection);
    };

    void to_json(nl::json& j, const SelectionPredicate& data)
    {
        if(data.selection().has_value())
        {
            j["selection"] = data.selection().value();
        }
    }

    typedef xtl::variant<std::string, FieldPredicate, SelectionPredicate> predicateType;

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

    typedef xtl::variant<Aggregate, std::string> aggType;
    typedef xtl::variant<std::string, bool, double, int, std::nullptr_t, TooltipContent> tooltipType;
    typedef xtl::variant<std::string, LinearGradient, RadialGradient> colorType;
    typedef xtl::variant<std::string, LinearGradient, RadialGradient, std::nullptr_t> colorNoneType;
}

#endif