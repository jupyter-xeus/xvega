// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/transformations/transform_regression.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const transform_regression& data)
    {
        serialize(j, data.regression(), "regression");
        serialize(j, data.on(), "on");
        serialize(j, data.groupby(), "groupby");
        serialize(j, data.method(), "method");
        serialize(j, data.order(), "order");
        serialize(j, data.extent(), "extent");
        serialize(j, data.params(), "params");
        serialize(j, data.as(), "as");
    }
}