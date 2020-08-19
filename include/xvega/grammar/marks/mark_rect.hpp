// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_RECT
#define XVEGA_MARK_RECT

#include "../marks.hpp"

namespace xv
{
    struct mark_rect : public Marks<mark_rect>
    {
        using base_type = Marks<mark_rect>;

        // Rect Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, mark_rect, align, xtl::missing<std::string>(), XEITHER_OPTIONAL("left", "right", "center"));
        XPROPERTY(xtl::xoptional<std::string>, mark_rect, baseline, xtl::missing<std::string>(), XEITHER_OPTIONAL("alphabetic", "top", "middle", "bottom", "line-top", "line-bottom"));
        XPROPERTY(xtl::xoptional<double>, mark_rect, cornerRadius);

        mark_rect()
        {
            type = "rect";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            // Fill in Rect Mark Properties
            if(align().has_value())
            {
                j["align"] = align().value();
            }
            if(baseline().has_value())
            {
                j["baseline"] = baseline().value();
            }
            if(cornerRadius().has_value())
            {
                j["cornerRadius"] = cornerRadius().value();
            }
        }
    };
}

#endif
