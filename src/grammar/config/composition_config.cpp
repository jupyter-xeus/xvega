// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/composition_config.hpp"

namespace xv
{
    void to_json(nl::json& j, const composition_config& data)
    {
        serialize(j, data.columns(), "columns");
        serialize(j, data.spacing(), "spacing");
    }
}
