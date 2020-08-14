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

    struct Y : public xp::xobserved<Y>
    {
        XPROPERTY(xtl::xoptional<aggType>, Y, aggregate);
        XPROPERTY(xtl::xoptional<axisType>, Y, axis);
        XPROPERTY(xtl::xoptional<double>, Y, band);
        XPROPERTY(xtl::xoptional<binType>, Y, bin);
        XPROPERTY(xtl::xoptional<fieldType>, Y, field);
        XPROPERTY(xtl::xoptional<imputeType>, Y, impute);
        XPROPERTY(xtl::xoptional<scaleType>, Y, scale);
        XPROPERTY(xtl::xoptional<sortType>, Y, sort);
        XPROPERTY(xtl::xoptional<stackType>, Y, stack);
        XPROPERTY(xtl::xoptional<timeUnitType>, Y, timeUnit);
        XPROPERTY(xtl::xoptional<stringVecNoneType>, Y, title);
        XPROPERTY(xtl::xoptional<std::string>, Y, type);
    };

    void to_json(nl::json& j, const Y& data)
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