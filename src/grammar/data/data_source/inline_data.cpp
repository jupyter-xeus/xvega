// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/data/data_source/inline_data.hpp"

namespace xv
{
    void to_json(nl::json& j, const inline_data& data)
    {
        j["values"] = data.values();
        serialize(j, data.name(), "name");
        serialize(j, data.format(), "format");
    }
}