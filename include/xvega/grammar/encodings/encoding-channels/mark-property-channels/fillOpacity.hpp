#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/legend.hpp"
#include "../../encoding-channel-options/scale.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

namespace nl = nlohmann;

namespace xv
{
    using stringVecNoneType = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct FillOpacity : public xp::xobserved<FillOpacity>
    {
        XPROPERTY(xtl::xoptional<aggType>, FillOpacity, aggregate);
        XPROPERTY(xtl::xoptional<binType>, FillOpacity, bin);
        // XPROPERTY(xtl::xoptional<conditionType>, FillOpacity, condition);
        XPROPERTY(xtl::xoptional<fieldType>, FillOpacity, field);
        XPROPERTY(xtl::xoptional<legendType>, FillOpacity, legend);
        XPROPERTY(xtl::xoptional<scaleType>, FillOpacity, scale);
        XPROPERTY(xtl::xoptional<sortType>, FillOpacity, sort);
        XPROPERTY(xtl::xoptional<timeUnitType>, FillOpacity, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, FillOpacity, title);
        XPROPERTY(xtl::xoptional<std::string>, FillOpacity, type);
    };

    void to_json(nl::json& j, const FillOpacity& data)
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
        if(data.legend().has_value())
        {
            j["legend"] = data.legend().value();
        }
        if(data.scale().has_value())
        {
            j["scale"] = data.scale().value();
        }
        if(data.sort().has_value())
        {
            j["sort"] = data.sort().value();
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