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
        name = "selector_interval_" + random_string(5);
        type = "interval";
    }

    void to_json(nl::json& j, const selection_interval& m)
    {
        private_to_json(m, j);
        serialize(j, m.bind(), "bind");
        serialize(j, m.init(), "init");
        serialize(j, m.mark(), "mark");
        serialize(j, m.translate(), "translate");
        serialize(j, m.zoom(), "zoom");
    }
}
