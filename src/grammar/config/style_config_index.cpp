// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/style_config_index.hpp"

namespace xv
{
    void to_json(nl::json& j, const style_config_index& data)
    {
        serialize(j, data.area(), "area");
        serialize(j, data.bar(), "bar");
        serialize(j, data.circle(), "circle");
        serialize(j, data.geoshape(), "geoshape");
        serialize(j, data.image(), "image");
        serialize(j, data.line(), "line");
        serialize(j, data.mark(), "mark");
        serialize(j, data.point(), "point");
        serialize(j, data.rect(), "rect");
        serialize(j, data.rule(), "rule");
        serialize(j, data.square(), "square");
        serialize(j, data.text(), "text");
        serialize(j, data.tick(), "tick");
        serialize(j, data.trail(), "trail");
        serialize(j, data.group_subtitle(), "group-subtitle");
        serialize(j, data.group_title(), "group-title");
        serialize(j, data.guide_label(), "guide-label");
        serialize(j, data.guide_title(), "guide-title");
    }
}