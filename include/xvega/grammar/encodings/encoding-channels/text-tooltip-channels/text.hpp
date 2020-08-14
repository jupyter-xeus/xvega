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
#include "../../encoding-channel-options/timeunit.hpp"

namespace nl = nlohmann;

namespace xv
{
    using stringVecNoneType = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct Text : public xp::xobserved<Text>
    {
        XPROPERTY(xtl::xoptional<aggType>, Text, aggregate);
        XPROPERTY(xtl::xoptional<binType>, Text, bin);
        // XPROPERTY(xtl::xoptional<conditionType>, Text, condition);
        XPROPERTY(xtl::xoptional<fieldType>, Text, field);
        XPROPERTY(xtl::xoptional<stringObjectType>, Text, format);
        XPROPERTY(xtl::xoptional<std::string>, Text, formatType);
        XPROPERTY(xtl::xoptional<std::string>, Text, labelExpr);
        XPROPERTY(xtl::xoptional<timeUnitType>, Text, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, Text, title);
        XPROPERTY(xtl::xoptional<std::string>, Text, type);
    };

    void to_json(nl::json& j, const Text& data)
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