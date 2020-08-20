// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_POINT_HPP
#define XVEGA_MARK_POINT_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_point : public mark<mark_point>
    {
        using base_type = mark<mark_point>;

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
            serialize(j, shape(), "shape");
            serialize(j, size(), "size");
        }
    };
}

#endif
