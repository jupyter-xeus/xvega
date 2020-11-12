// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_line.hpp"
#include "../marks_private.hpp"

namespace xv
{
    mark_line::mark_line()
    {
        type = "line";
    }

    void to_json(nl::json& j, const mark_line& m)
    {
        private_to_json(m, j);
        // Fill in Line Mark Properties
        serialize(j, m.orient(), "orient");
        serialize(j, m.interpolate(), "interpolate");
        serialize(j, m.tension(), "tension");
        serialize(j, m.point(), "point");
    }
}
