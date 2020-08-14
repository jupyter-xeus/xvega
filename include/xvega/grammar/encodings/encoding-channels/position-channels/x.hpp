#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/axis.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/impute.hpp"
#include "../../encoding-channel-options/scale.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/stack.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

namespace nl = nlohmann;

namespace xv
{
    using stringVecNoneType = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct X : public xp::xobserved<X>
    {
        XPROPERTY(xtl::xoptional<aggType>, X, aggregate);
        XPROPERTY(xtl::xoptional<axisType>, X, axis);
        XPROPERTY(xtl::xoptional<double>, X, band);
        XPROPERTY(xtl::xoptional<binType>, X, bin);
        XPROPERTY(xtl::xoptional<fieldType>, X, field);
        XPROPERTY(xtl::xoptional<imputeType>, X, impute);
        XPROPERTY(xtl::xoptional<scaleType>, X, scale);
        XPROPERTY(xtl::xoptional<sortType>, X, sort);
        XPROPERTY(xtl::xoptional<stackType>, X, stack);
        XPROPERTY(xtl::xoptional<timeUnitType>, X, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, X, title);
        XPROPERTY(xtl::xoptional<std::string>, X, type);
    };

    void to_json(nl::json& j, const X& data)
    {
        if(data.aggregate().has_value())
        {
            j["aggregate"] = data.aggregate().value();
        }
        if(data.axis().has_value())
        {
            j["axis"] = data.axis().value();
        }
        if(data.band().has_value())
        {
            j["band"] = data.band().value();
        }
        if(data.bin().has_value())
        {
            j["bin"] = data.bin().value();
        }
        if(data.field().has_value())
        {
            j["field"] = data.field().value();
        }
        if(data.impute().has_value())
        {
            j["impute"] = data.impute().value();
        }
        if(data.scale().has_value())
        {
            j["scale"] = data.scale().value();
        }
        if(data.sort().has_value())
        {
            j["sort"] = data.sort().value();
        }
        if(data.stack().has_value())
        {
            j["stack"] = data.stack().value();
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