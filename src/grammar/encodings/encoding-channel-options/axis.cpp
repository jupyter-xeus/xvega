// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/encodings/encoding-channel-options/axis.hpp"
#include "../../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const Axis& data)
    {
        // Fill in General Axis Properties
        serialize(j, data.aria(), "aria");
        serialize(j, data.bandPosition(), "bandPosition");
        serialize(j, data.description(), "description");
        serialize(j, data.maxExtent(), "maxExtent");
        serialize(j, data.minExtent(), "minExtent");
        serialize(j, data.orient(), "orient");
        serialize(j, data.offset(), "offset");
        serialize(j, data.position(), "position");
        serialize(j, data.style(), "style");
        serialize(j, data.translate(), "translate");
        serialize(j, data.zindex(), "zindex");

        // Fill in Domain Axis Properties
        serialize(j, data.domain(), "domain");
        serialize(j, data.domainCap(), "domainCap");
        serialize(j, data.domainColor(), "domainColor");
        serialize(j, data.domainOpacity(), "domainOpacity");
        serialize(j, data.domainWidth(), "domainWidth");
        serialize(j, data.domainDash(), "domainDash");
        serialize(j, data.domainDashOffset(), "domainDashOffset");

        // Fill in Label Axis Properties
        serialize(j, data.format(), "format");
        serialize(j, data.formatType(), "formatType");
        serialize(j, data.labels(), "labels");
        serialize(j, data.labelAlign(), "labelAlign");
        serialize(j, data.labelAngle(), "labelAngle");
        serialize(j, data.labelBaseline(), "labelBaseline");
        serialize(j, data.labelBound(), "labelBound");
        serialize(j, data.labelColor(), "labelColor");
        serialize(j, data.labelExpr(), "labelExpr");
        serialize(j, data.labelFlush(), "labelFlush");
        serialize(j, data.labelFlushOffset(), "labelFlushOffset");
        serialize(j, data.labelFont(), "labelFont");
        serialize(j, data.labelFontSize(), "labelFontSize");
        serialize(j, data.labelFontStyle(), "labelFontStyle");
        serialize(j, data.labelFontWeight(), "labelFontWeight");
        serialize(j, data.labelLimit(), "labelLimit");
        serialize(j, data.labelLineHeight(), "labelLineHeight");
        serialize(j, data.labelOffset(), "labelOffset");
        serialize(j, data.labelOpacity(), "labelOpacity");
        serialize(j, data.labelOverlap(), "labelOverlap");
        serialize(j, data.labelPadding(), "labelPadding");
        serialize(j, data.labelSeparation(), "labelSeparation");

        // Fill in Ticks Axis Properties
        serialize(j, data.ticks(), "ticks");
        serialize(j, data.tickBand(), "tickBand");
        serialize(j, data.tickCap(), "tickCap");
        serialize(j, data.tickColor(), "tickColor");
        serialize(j, data.tickCount(), "tickCount");
        serialize(j, data.tickDash(), "tickDash");
        serialize(j, data.tickDashOffset(), "tickDashOffset");
        serialize(j, data.tickExtra(), "tickExtra");
        serialize(j, data.tickMinStep(), "tickMinStep");
        serialize(j, data.tickOffset(), "tickOffset");
        serialize(j, data.tickOpacity(), "tickOpacity");
        serialize(j, data.tickRound(), "tickRound");
        serialize(j, data.tickSize(), "tickSize");
        serialize(j, data.tickWidth(), "tickWidth");
        serialize(j, data.values(), "values");

        // Fill in Title Axis Properties
        serialize(j, data.title(), "title");
        serialize(j, data.titleAlign(), "titleAlign");
        serialize(j, data.titleAnchor(), "titleAnchor");
        serialize(j, data.titleAngle(), "titleAngle");
        serialize(j, data.titleBaseline(), "titleBaseline");
        serialize(j, data.titleColor(), "titleColor");
        serialize(j, data.titleFont(), "titleFont");
        serialize(j, data.titleFontSize(), "titleFontSize");
        serialize(j, data.titleFontStyle(), "titleFontStyle");
        serialize(j, data.titleFontWeight(), "titleFontWeight");
        serialize(j, data.titleLimit(), "titleLimit");
        serialize(j, data.titleLineHeight(), "titleLineHeight");
        serialize(j, data.titleOpacity(), "titleOpacity");
        serialize(j, data.titlePadding(), "titlePadding");
        serialize(j, data.titleX(), "titleX");
        serialize(j, data.titleY(), "titleY");
        
        // Fill in Grid Axis Properties
        serialize(j, data.grid(), "grid");
        serialize(j, data.gridCap(), "gridCap");
        serialize(j, data.gridColor(), "gridColor");
        serialize(j, data.gridDash(), "gridDash");
        serialize(j, data.gridDashOffset(), "gridDashOffset");
        serialize(j, data.gridOpacity(), "gridOpacity");
        serialize(j, data.gridWidth(), "gridWidth");
    }
}