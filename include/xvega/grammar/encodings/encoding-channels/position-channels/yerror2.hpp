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

    struct YError2 : public xp::xobserved<YError2>
    {
        XPROPERTY(xtl::xoptional<aggType>, YError2, aggregate);
        XPROPERTY(xtl::xoptional<binType>, YError2, bin);
        XPROPERTY(xtl::xoptional<fieldType>, YError2, field);
        XPROPERTY(xtl::xoptional<timeUnitType>, YError2, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, YError2, title);
    };

    void to_json(nl::json& j, const YError2& data)
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
    }
}