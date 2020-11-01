// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/encodings/encoding-channels/position-channels/y.hpp"
#include "../../../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const Y& data)
    {
        serialize(j, data.aggregate(), "aggregate");
        serialize(j, data.axis(), "axis");
        serialize(j, data.band(), "band");
        serialize(j, data.bin(), "bin");
        serialize(j, data.field(), "field");
        serialize(j, data.impute(), "impute");
        serialize(j, data.scale(), "scale");
        serialize(j, data.sort(), "sort");
        serialize(j, data.stack(), "stack");
        serialize(j, data.timeUnit(), "timeUnit");
        serialize(j, data.title(), "title");
        serialize(j, data.type(), "type");
    }
}