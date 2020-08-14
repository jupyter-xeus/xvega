#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/timeunit.hpp"

namespace nl = nlohmann;

namespace xv
{
    using stringVecNoneType = xtl::variant<std::vector<std::string>, std::nullptr_t>;
    using stringObjectType = xtl::variant<nl::json, std::string>;

    struct Tooltip : public xp::xobserved<Tooltip>
    {
        XPROPERTY(xtl::xoptional<aggType>, Tooltip, aggregate);
        XPROPERTY(xtl::xoptional<binType>, Tooltip, bin);
        // XPROPERTY(xtl::xoptional<conditionType>, Tooltip, condition);
        XPROPERTY(xtl::xoptional<fieldType>, Tooltip, field);
        XPROPERTY(xtl::xoptional<stringObjectType>, Tooltip, format);
        XPROPERTY(xtl::xoptional<std::string>, Tooltip, formatType);
        XPROPERTY(xtl::xoptional<std::string>, Tooltip, labelExpr);
        XPROPERTY(xtl::xoptional<timeUnitType>, Tooltip, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, Tooltip, title);
        XPROPERTY(xtl::xoptional<std::string>, Tooltip, type);
    };

    void to_json(nl::json& j, const Tooltip& data)
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