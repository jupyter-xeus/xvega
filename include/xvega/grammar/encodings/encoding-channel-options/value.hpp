// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_VALUE_HPP
#define XVEGA_ENCODING_OPTIONS_VALUE_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../../xvega_config.hpp"
#include "../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Value
    {
        std::optional<any_type> value;

        Value(any_type val);
    };

    XVEGA_API void to_json(nl::json& j, const Value& data);
}

#endif
