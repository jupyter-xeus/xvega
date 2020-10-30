// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/encodings.hpp"
#include "../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const Encodings& data)
    {
        serialize(j, data.x(), "x");
        serialize(j, data.y(), "y");
        serialize(j, data.x2(), "x2");
        serialize(j, data.y2(), "y2");
        serialize(j, data.xError(), "xError");
        serialize(j, data.yError(), "yError");
        serialize(j, data.xError2(), "xError2");
        serialize(j, data.yError2(), "yError2");
        serialize(j, data.longitude(), "longitude");
        serialize(j, data.latitude(), "latitude");
        serialize(j, data.longitude2(), "longitude2");
        serialize(j, data.latitude2(), "latitude2");
        
        serialize(j, data.color(), "color");
        serialize(j, data.fill(), "fill");
        serialize(j, data.fillOpacity(), "fillOpacity");
        serialize(j, data.opacity(), "opacity");
        serialize(j, data.shape(), "shape");
        serialize(j, data.size(), "size");
        serialize(j, data.stroke(), "stroke");
        serialize(j, data.strokeDash(), "strokeDash");
        serialize(j, data.strokeOpacity(), "strokeOpacity");
        serialize(j, data.strokeWidth(), "strokeWidth");

        serialize(j, data.text(), "text");
        serialize(j, data.key(), "key");
        serialize(j, data.tooltip(), "tooltip");
        
        serialize(j, data.href(), "href");

        serialize(j, data.detail(), "detail");

        serialize(j, data.order(), "order");

        serialize(j, data.row(), "row");
        serialize(j, data.facet(), "facet");
        serialize(j, data.column(), "column");
    }
}