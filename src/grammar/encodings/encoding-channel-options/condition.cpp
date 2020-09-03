// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/encodings/encoding-channel-options/condition.hpp"

namespace xv
{
    void to_json(nl::json& j, const FieldPredicate& data)
    {
        serialize(j, data.field(), "field");
        serialize(j, data.timeUnit(), "timeUnit");
        serialize(j, data.equal(), "equal");
        serialize(j, data.lt(), "lt");
        serialize(j, data.lte(), "lte");
        serialize(j, data.gt(), "gt");
        serialize(j, data.gte(), "gte");
        serialize(j, data.range(), "range");
        serialize(j, data.oneOf(), "oneOf");
        serialize(j, data.valid(), "valid");
    }

    void to_json(nl::json& j, const SelectionPredicate& data)
    {
        serialize(j, data.selection(), "selection");
    }
}