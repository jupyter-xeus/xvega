// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/transformations/transform_quantile.hpp"

namespace xv
{
    void to_json(nl::json& j, const transform_quantile& data)
    {
        serialize(j, data.quantile(), "quantile");
        serialize(j, data.groupby(), "groupby");
        serialize(j, data.probs(), "probs");
        serialize(j, data.step(), "step");
        serialize(j, data.as(), "as");
    }
}