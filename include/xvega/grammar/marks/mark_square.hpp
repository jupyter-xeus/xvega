// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_SQUARE
#define XVEGA_MARK_SQUARE

#include "../marks.hpp"

namespace xv
{
    struct mark_square : public Marks<mark_square>
    {
        using base_type = Marks<mark_square>;

        // Square Mark Properties
        XPROPERTY(xtl::xoptional<double>, mark_square, size);

        mark_square()
        {
            type = "square";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            // Fill in Square Mark Properties
            if(size().has_value())
            {
                j["size"] = size().value();
            }
        }
    };
}

#endif
