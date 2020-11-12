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

    void to_json(nl::json& j, const mark_image& m)
    {
        private_to_json(m, j);
        // Fill in Image Mark Properties
        serialize(j, m.url(), "url");
        serialize(j, m.aspect(), "aspect");
        serialize(j, m.align(), "align");
        serialize(j, m.baseline(), "baseline");
    }
}
