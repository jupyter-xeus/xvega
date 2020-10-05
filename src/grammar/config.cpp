// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config.hpp"

namespace xv
{
    void to_json(nl::json& j, const Config& data)
    {
        serialize(j, data.area(), "area");
        serialize(j, data.autosize(), "autosize");
        serialize(j, data.axis(), "axis");
        serialize(j, data.axisBand(), "axisBand");
        serialize(j, data.axisBottom(), "axisBottom");
        serialize(j, data.axisDiscrete(), "axisDiscrete");
        serialize(j, data.axisLeft(), "axisLeft");
        serialize(j, data.axisPoint(), "axisPoint");
        serialize(j, data.axisQuantitative(), "axisQuantitative");
        serialize(j, data.axisRight(), "axisRight");
        serialize(j, data.axisTemporal(), "axisTemporal");
        serialize(j, data.axisTop(), "axisTop");
        serialize(j, data.axisX(), "axisX");
        serialize(j, data.axisXBand(), "axisXBand");
        serialize(j, data.axisXDiscrete(), "axisXDiscrete");
        serialize(j, data.axisXPoint(), "axisXPoint");
        serialize(j, data.axisXQuantitative(), "axisXQuantitative");
        serialize(j, data.axisXTemporal(), "axisXTemporal");
        serialize(j, data.axisY(), "axisY");
        serialize(j, data.axisYBand(), "axisYBand");
        serialize(j, data.axisYDiscrete(), "axisYDiscrete");
        serialize(j, data.axisYPoint(), "axisYPoint");
        serialize(j, data.axisYQuantitative(), "axisYQuantitative");
        serialize(j, data.axisYTemporal(), "axisYTemporal");
        serialize(j, data.background(), "background");
        serialize(j, data.bar(), "bar");
        serialize(j, data.boxplot(), "boxplot");
        serialize(j, data.circle(), "circle");
        serialize(j, data.concat(), "concat");
        serialize(j, data.countTitle(), "countTitle");
        serialize(j, data.errorband(), "errorband");
        serialize(j, data.errorbar(), "errorbar");
        serialize(j, data.facet(), "facet");
        serialize(j, data.fieldTitle(), "fieldTitle");
        serialize(j, data.font(), "font");
        serialize(j, data.geoshape(), "geoshape");
        serialize(j, data.header(), "header");
        serialize(j, data.headerColumn(), "headerColumn");
        serialize(j, data.headerFacet(), "headerFacet");
        serialize(j, data.headerRow(), "headerRow");
        serialize(j, data.image(), "image");
        serialize(j, data.legend(), "legend");
        serialize(j, data.line(), "line");
        serialize(j, data.lineBreak(), "lineBreak");
        serialize(j, data.mark(), "mark");
        serialize(j, data.numberFormat(), "numberFormat");
        serialize(j, data.padding(), "padding");
        serialize(j, data.point(), "point");
        serialize(j, data.projection(), "projection");
        serialize(j, data.range(), "range");
        serialize(j, data.rect(), "rect");
        serialize(j, data.rule(), "rule");
        serialize(j, data.scale(), "scale");
        serialize(j, data.selection(), "selection");
        serialize(j, data.square(), "square");
        serialize(j, data.style(), "style");
        serialize(j, data.text(), "text");
        serialize(j, data.tick(), "tick");
        serialize(j, data.timeFormat(), "timeFormat");
        serialize(j, data.title(), "title");
        serialize(j, data.trail(), "trail");
        serialize(j, data.view(), "view");
    }
}