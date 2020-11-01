// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/header_config.hpp"

namespace xv
{
    void to_json(nl::json& j, const header_config& data)
    {
        serialize(j, data.title(), "title");

        serialize(j, data.format(), "format");
        serialize(j, data.formatType(), "formatType");

        serialize(j, data.labelAlign(), "labelAlign");
        serialize(j, data.labelAnchor(), "labelAnchor");
        serialize(j, data.labelAngle(), "labelAngle");
        serialize(j, data.labelBaseline(), "labelBaseline");
        serialize(j, data.labelColor(), "labelColor");
        serialize(j, data.labelExpr(), "labelExpr");
        serialize(j, data.labelFont(), "labelFont");
        serialize(j, data.labelFontSize(), "labelFontSize");
        serialize(j, data.labelFontStyle(), "labelFontStyle");
        serialize(j, data.labelFontWeight(), "labelFontWeight");
        serialize(j, data.labelLimit(), "labelLimit");
        serialize(j, data.labelLineHeight(), "labelLineHeight");
        serialize(j, data.labelOrient(), "labelOrient");
        serialize(j, data.labelPadding(), "labelPadding");

        serialize(j, data.labels(), "labels");
        serialize(j, data.orient(), "orient");

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
        serialize(j, data.titleOrient(), "titleOrient");
        serialize(j, data.titlePadding(), "titlePadding");
    }
}
