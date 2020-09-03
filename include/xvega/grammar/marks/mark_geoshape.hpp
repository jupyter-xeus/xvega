// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_GEOSHAPE_HPP
#define XVEGA_MARK_GEOSHAPE_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_geoshape : public mark<mark_geoshape>
    {
        using base_type = mark<mark_geoshape>;

        mark_geoshape();

        void to_json(nl::json& j) const;
    };
}

#endif
