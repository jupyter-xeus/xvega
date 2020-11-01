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

    void mark_text::to_json(nl::json& j) const
    {
        private_to_json(*this, j);
        // Fill in Text Mark Properties
        serialize(j, angle(), "angle");
        serialize(j, align(), "align");
        serialize(j, baseline(), "baseline");
        serialize(j, dir(), "dir");
        serialize(j, dx(), "dx");
        serialize(j, dy(), "dy");
        serialize(j, ellipsis(), "ellipsis");
        serialize(j, font(), "font");
        serialize(j, fontSize(), "fontSize");
        serialize(j, fontStyle(), "fontStyle");
        serialize(j, fontWeight(), "fontWeight");
        serialize(j, limit(), "limit");
        serialize(j, lineHeight(), "lineHeight");
        serialize(j, radius(), "radius");
        serialize(j, text(), "text");
        serialize(j, theta(), "theta");
    }
}
