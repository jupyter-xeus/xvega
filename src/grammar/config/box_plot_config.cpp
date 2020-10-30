// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/box_plot_config.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const box_plot_config& data)
    {
        serialize(j, data.box(), "box");
        serialize(j, data.extent(), "extent");
        serialize(j, data.median(), "median");
        serialize(j, data.outliers(), "outliers");
        serialize(j, data.rule(), "rule");
        serialize(j, data.size(), "size");
        serialize(j, data.ticks(), "ticks");
    }
}
