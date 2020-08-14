#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

namespace nl = nlohmann;

namespace xv
{
    using stringVecNoneType = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct Order : public xp::xobserved<Order>
    {
        XPROPERTY(xtl::xoptional<aggType>, Order, aggregate);
        XPROPERTY(xtl::xoptional<binType>, Order, bin);
        XPROPERTY(xtl::xoptional<fieldType>, Order, field);
        XPROPERTY(xtl::xoptional<sortType>, Order, sort);
        XPROPERTY(xtl::xoptional<timeUnitType>, Order, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, Order, title);
        XPROPERTY(xtl::xoptional<std::string>, Order, type);
    };

    void to_json(nl::json& j, const Order& data)
    {
        if(data.aggregate().has_value())
        {
            j["aggregate"] = data.aggregate().value();
        }
        if(data.bin().has_value())
        {
            j["bin"] = data.bin().value();
        }
        if(data.field().has_value())
        {
            j["field"] = data.field().value();
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