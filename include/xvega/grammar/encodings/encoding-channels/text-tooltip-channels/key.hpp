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

    struct Key : public xp::xobserved<Key>
    {
        XPROPERTY(xtl::xoptional<aggType>, Key, aggregate);
        XPROPERTY(xtl::xoptional<binType>, Key, bin);
        XPROPERTY(xtl::xoptional<fieldType>, Key, field);
        XPROPERTY(xtl::xoptional<timeUnitType>, Key, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, Key, title);
        XPROPERTY(xtl::xoptional<std::string>, Key, type);
    };

    void to_json(nl::json& j, const Key& data)
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