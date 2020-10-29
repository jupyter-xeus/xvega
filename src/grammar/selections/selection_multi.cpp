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
        if(!name().has_value())
        {
            name = "selector_multi_" + random_string(5);
        }
        type = "multi";
    }

    void selection_multi::to_json(nl::json& j) const
    {
        private_to_json(*this, j);
        serialize(j, init(), "init");
        serialize(j, bind(), "bind");
        serialize(j, nearest(), "nearest");
        serialize(j, toggle(), "toggle");
    }
}