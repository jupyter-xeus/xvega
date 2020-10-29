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

    void mark_bar::to_json(nl::json& j) const
    {
        private_to_json(*this, j);
        // Fill in Bar Mark Properties
        serialize(j, orient(), "orient");
        serialize(j, align(), "align");
        serialize(j, baseline(), "baseline");
        serialize(j, binSpacing(), "binSpacing");
        serialize(j, cornerRadius(), "cornerRadius");
        serialize(j, cornerRadiusEnd(), "cornerRadiusEnd");
        serialize(j, cornerRadiusTopLeft(), "cornerRadiusTopLeft");
        serialize(j, cornerRadiusTopRight(), "cornerRadiusTopRight");
        serialize(j, cornerRadiusBottomLeft(), "cornerRadiusBottomLeft");
        serialize(j, cornerRadiusBottomRight(), "cornerRadiusBottomRight");
    }
}
