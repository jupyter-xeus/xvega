// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/encodings/encoding-channel-options/value.hpp"
#include "../../../utils/serialize.hpp"

namespace xv
{
    Value::Value(any_type val)
    {
        value = val;
    }

    void to_json(nl::json& j, const Value& data)
    {
        serialize(j, data.value, "value");
    }
}