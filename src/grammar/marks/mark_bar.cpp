// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_bar.hpp"
#include "../marks_private.hpp"

namespace xv
{
    mark_bar::mark_bar()
    {
        type = "bar";
    }

    void to_json(nl::json& j, const mark_bar& m)
    {
        private_to_json(m, j);
        // Fill in Bar Mark Properties
        serialize(j, m.orient(), "orient");
        serialize(j, m.align(), "align");
        serialize(j, m.baseline(), "baseline");
        serialize(j, m.binSpacing(), "binSpacing");
        serialize(j, m.cornerRadius(), "cornerRadius");
        serialize(j, m.cornerRadiusEnd(), "cornerRadiusEnd");
        serialize(j, m.cornerRadiusTopLeft(), "cornerRadiusTopLeft");
        serialize(j, m.cornerRadiusTopRight(), "cornerRadiusTopRight");
        serialize(j, m.cornerRadiusBottomLeft(), "cornerRadiusBottomLeft");
        serialize(j, m.cornerRadiusBottomRight(), "cornerRadiusBottomRight");
    }
}
