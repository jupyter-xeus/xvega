// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_LINE_HPP
#define XVEGA_MARK_LINE_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_line : public mark<mark_line>
    {
        using base_type = mark<mark_line>;

        // Line Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, mark_line, orient, xtl::missing<std::string>(), XEITHER_OPTIONAL("horizontal", "vertical"));
        XPROPERTY(xtl::xoptional<std::string>, mark_line, interpolate, xtl::missing<std::string>(), XEITHER_OPTIONAL("basis", "basis-open", "basis-closed", "bundle", "cardinal", "cardinal-open", "cardinal-closed", "catmull-rom", "linear", "linear-closed", "monotone", "natural", "step", "step-before", "step-after"));
        XPROPERTY(xtl::xoptional<double>, mark_line, tension);
        XPROPERTY(xtl::xoptional<bool_string_object_type>, mark_line, point);

        mark_line()
        {
            type = "line";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            // Fill in Line Mark Properties
            serialize(j, orient(), "orient");
            serialize(j, interpolate(), "interpolate");
            serialize(j, tension(), "tension");
            serialize(j, point(), "point");
        }
    };
}

#endif
