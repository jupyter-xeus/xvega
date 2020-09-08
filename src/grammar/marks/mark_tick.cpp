// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_tick.hpp"

namespace xv
{
    mark_tick::mark_tick()
    {
        type = "tick";
    }

    void mark_tick::to_json(nl::json& j) const
    {
        base_type::to_json(j);
        // Fill in Tick Mark Properties
        serialize(j, cornerRadius(), "cornerRadius");
        serialize(j, orient(), "orient");
    }
}