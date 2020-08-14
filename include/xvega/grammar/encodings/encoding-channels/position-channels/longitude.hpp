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

    struct Longitude : public xp::xobserved<Longitude>
    {
        XPROPERTY(xtl::xoptional<aggType>, Longitude, aggregate);
        XPROPERTY(xtl::xoptional<binType>, Longitude, bin);
        XPROPERTY(xtl::xoptional<fieldType>, Longitude, field);
        XPROPERTY(xtl::xoptional<timeUnitType>, Longitude, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, Longitude, title);
        XPROPERTY(xtl::xoptional<std::string>, Longitude, type);
    };

    void to_json(nl::json& j, const Longitude& data)
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