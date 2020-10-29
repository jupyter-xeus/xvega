// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_square.hpp"
#include "../marks_private.hpp"

namespace xv
{
    mark_square::mark_square()
    {
        type = "square";
    }

    void mark_square::to_json(nl::json& j) const
    {
        private_to_json(*this, j);
        // Fill in Square Mark Properties
        serialize(j, size(), "size");
    }
}
