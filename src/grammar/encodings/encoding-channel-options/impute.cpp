// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/encodings/encoding-channel-options/impute.hpp"

namespace xv
{
    void to_json(nl::json& j, const ImputeSequence& data)
    {
        serialize(j, data.start(), "start");
        serialize(j, data.stop(), "stop");
        serialize(j, data.step(), "step");
    }

    void to_json(nl::json& j, const Impute& data)
    {
        serialize(j, data.frame(), "frame");
        serialize(j, data.keyvals(), "keyvals");
        serialize(j, data.method(), "method");
        serialize(j, data.value(), "value");
    }
}