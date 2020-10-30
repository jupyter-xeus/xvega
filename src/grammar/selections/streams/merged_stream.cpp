// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/selections/streams/merged_stream.hpp"
#include "../../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const merged_stream& data)
    {
        serialize(j, data.merge(), "merge");
        serialize(j, data.between(), "between");
        serialize(j, data.consume(), "consume");
        serialize(j, data.filter(), "filter");
        serialize(j, data.debounce(), "debounce");
        serialize(j, data.markname(), "markname");
        serialize(j, data.marktype(), "marktype");
        serialize(j, data.throttle(), "throttle");
    }
}