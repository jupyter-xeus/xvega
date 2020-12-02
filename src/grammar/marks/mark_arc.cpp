// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_arc.hpp"
#include "../marks_private.hpp"

namespace xv
{
    mark_arc::mark_arc()
    {
        type = "arc";
    }

    void to_json(nl::json& j, const mark_arc& m)
    {
        private_to_json(m, j);
        // Fill in Arc Mark Properties
        serialize(j, m.radius(), "radius");
        serialize(j, m.radius2(), "radius2");
        serialize(j, m.innerRadius(), "innerRadius");
        serialize(j, m.outerRadius(), "outerRadius");
        serialize(j, m.theta(), "theta");
        serialize(j, m.theta2(), "theta2");
        serialize(j, m.cornerRadius(), "cornerRadius");
        serialize(j, m.padAngle(), "padAngle");
        serialize(j, m.radiusOffset(), "radiusOffset");
        serialize(j, m.radius2Offset(), "radius2Offset");
        serialize(j, m.thetaOffset(), "thetaOffset");
        serialize(j, m.theta2Offset(), "theta2Offset");
    }
}
