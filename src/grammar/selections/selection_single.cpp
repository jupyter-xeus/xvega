// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/selections/selection_single.hpp"

namespace xv
{
    selection_single::selection_single()
    {
        if(!name().has_value())
        {
            name = "selector_single_" + random_string(5);
        }
        type = "single";
    }

    void selection_single::to_json(nl::json& j) const
    {
        base_type::to_json(j);
        serialize(j, init(), "init");
        serialize(j, bind(), "bind");
        serialize(j, nearest(), "nearest");
    }
}