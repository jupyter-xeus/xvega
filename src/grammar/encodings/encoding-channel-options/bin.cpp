// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/encodings/encoding-channel-options/bin.hpp"
#include "../../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const Bin& data)
    {
        serialize(j, data.anchor(), "anchor");
        serialize(j, data.base(), "base");
        serialize(j, data.binned(), "binned");
        serialize(j, data.divide(), "divide");
        serialize(j, data.extent(), "extent");
        serialize(j, data.maxbins(), "maxbins");
        serialize(j, data.minstep(), "minstep");
        serialize(j, data.nice(), "nice");
        serialize(j, data.step(), "step");
        serialize(j, data.steps(), "steps");
    }
}