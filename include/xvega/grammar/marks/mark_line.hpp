// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_LINE
#define XVEGA_MARK_LINE

#include "../marks.hpp"

namespace xv
{
    struct mark_line : public Marks<mark_line>
    {
        using base_type = Marks<mark_line>;

        // Line Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, mark_line, orient, xtl::missing<std::string>(), XEITHER_OPTIONAL("horizontal", "vertical"));
        XPROPERTY(xtl::xoptional<std::string>, mark_line, interpolate, xtl::missing<std::string>(), XEITHER_OPTIONAL("basis", "basis-open", "basis-closed", "bundle", "cardinal", "cardinal-open", "cardinal-closed", "catmull-rom", "linear", "linear-closed", "monotone", "natural", "step", "step-before", "step-after"));
        XPROPERTY(xtl::xoptional<double>, mark_line, tension);
        XPROPERTY(xtl::xoptional<boolStringObjectType>, mark_line, point);

        mark_line()
        {
            type = "line";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            // Fill in Line Mark Properties
            if(orient().has_value())
            {
                j["orient"] = orient().value();
            }
            if(interpolate().has_value())
            {
                j["interpolate"] = interpolate().value();
            }
            if(tension().has_value())
            {
                j["tension"] = tension().value();
            }
            if(point().has_value())
            {
                j["point"] = point().value();
            }
        }
    };
}

#endif
