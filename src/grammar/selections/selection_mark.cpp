// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/selections/selection_mark.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const selection_mark& data)
    {
        serialize(j, data.cursor(), "cursor");
        serialize(j, data.fill(), "fill");
        serialize(j, data.fillOpacity(), "fillOpacity");
        serialize(j, data.stroke(), "stroke");
        serialize(j, data.strokeOpacity(), "strokeOpacity");
        serialize(j, data.strokeWidth(), "strokeWidth");
        serialize(j, data.strokeDash(), "strokeDash");
        serialize(j, data.strokeDashOffset(), "strokeDashOffset");
    }
}