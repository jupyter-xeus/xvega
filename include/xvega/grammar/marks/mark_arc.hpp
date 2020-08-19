// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_ARC
#define XVEGA_MARK_ARC

#include "../marks.hpp"

namespace xv
{
    struct mark_arc : public Marks<mark_arc>
    {
        using base_type = Marks<mark_arc>;

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
            if(radius().has_value())
            {
                j["radius"] = radius().value();
            }
            if(radius2().has_value())
            {
                j["radius2"] = radius2().value();
            }
            if(innerRadius().has_value())
            {
                j["innerRadius"] = innerRadius().value();
            }
            if(outerRadius().has_value())
            {
                j["outerRadius"] = outerRadius().value();
            }
            if(theta().has_value())
            {
                j["theta"] = theta().value();
            }
            if(theta2().has_value())
            {
                j["theta2"] = theta2().value();
            }
            if(cornerRadius().has_value())
            {
                j["cornerRadius"] = cornerRadius().value();
            }
            if(padAngle().has_value())
            {
                j["padAngle"] = padAngle().value();
            }
            if(radiusOffset().has_value())
            {
                j["radiusOffset"] = radiusOffset().value();
            }
            if(radius2Offset().has_value())
            {
                j["radius2Offset"] = radius2Offset().value();
            }
            if(thetaOffset().has_value())
            {
                j["thetaOffset"] = thetaOffset().value();
            }
            if(theta2Offset().has_value())
            {
                j["theta2Offset"] = theta2Offset().value();
            }
        }
    };
}

#endif
