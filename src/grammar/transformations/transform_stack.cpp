// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/transformations/transform_stack.hpp"

namespace xv
{
    void to_json(nl::json& j, const sort_field_def& data)
    {
        serialize(j, data.field(), "field");
        serialize(j, data.order(), "order");
    }

    void to_json(nl::json& j, const transform_stack& data)
    {
        serialize(j, data.stack(), "stack");
        serialize(j, data.groupby(), "groupby");
        serialize(j, data.offset(), "offset");
        serialize(j, data.sort(), "sort");
        serialize(j, data.as(), "as");
    }
}