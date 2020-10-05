// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/projection_config.hpp"

namespace xv
{
    void to_json(nl::json& j, const projection_config& data)
    {
        serialize(j, data.center(), "center");
        serialize(j, data.clipAngle(), "clipAngle");
        serialize(j, data.clipExtent(), "clipExtent");
        serialize(j, data.coefficient(), "coefficient");
        serialize(j, data.distance(), "distance");
        serialize(j, data.extent(), "extent");
        serialize(j, data.fit(), "fit");
        serialize(j, data.fraction(), "fraction");
        serialize(j, data.lobes(), "lobes");
        serialize(j, data.parallel(), "parallel");
        serialize(j, data.parallels(), "parallels");
        serialize(j, data.pointRadius(), "pointRadius");
        serialize(j, data.precision(), "precision");
        serialize(j, data.radius(), "radius");
        serialize(j, data.ratio(), "ratio");
        serialize(j, data.reflectX(), "reflectX");
        serialize(j, data.reflectY(), "reflectY");
        serialize(j, data.rotate(), "rotate");
        serialize(j, data.scale(), "scale");
        serialize(j, data.size(), "size");
        serialize(j, data.spacing(), "spacing");
        serialize(j, data.tilt(), "tilt");
        serialize(j, data.translate(), "translate");
        serialize(j, data.type(), "type");
    }
}