// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/auto_size_params.hpp"

namespace xv
{
    void to_json(nl::json& j, const auto_size_params& data)
    {
        serialize(j, data.contains(), "contains");
        serialize(j, data.resize(), "resize");
        serialize(j, data.type(), "type");
    }
}