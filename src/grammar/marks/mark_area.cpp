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

    void to_json(nl::json& j, const mark_area& m)
    {
        private_to_json(m, j);
        // Fill in Area Mark Properties
        serialize(j, m.align(), "align");
        serialize(j, m.baseline(), "baseline");
        serialize(j, m.orient(), "orient");
        serialize(j, m.interpolate(), "interpolate");
        serialize(j, m.tension(), "tension");
        serialize(j, m.line(), "line");
        serialize(j, m.point(), "point");
    }
}
