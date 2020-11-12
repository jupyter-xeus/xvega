// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_text.hpp"
#include "../marks_private.hpp"

namespace xv
{
    mark_text::mark_text()
    {
        type = "text";
    }

    void to_json(nl::json& j, const mark_text& m)
    {
        private_to_json(m, j);
        // Fill in Text Mark Properties
        serialize(j, m.angle(), "angle");
        serialize(j, m.align(), "align");
        serialize(j, m.baseline(), "baseline");
        serialize(j, m.dir(), "dir");
        serialize(j, m.dx(), "dx");
        serialize(j, m.dy(), "dy");
        serialize(j, m.ellipsis(), "ellipsis");
        serialize(j, m.font(), "font");
        serialize(j, m.fontSize(), "fontSize");
        serialize(j, m.fontStyle(), "fontStyle");
        serialize(j, m.fontWeight(), "fontWeight");
        serialize(j, m.limit(), "limit");
        serialize(j, m.lineHeight(), "lineHeight");
        serialize(j, m.radius(), "radius");
        serialize(j, m.text(), "text");
        serialize(j, m.theta(), "theta");
    }
}
