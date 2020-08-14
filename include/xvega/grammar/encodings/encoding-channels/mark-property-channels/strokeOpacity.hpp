// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

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

    struct StrokeOpacity : public xp::xobserved<StrokeOpacity>
    {
        XPROPERTY(xtl::xoptional<aggType>, StrokeOpacity, aggregate);
        XPROPERTY(xtl::xoptional<binType>, StrokeOpacity, bin);
        // XPROPERTY(xtl::xoptional<conditionType>, StrokeOpacity, condition);
        XPROPERTY(xtl::xoptional<fieldType>, StrokeOpacity, field);
        XPROPERTY(xtl::xoptional<legendType>, StrokeOpacity, legend);
        XPROPERTY(xtl::xoptional<scaleType>, StrokeOpacity, scale);
        XPROPERTY(xtl::xoptional<sortType>, StrokeOpacity, sort);
        XPROPERTY(xtl::xoptional<timeUnitType>, StrokeOpacity, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, StrokeOpacity, title);
        XPROPERTY(xtl::xoptional<std::string>, StrokeOpacity, type);
    };

    void to_json(nl::json& j, const StrokeOpacity& data)
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