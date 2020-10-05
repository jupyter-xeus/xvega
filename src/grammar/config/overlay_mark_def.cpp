// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/overlay_mark_def.hpp"

namespace xv
{
    void overlay_mark_def::to_json(nl::json& j) const
    {
        base_type::to_json(j);

        serialize(j, clip(), "clip");
        serialize(j, style(), "style");
        serialize(j, xOffset(), "xOffset");
        serialize(j, x2Offset(), "x2Offset");
        serialize(j, yOffset(), "yOffset");
        serialize(j, y2Offset(), "y2Offset");
    }
}