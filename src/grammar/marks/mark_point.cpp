// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_point.hpp"
#include "../marks_private.hpp"

namespace xv
{
    mark_point::mark_point()
    {
        type = "point";
    }

    void to_json(nl::json& j, const mark_point& m)
    {
        private_to_json(m, j);
        // Fill in Point Mark Properties
        serialize(j, m.shape(), "shape");
        serialize(j, m.size(), "size");
    }
}
