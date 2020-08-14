#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

namespace nl = nlohmann;

namespace xv
{
    using stringVecNoneType = xtl::variant<std::vector<std::string>, std::nullptr_t>;
    using stringObjectType = xtl::variant<nl::json, std::string>;

    struct Href : public xp::xobserved<Href>
    {
        XPROPERTY(xtl::xoptional<aggType>, Href, aggregate);
        XPROPERTY(xtl::xoptional<binType>, Href, bin);
        // XPROPERTY(xtl::xoptional<conditionType>, Href, condition);
        XPROPERTY(xtl::xoptional<fieldType>, Href, field);
        XPROPERTY(xtl::xoptional<stringObjectType>, Href, format);
        XPROPERTY(xtl::xoptional<std::string>, Href, formatType);
        XPROPERTY(xtl::xoptional<std::string>, Href, labelExpr);
        XPROPERTY(xtl::xoptional<timeUnitType>, Href, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, Href, title);
        XPROPERTY(xtl::xoptional<std::string>, Href, type);
    };

    void to_json(nl::json& j, const Href& data)
    {
        if(data.aggregate().has_value())
        {
            j["aggregate"] = data.aggregate().value();
        }
        if(data.bin().has_value())
        {
            j["bin"] = data.bin().value();
        }
        // if(data.condition().has_value())
        // {
        //     j["condition"] = data.condition().value();
        // }
        if(data.field().has_value())
        {
            j["field"] = data.field().value();
        }
        if(data.format().has_value())
        {
            j["format"] = data.format().value();
        }
        if(data.formatType().has_value())
        {
            j["formatType"] = data.formatType().value();
        }
        if(data.labelExpr().has_value())
        {
            j["labelExpr"] = data.labelExpr().value();
        }
        if(data.timeUnit().has_value())
        {
            j["timeUnit"] = data.timeUnit().value();
        }
        if(data.title().has_value())
        {
            j["title"] = data.title().value();
        }
        if(data.type().has_value())
        {
            j["type"] = data.type().value();
        }
    }
}