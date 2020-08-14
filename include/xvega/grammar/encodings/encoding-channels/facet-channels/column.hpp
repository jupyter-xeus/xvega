#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/header.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

namespace nl = nlohmann;

namespace xv
{
    using stringVecNoneType = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct Column : public xp::xobserved<Column>
    {
        XPROPERTY(xtl::xoptional<aggType>, Column, aggregate);
        XPROPERTY(xtl::xoptional<std::string>, Column, align);
        XPROPERTY(xtl::xoptional<binType>, Column, bin);
        XPROPERTY(xtl::xoptional<bool>, Column, center);
        XPROPERTY(xtl::xoptional<fieldType>, Column, field);
        XPROPERTY(xtl::xoptional<Header>, Column, header);
        XPROPERTY(xtl::xoptional<sortType>, Column, sort);
        XPROPERTY(xtl::xoptional<double>, Column, spacing);
        XPROPERTY(xtl::xoptional<timeUnitType>, Column, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, Column, title);
        XPROPERTY(xtl::xoptional<std::string>, Column, type);
    };

    void to_json(nl::json& j, const Column& data)
    {
        if(data.aggregate().has_value())
        {
            j["aggregate"] = data.aggregate().value();
        }
        if(data.align().has_value())
        {
            j["align"] = data.align().value();
        }
        if(data.bin().has_value())
        {
            j["bin"] = data.bin().value();
        }
        if(data.center().has_value())
        {
            j["center"] = data.center().value();
        }
        if(data.field().has_value())
        {
            j["field"] = data.field().value();
        }
        if(data.header().has_value())
        {
            j["header"] = data.header().value();
        }
        if(data.sort().has_value())
        {
            j["sort"] = data.sort().value();
        }
        if(data.spacing().has_value())
        {
            j["spacing"] = data.spacing().value();
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