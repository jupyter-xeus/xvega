// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/transformations/transform_density.hpp"

namespace xv
{
    void to_json(nl::json& j, const transform_density& data)
    {
        serialize(j, data.density(), "density");
        serialize(j, data.groupby(), "groupby");
        serialize(j, data.cumulative(), "cumulative");
        serialize(j, data.counts(), "counts");
        serialize(j, data.bandwidth(), "bandwidth");
        serialize(j, data.extent(), "extent");
        serialize(j, data.minsteps(), "minsteps");
        serialize(j, data.maxsteps(), "maxsteps");
        serialize(j, data.steps(), "steps");
        serialize(j, data.as(), "as");
    }
}