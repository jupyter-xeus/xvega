// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_trail.hpp"

namespace xv
{
    mark_trail::mark_trail()
    {
        type = "trail";
    }

    void mark_trail::to_json(nl::json& j) const
    {
        base_type::to_json(j);
        // Fill in Trail Mark Properties
        serialize(j, orient(), "orient");
    }
}