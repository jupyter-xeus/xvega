// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_CONDITION_HPP
#define XVEGA_ENCODING_OPTIONS_CONDITION_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "./timeunit.hpp"
#include "./datetime.hpp"

namespace nl = nlohmann;

namespace xv
{

    using fieldPredicateEqualType = xtl::variant<std::string, double, int, bool, DateTime>;
    using fieldPredicateType = xtl::variant<std::string, double, int, DateTime>;
    using fieldPredicateRangeType = xtl::variant<std::vector<double>, std::vector<int>, std::vector<DateTime>, std::vector<std::nullptr_t>>;
    using anyArrayType = xtl::variant<std::vector<std::string>, std::vector<double>, std::vector<int>, std::vector<bool>, std::vector<DateTime>>;

    struct FieldPredicate : public xp::xobserved<FieldPredicate>
    {
        XPROPERTY(xtl::xoptional<std::string>, FieldPredicate, field);
        XPROPERTY(xtl::xoptional<TimeUnit>, FieldPredicate, timeUnit);
        XPROPERTY(xtl::xoptional<fieldPredicateEqualType>, FieldPredicate, equal);
        XPROPERTY(xtl::xoptional<fieldPredicateType>, FieldPredicate, lt);
        XPROPERTY(xtl::xoptional<fieldPredicateType>, FieldPredicate, lte);
        XPROPERTY(xtl::xoptional<fieldPredicateType>, FieldPredicate, gt);
        XPROPERTY(xtl::xoptional<fieldPredicateType>, FieldPredicate, gte);
        XPROPERTY(xtl::xoptional<fieldPredicateRangeType>, FieldPredicate, range);
        XPROPERTY(xtl::xoptional<anyArrayType>, FieldPredicate, oneOf);
        XPROPERTY(xtl::xoptional<bool>, FieldPredicate, valid);
    };

    void to_json(nl::json& j, const FieldPredicate& data)
    {
        if(data.field().has_value())
        {
            j["field"] = data.field().value();
        }
        if(data.timeUnit().has_value())
        {
            j["timeUnit"] = data.timeUnit().value();
        }
        if(data.equal().has_value())
        {
            j["equal"] = data.equal().value();
        }
        if(data.lt().has_value())
        {
            j["lt"] = data.lt().value();
        }
        if(data.lte().has_value())
        {
            j["lte"] = data.lte().value();
        }
        if(data.gt().has_value())
        {
            j["gt"] = data.gt().value();
        }
        if(data.gte().has_value())
        {
            j["gte"] = data.gte().value();
        }
        if(data.range().has_value())
        {
            j["range"] = data.range().value();
        }
        if(data.oneOf().has_value())
        {
            j["oneOf"] = data.oneOf().value();
        }
        if(data.valid().has_value())
        {
            j["valid"] = data.valid().value();
        }
    }

    struct SelectionPredicate : public xp::xobserved<SelectionPredicate>
    {
        XPROPERTY(xtl::xoptional<stringObjectType>, SelectionPredicate, selection);
    };

    void to_json(nl::json& j, const SelectionPredicate& data)
    {
        if(data.selection().has_value())
        {
            j["selection"] = data.selection().value();
        }
    }

    typedef xtl::variant<std::string, FieldPredicate, SelectionPredicate> predicateType;
}

#endif