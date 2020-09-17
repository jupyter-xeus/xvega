// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/transformations/transform_pivot.hpp"

namespace xv
{
    void to_json(nl::json& j, const transform_pivot& data)
    {
        serialize(j, data.pivot(), "pivot");
        serialize(j, data.value(), "value");
        serialize(j, data.groupby(), "groupby");
        serialize(j, data.limit(), "limit");
        serialize(j, data.op(), "op");
    }
}