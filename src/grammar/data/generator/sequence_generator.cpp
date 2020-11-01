// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/data/generator/sequence_generator.hpp"
#include "../../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const sequence_params& data)
    {
        serialize(j, data.start(), "start");
        serialize(j, data.stop(), "stop");
        serialize(j, data.step(), "step");
        serialize(j, data.as(), "as");
    }

    void to_json(nl::json& j, const sequence_generator& data)
    {
        serialize(j, data.sequence(), "sequence");
        serialize(j, data.name(), "name");
    }
}