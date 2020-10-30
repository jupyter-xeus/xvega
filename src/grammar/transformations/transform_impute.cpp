// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/transformations/transform_impute.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const transform_impute& data)
    {
        serialize(j, data.impute(), "impute");
        serialize(j, data.key(), "key");
        serialize(j, data.keyvals(), "keyvals");
        serialize(j, data.groupby(), "groupby");
        serialize(j, data.frame(), "frame");
        serialize(j, data.method(), "method");
        serialize(j, data.value(), "value");
    }
}