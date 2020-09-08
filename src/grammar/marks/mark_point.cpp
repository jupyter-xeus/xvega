// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_point.hpp"

namespace xv
{
    mark_point::mark_point()
    {
        type = "point";
    }

    void mark_point::to_json(nl::json& j) const
    {
        base_type::to_json(j);
        // Fill in Point Mark Properties
        serialize(j, shape(), "shape");
        serialize(j, size(), "size");
    }
}