// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_CONDITION_HPP
#define XVEGA_ENCODING_OPTIONS_CONDITION_HPP

#include <optional>
#include <variant>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "./timeunit.hpp"
#include "./datetime.hpp"

#include "../../../xvega_config.hpp"
#include "../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    using field_predicate_equal_type = std::variant<std::string, double, int, bool, DateTime>;
    using field_predicate_type = std::variant<std::string, double, int, DateTime>;
    using field_predicate_range_type = std::variant<
                                            std::vector<double>, 
                                            std::vector<int>, 
                                            std::vector<DateTime>, 
                                            std::vector<std::nullptr_t>
                                            >;

    struct FieldPredicate : public xp::xobserved<FieldPredicate>
    {
        XPROPERTY(std::optional<std::string>, FieldPredicate, field);
        XPROPERTY(std::optional<TimeUnit>, FieldPredicate, timeUnit);
        XPROPERTY(std::optional<field_predicate_equal_type>, FieldPredicate, equal);
        XPROPERTY(std::optional<field_predicate_type>, FieldPredicate, lt);
        XPROPERTY(std::optional<field_predicate_type>, FieldPredicate, lte);
        XPROPERTY(std::optional<field_predicate_type>, FieldPredicate, gt);
        XPROPERTY(std::optional<field_predicate_type>, FieldPredicate, gte);
        XPROPERTY(std::optional<field_predicate_range_type>, FieldPredicate, range);
        XPROPERTY(std::optional<any_array_type>, FieldPredicate, oneOf);
        XPROPERTY(std::optional<bool>, FieldPredicate, valid);
    };

    XVEGA_API void to_json(nl::json& j, const FieldPredicate& data);

    struct SelectionPredicate : public xp::xobserved<SelectionPredicate>
    {
        XPROPERTY(std::optional<string_object_type>, SelectionPredicate, selection);
    };

    XVEGA_API void to_json(nl::json& j, const SelectionPredicate& data);

    using predicate_type = std::variant<std::string, FieldPredicate, SelectionPredicate>;
}

#endif
