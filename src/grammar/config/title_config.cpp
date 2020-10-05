// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/title_config.hpp"

namespace xv
{
    void to_json(nl::json& j, const title_config& data)
    {
        serialize(j, data.align(), "align");
        serialize(j, data.anchor(), "anchor");
        serialize(j, data.angle(), "angle");
        serialize(j, data.baseline(), "baseline");
        serialize(j, data.color(), "color");
        serialize(j, data.dx(), "dx");
        serialize(j, data.dy(), "dy");
        serialize(j, data.font(), "font");
        serialize(j, data.fontSize(), "fontSize");
        serialize(j, data.fontStyle(), "fontStyle");
        serialize(j, data.fontWeight(), "fontWeight");
        serialize(j, data.frame(), "frame");
        serialize(j, data.limit(), "limit");
        serialize(j, data.lineHeight(), "lineHeight");
        serialize(j, data.offset(), "offset");
        serialize(j, data.orient(), "orient");
        serialize(j, data.subtitleColor(), "subtitleColor");
        serialize(j, data.subtitleFont(), "subtitleFont");
        serialize(j, data.subtitleFontSize(), "subtitleFontSize");
        serialize(j, data.subtitleFontStyle(), "subtitleFontStyle");
        serialize(j, data.subtitleFontWeight(), "subtitleFontWeight");
        serialize(j, data.subtitleLineHeight(), "subtitleLineHeight");
        serialize(j, data.subtitlePadding(), "subtitlePadding");
    }
}