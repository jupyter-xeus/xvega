// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/selections/selection_single.hpp"
#include "../selections_private.hpp"

namespace xv
{
    selection_single::selection_single()
    {
        name = "selector_single_" + random_string(5);
        type = "single";
    }

    void to_json(nl::json& j, const selection_single& m)
    {
        private_to_json(m, j);
        serialize(j, m.init(), "init");
        serialize(j, m.bind(), "bind");
        serialize(j, m.nearest(), "nearest");
    }
}
