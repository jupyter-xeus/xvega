// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_line.hpp"

namespace xv
{
    mark_line::mark_line()
    {
        type = "line";
    }

    void mark_line::to_json(nl::json& j) const
    {
        base_type::to_json(j);
        // Fill in Line Mark Properties
        serialize(j, orient(), "orient");
        serialize(j, interpolate(), "interpolate");
        serialize(j, tension(), "tension");
        serialize(j, point(), "point");
    }
}