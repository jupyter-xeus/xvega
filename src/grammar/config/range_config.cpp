// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/range_config.hpp"

namespace xv
{
    void to_json(nl::json& j, const range_config& data)
    {
        serialize(j, data.category(), "category");
        serialize(j, data.diverging(), "diverging");
        serialize(j, data.heatmap(), "heatmap");
        serialize(j, data.ordinal(), "ordinal");
        serialize(j, data.ramp(), "ramp");
        serialize(j, data.symbol(), "symbol");
    }
}