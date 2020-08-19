// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_GEOSHAPE
#define XVEGA_MARK_GEOSHAPE

#include "../marks.hpp"

namespace xv
{
    struct mark_geoshape : public Marks<mark_geoshape>
    {
        using base_type = Marks<mark_geoshape>;

        mark_geoshape()
        {
            type = "geoshape";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
        }
    };
}

#endif
