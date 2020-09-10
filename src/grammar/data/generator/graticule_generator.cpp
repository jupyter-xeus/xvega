// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/data/generator/graticule_generator.hpp"

namespace xv
{
    void to_json(nl::json& j, const graticule_params& data)
    {
        serialize(j, data.extent(), "extent");
        serialize(j, data.extentMajor(), "extentMajor");
        serialize(j, data.extentMinor(), "extentMinor");
        serialize(j, data.precision(), "precision");
        serialize(j, data.step(), "step");
        serialize(j, data.stepMajor(), "stepMajor");
        serialize(j, data.stepMinor(), "stepMinor");
    }

    void to_json(nl::json& j, const graticule_generator& data)
    {
        serialize(j, data.graticule(), "graticule");
        serialize(j, data.name(), "name");
    }
}