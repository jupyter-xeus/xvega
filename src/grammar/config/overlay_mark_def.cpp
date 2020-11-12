// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/overlay_mark_def.hpp"
#include "base_config_private.hpp"

namespace xv
{
    void to_json(nl::json& j, const overlay_mark_def& c)
    {
        private_to_json(c, j);

        serialize(j, c.clip(), "clip");
        serialize(j, c.style(), "style");
        serialize(j, c.xOffset(), "xOffset");
        serialize(j, c.x2Offset(), "x2Offset");
        serialize(j, c.yOffset(), "yOffset");
        serialize(j, c.y2Offset(), "y2Offset");
    }
}
