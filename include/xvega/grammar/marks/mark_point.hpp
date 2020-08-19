// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_POINT
#define XVEGA_MARK_POINT

#include "../marks.hpp"

namespace xv
{
    struct mark_point : public Marks<mark_point>
    {
        using base_type = Marks<mark_point>;

        // Point Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, mark_point, shape);
        XPROPERTY(xtl::xoptional<double>, mark_point, size);

        mark_point()
        {
            type = "point";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            // Fill in Point Mark Properties
            if(shape().has_value())
            {
                j["shape"] = shape().value();
            }
            if(size().has_value())
            {
                j["size"] = size().value();
            }
        }
    };
}

#endif
