// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/marks/mark_image.hpp"
#include "../marks_private.hpp"

namespace xv
{
    mark_image::mark_image()
    {
        type = "image";
    }

    void mark_image::to_json(nl::json& j) const
    {
        private_to_json(*this, j);
        // Fill in Image Mark Properties
        serialize(j, url(), "url");
        serialize(j, aspect(), "aspect");
        serialize(j, align(), "align");
        serialize(j, baseline(), "baseline");
    }
}
