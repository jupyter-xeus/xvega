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

    void mark_arc::to_json(nl::json& j) const
    {
        private_to_json(*this, j);
        // Fill in Arc Mark Properties
        serialize(j, radius(), "radius");
        serialize(j, radius2(), "radius2");
        serialize(j, innerRadius(), "innerRadius");
        serialize(j, outerRadius(), "outerRadius");
        serialize(j, theta(), "theta");
        serialize(j, theta2(), "theta2");
        serialize(j, cornerRadius(), "cornerRadius");
        serialize(j, padAngle(), "padAngle");
        serialize(j, radiusOffset(), "radiusOffset");
        serialize(j, radius2Offset(), "radius2Offset");
        serialize(j, thetaOffset(), "thetaOffset");
        serialize(j, theta2Offset(), "theta2Offset");
    }
}
