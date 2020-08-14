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

    struct Facet : public xp::xobserved<Facet>
    {
        XPROPERTY(xtl::xoptional<aggType>, Facet, aggregate);
        XPROPERTY(xtl::xoptional<std::string>, Facet, align);
        XPROPERTY(xtl::xoptional<binType>, Facet, bin);
        XPROPERTY(xtl::xoptional<std::string>, Facet, bounds);
        XPROPERTY(xtl::xoptional<bool>, Facet, center);
        XPROPERTY(xtl::xoptional<double>, Facet, columns);
        XPROPERTY(xtl::xoptional<fieldType>, Facet, field);
        XPROPERTY(xtl::xoptional<Header>, Facet, header);
        XPROPERTY(xtl::xoptional<sortType>, Facet, sort);
        XPROPERTY(xtl::xoptional<double>, Facet, spacing);
        XPROPERTY(xtl::xoptional<timeUnitType>, Facet, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, Facet, title);
        XPROPERTY(xtl::xoptional<std::string>, Facet, type);
    };

    void to_json(nl::json& j, const Facet& data)
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
        if(data.bounds().has_value())
        {
            j["bounds"] = data.bounds().value();
        }
        if(data.center().has_value())
        {
            j["center"] = data.center().value();
        }
        if(data.columns().has_value())
        {
            j["columns"] = data.columns().value();
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