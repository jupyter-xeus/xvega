// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_VALUE_HPP
#define XVEGA_ENCODING_OPTIONS_VALUE_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../../utils/serialize.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    using any_type = xtl::variant<std::string, bool, double, int, std::nullptr_t>;

    struct Value
    {
        xtl::xoptional<any_type> value;

        Value(any_type val);
    };

    XVEGA_API void to_json(nl::json& j, const Value& data);
}

#endif