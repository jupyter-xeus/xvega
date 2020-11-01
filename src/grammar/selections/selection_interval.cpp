// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/selections/selection_interval.hpp"
#include "../selections_private.hpp"

namespace xv
{
    selection_interval::selection_interval()
    {
        if(!name().has_value())
        {
            name = "selector_interval_" + random_string(5);
        }
        type = "interval";
    }

    void selection_interval::to_json(nl::json& j) const
    {
        private_to_json(*this, j);
        serialize(j, bind(), "bind");
        serialize(j, init(), "init");
        serialize(j, mark(), "mark");
        serialize(j, translate(), "translate");
        serialize(j, zoom(), "zoom");
    }
}