// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/encodings/encoding-channel-options/repeatRef.hpp"

namespace xv
{
    void to_json(nl::json& j, const RepeatRef& data)
    {
        serialize(j, data.repeat(), "repeat");
    }
}