// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_ARC_HPP
#define XVEGA_MARK_ARC_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_arc : public mark<mark_arc>
    {
        // Arc Mark Properties
        XPROPERTY(xtl::xoptional<double>, mark_arc, radius);
        XPROPERTY(xtl::xoptional<double>, mark_arc, radius2);
        XPROPERTY(xtl::xoptional<double>, mark_arc, innerRadius);
        XPROPERTY(xtl::xoptional<double>, mark_arc, outerRadius);
        XPROPERTY(xtl::xoptional<double>, mark_arc, theta);
        XPROPERTY(xtl::xoptional<double>, mark_arc, theta2);
        XPROPERTY(xtl::xoptional<double>, mark_arc, cornerRadius);
        XPROPERTY(xtl::xoptional<double>, mark_arc, padAngle);
        XPROPERTY(xtl::xoptional<double>, mark_arc, radiusOffset);
        XPROPERTY(xtl::xoptional<double>, mark_arc, radius2Offset);
        XPROPERTY(xtl::xoptional<double>, mark_arc, thetaOffset);
        XPROPERTY(xtl::xoptional<double>, mark_arc, theta2Offset);

        XVEGA_API mark_arc();

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
