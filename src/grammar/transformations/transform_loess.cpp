// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/transformations/transform_loess.hpp"

namespace xv
{
    void to_json(nl::json& j, const transform_loess& data)
    {
        serialize(j, data.loess(), "loess");
        serialize(j, data.on(), "on");
        serialize(j, data.groupby(), "groupby");
        serialize(j, data.bandwidth(), "bandwidth");
        serialize(j, data.as(), "as");
    }
}