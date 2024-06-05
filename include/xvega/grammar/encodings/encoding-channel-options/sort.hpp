// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_SORT_HPP
#define XVEGA_ENCODING_OPTIONS_SORT_HPP

#include <optional>
#include <variant>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "./datetime.hpp"
#include "./field.hpp"
#include "../../../xvega_config.hpp"
#include "../../../utils/custom_datatypes.hpp"


namespace nl = nlohmann;

namespace xv
{
    struct FieldSort : public xp::xobserved<FieldSort>
    {
        XPROPERTY(std::optional<field_type>, FieldSort, field);
        XPROPERTY(std::optional<std::string>, FieldSort, op);
        XPROPERTY(std::optional<string_none_type>, FieldSort, order);
    };

    XVEGA_API void to_json(nl::json& j, const FieldSort& data);

    struct EncodingSort : public xp::xobserved<EncodingSort>
    {
        XPROPERTY(std::optional<std::string>, EncodingSort, encoding);
        XPROPERTY(std::optional<string_none_type>, EncodingSort, order);
    };

    XVEGA_API void to_json(nl::json& j, const EncodingSort& data);

    using sort_type = std::variant<any_array_type, std::string, std::nullptr_t, FieldSort, EncodingSort>;
}

#endif
