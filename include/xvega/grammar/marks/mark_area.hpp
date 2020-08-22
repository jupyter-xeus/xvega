// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_AREA_HPP
#define XVEGA_MARK_AREA_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_area : public mark<mark_area>
    {
        using base_type = mark<mark_area>;

        // Area Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, mark_area, align, xtl::missing<std::string>(), XEITHER_OPTIONAL("left", "right", "center"));
        XPROPERTY(xtl::xoptional<std::string>, mark_area, baseline, xtl::missing<std::string>(), XEITHER_OPTIONAL("alphabetic", "top", "middle", "bottom", "line-top", "line-bottom"));
        XPROPERTY(xtl::xoptional<std::string>, mark_area, orient, xtl::missing<std::string>(), XEITHER_OPTIONAL("horizontal", "vertical"));
        XPROPERTY(xtl::xoptional<std::string>, mark_area, interpolate, xtl::missing<std::string>(), XEITHER_OPTIONAL("basis", "basis-open", "basis-closed", "bundle", "cardinal", "cardinal-open", "cardinal-closed", "catmull-rom", "linear", "linear-closed", "monotone", "natural", "step", "step-before", "step-after"));
        XPROPERTY(xtl::xoptional<double>, mark_area, tension);
        XPROPERTY(xtl::xoptional<bool_object_type>, mark_area, line);
        XPROPERTY(xtl::xoptional<bool_string_object_type>, mark_area, point);

        mark_area()
        {
            type = "area";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            // Fill in Area Mark Properties
            serialize(j, align(), "align");
            serialize(j, baseline(), "baseline");
            serialize(j, orient(), "orient");
            serialize(j, interpolate(), "interpolate");
            serialize(j, tension(), "tension");
            serialize(j, line(), "line");
            serialize(j, point(), "point");
        }
    };
}

#endif
