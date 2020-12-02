// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/selections/selection_mark.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const selection_mark& m)
    {
        serialize(j, m.cursor(), "cursor");
        serialize(j, m.fill(), "fill");
        serialize(j, m.fillOpacity(), "fillOpacity");
        serialize(j, m.stroke(), "stroke");
        serialize(j, m.strokeOpacity(), "strokeOpacity");
        serialize(j, m.strokeWidth(), "strokeWidth");
        serialize(j, m.strokeDash(), "strokeDash");
        serialize(j, m.strokeDashOffset(), "strokeDashOffset");
    }
}
