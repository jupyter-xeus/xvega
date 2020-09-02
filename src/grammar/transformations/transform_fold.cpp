// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/transformations/transform_fold.hpp"

namespace xv
{
    void to_json(nl::json& j, const transform_fold& data)
    {
        serialize(j, data.fold(), "fold");
        serialize(j, data.as(), "as");
    }
}