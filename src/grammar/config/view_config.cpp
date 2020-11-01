// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/view_config.hpp"

namespace xv
{
    void to_json(nl::json& j, const view_config& data)
    {
        serialize(j, data.clip(), "clip");
        serialize(j, data.continuousHeight(), "continuousHeight");
        serialize(j, data.continuousWidth(), "continuousWidth");
        serialize(j, data.cornerRadius(), "cornerRadius");
        serialize(j, data.cursor(), "cursor");
        serialize(j, data.discreteHeight(), "discreteHeight");
        serialize(j, data.discreteWidth(), "discreteWidth");
        serialize(j, data.fill(), "fill");
        serialize(j, data.fillOpacity(), "fillOpacity");
        serialize(j, data.height(), "height");
        serialize(j, data.opacity(), "opacity");
        serialize(j, data.step(), "step");
        serialize(j, data.stroke(), "stroke");
        serialize(j, data.strokeCap(), "strokeCap");
        serialize(j, data.strokeDash(), "strokeDash");
        serialize(j, data.strokeDashOffset(), "strokeDashOffset");
        serialize(j, data.strokeJoin(), "strokeJoin");
        serialize(j, data.strokeMiterLimit(), "strokeMiterLimit");
        serialize(j, data.strokeOpacity(), "strokeOpacity");
        serialize(j, data.strokeWidth(), "strokeWidth");
        serialize(j, data.width(), "width");
    }
}
