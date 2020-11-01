// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/data/generator/sphere_generator.hpp"
#include "../../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const sphere_generator& data)
    {
        serialize(j, data.sphere(), "sphere");
        serialize(j, data.name(), "name");
    }
}