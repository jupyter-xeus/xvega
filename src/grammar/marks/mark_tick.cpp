// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_tick.hpp"
#include "../marks_private.hpp"

namespace xv
{
    mark_tick::mark_tick()
    {
        type = "tick";
    }

    void to_json(nl::json& j, const mark_tick& m)
    {
        private_to_json(m, j);
        // Fill in Tick Mark Properties
        serialize(j, m.cornerRadius(), "cornerRadius");
        serialize(j, m.orient(), "orient");
    }
}
