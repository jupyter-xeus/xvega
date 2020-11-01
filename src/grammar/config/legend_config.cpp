// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/legend_config.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const legend_config& data)
    {
        serialize(j, data.clipHeight(), "clipHeight");
        serialize(j, data.columnPadding(), "columnPadding");
        serialize(j, data.columns(), "columns");
        serialize(j, data.cornerRadius(), "cornerRadius");
        serialize(j, data.direction(), "direction");
        serialize(j, data.disable(), "disable");
        serialize(j, data.fillColor(), "fillColor");
        serialize(j, data.gradientDirection(), "gradientDirection");
        serialize(j, data.gradientHorizontalMaxLength(), "gradientHorizontalMaxLength");
        serialize(j, data.gradientHorizontalMinLength(), "gradientHorizontalMinLength");
        serialize(j, data.gradientLabelLimit(), "gradientLabelLimit");
        serialize(j, data.gradientLabelOffset(), "gradientLabelOffset");
        serialize(j, data.gradientLength(), "gradientLength");
        serialize(j, data.gradientOpacity(), "gradientOpacity");
        serialize(j, data.gradientStrokeColor(), "gradientStrokeColor");
        serialize(j, data.gradientStrokeWidth(), "gradientStrokeWidth");
        serialize(j, data.gradientThickness(), "gradientThickness");
        serialize(j, data.gradientVerticalMaxLength(), "gradientVerticalMaxLength");
        serialize(j, data.gradientVerticalMinLength(), "gradientVerticalMinLength");
        serialize(j, data.gridAlign(), "gridAlign");
        serialize(j, data.labelAlign(), "labelAlign");
        serialize(j, data.labelBaseline(), "labelBaseline");
        serialize(j, data.labelColor(), "labelColor");
        serialize(j, data.labelFont(), "labelFont");
        serialize(j, data.labelFontSize(), "labelFontSize");
        serialize(j, data.labelFontStyle(), "labelFontStyle");
        serialize(j, data.labelFontWeight(), "labelFontWeight");
        serialize(j, data.labelLimit(), "labelLimit");
        serialize(j, data.labelOffset(), "labelOffset");
        serialize(j, data.labelOpacity(), "labelOpacity");
        serialize(j, data.labelOverlap(), "labelOverlap");
        serialize(j, data.labelPadding(), "labelPadding");
        serialize(j, data.labelSeparation(), "labelSeparation");
        serialize(j, data.legendX(), "legendX");
        serialize(j, data.legendY(), "legendY");
        serialize(j, data.offset(), "offset");
        serialize(j, data.orient(), "orient");
        serialize(j, data.padding(), "padding");
        serialize(j, data.rowPadding(), "rowPadding");
        serialize(j, data.strokeColor(), "strokeColor");
        serialize(j, data.strokeDash(), "strokeDash");
        serialize(j, data.strokeWidth(), "strokeWidth");
        serialize(j, data.symbolBaseFillColor(), "symbolBaseFillColor");
        serialize(j, data.symbolBaseStrokeColor(), "symbolBaseStrokeColor");
        serialize(j, data.symbolDash(), "symbolDash");
        serialize(j, data.symbolDashOffset(), "symbolDashOffset");
        serialize(j, data.symbolDirection(), "symbolDirection");
        serialize(j, data.symbolFillColor(), "symbolFillColor");
        serialize(j, data.symbolLimit(), "symbolLimit");
        serialize(j, data.symbolOffset(), "symbolOffset");
        serialize(j, data.symbolOpacity(), "symbolOpacity");
        serialize(j, data.symbolSize(), "symbolSize");
        serialize(j, data.symbolStrokeColor(), "symbolStrokeColor");
        serialize(j, data.symbolStrokeWidth(), "symbolStrokeWidth");
        serialize(j, data.symbolType(), "symbolType");
        serialize(j, data.tickCount(), "tickCount");
        serialize(j, data.title(), "title");
        serialize(j, data.titleAlign(), "titleAlign");
        serialize(j, data.titleAnchor(), "titleAnchor");
        serialize(j, data.titleBaseline(), "titleBaseline");
        serialize(j, data.titleColor(), "titleColor");
        serialize(j, data.titleFont(), "titleFont");
        serialize(j, data.titleFontSize(), "titleFontSize");
        serialize(j, data.titleFontStyle(), "titleFontStyle");
        serialize(j, data.titleFontWeight(), "titleFontWeight");
        serialize(j, data.titleLimit(), "titleLimit");
        serialize(j, data.titleLineHeight(), "titleLineHeight");
        serialize(j, data.titleOpacity(), "titleOpacity");
        serialize(j, data.titleOrient(), "titleOrient");
        serialize(j, data.titlePadding(), "titlePadding");
        serialize(j, data.unselectedOpacity(), "unselectedOpacity");
    }
}
