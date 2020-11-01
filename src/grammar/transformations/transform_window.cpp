// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/transformations/transform_window.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const window_field_def& data)
    {
        serialize(j, data.op(), "op");
        serialize(j, data.field(), "field");
        serialize(j, data.param(), "param");
        serialize(j, data.as(), "as");
    }

    void to_json(nl::json& j, const transform_window& data)
    {
        serialize(j, data.window(), "window");
        serialize(j, data.frame(), "frame");
        serialize(j, data.ignorePeers(), "ignorePeers");
        serialize(j, data.groupby(), "groupby");
        serialize(j, data.sort(), "sort");
    }
}