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
        // Point Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, mark_point, shape);
        XPROPERTY(xtl::xoptional<double>, mark_point, size);

        XVEGA_API mark_point();

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
