// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_area.hpp"
#include "../marks_private.hpp"

namespace xv
{
    mark_area::mark_area()
    {
        type = "area";
    }

    void mark_area::to_json(nl::json& j) const
    {
        private_to_json(*this, j);
        // Fill in Area Mark Properties
        serialize(j, align(), "align");
        serialize(j, baseline(), "baseline");
        serialize(j, orient(), "orient");
        serialize(j, interpolate(), "interpolate");
        serialize(j, tension(), "tension");
        serialize(j, line(), "line");
        serialize(j, point(), "point");
    }
}
