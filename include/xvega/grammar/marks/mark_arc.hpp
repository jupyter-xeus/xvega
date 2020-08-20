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
        using base_type = mark<mark_arc>;

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

        mark_arc()
        {
            type = "arc";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            // Fill in Arc Mark Properties
            serialize(j, radius(), "radius");
            serialize(j, radius2(), "radius2");
            serialize(j, innerRadius(), "innerRadius");
            serialize(j, outerRadius(), "outerRadius");
            serialize(j, theta(), "theta");
            serialize(j, theta2(), "theta2");
            serialize(j, cornerRadius(), "cornerRadius");
            serialize(j, padAngle(), "padAngle");
            serialize(j, radiusOffset(), "radiusOffset");
            serialize(j, radius2Offset(), "radius2Offset");
            serialize(j, thetaOffset(), "thetaOffset");
            serialize(j, theta2Offset(), "theta2Offset");
        }
    };
}

#endif
