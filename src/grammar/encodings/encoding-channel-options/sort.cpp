// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/encodings/encoding-channel-options/sort.hpp"
#include "../../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const FieldSort& data) {
        serialize(j, data.field(), "field");
        serialize(j, data.op(), "op");
        serialize(j, data.order(), "order");
    }

    void to_json(nl::json& j, const EncodingSort& data) {
        serialize(j, data.encoding(), "encoding");
        serialize(j, data.order(), "order");
    }
}