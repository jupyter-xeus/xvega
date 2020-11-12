// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/selections/selection_multi.hpp"
#include "../selections_private.hpp"

namespace xv
{
    selection_multi::selection_multi()
    {
        name = "selector_multi_" + random_string(5);
        type = "multi";
    }

    void to_json(nl::json& j, const selection_multi& m)
    {
        private_to_json(m, j);
        serialize(j, m.init(), "init");
        serialize(j, m.bind(), "bind");
        serialize(j, m.nearest(), "nearest");
        serialize(j, m.toggle(), "toggle");
    }
}
