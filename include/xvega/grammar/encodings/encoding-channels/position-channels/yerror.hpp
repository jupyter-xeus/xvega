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

    struct YError : public xp::xobserved<YError>
    {
        XPROPERTY(xtl::xoptional<aggType>, YError, aggregate);
        XPROPERTY(xtl::xoptional<binType>, YError, bin);
        XPROPERTY(xtl::xoptional<fieldType>, YError, field);
        XPROPERTY(xtl::xoptional<timeUnitType>, YError, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, YError, title);
    };

    void to_json(nl::json& j, const YError& data)
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