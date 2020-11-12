// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_circle.hpp"
#include "../marks_private.hpp"

namespace xv
{
    mark_circle::mark_circle()
    {
        type = "circle";
    }

    void to_json(nl::json& j, const mark_circle& m)
    {
        private_to_json(m, j);
        // Fill in Circle Mark Properties
        serialize(j, m.size(), "size");
    }
}
