// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_TEXT_HPP
#define XVEGA_MARK_TEXT_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_text : public mark<mark_text>
    {
        using base_type = mark<mark_text>;

        // Text Mark Properties
        XPROPERTY(xtl::xoptional<double>, mark_text, angle);
        XPROPERTY(xtl::xoptional<std::string>, mark_text, align, xtl::missing<std::string>(), XEITHER_OPTIONAL("left", "right", "center"));
        XPROPERTY(xtl::xoptional<std::string>, mark_text, baseline, xtl::missing<std::string>(), XEITHER_OPTIONAL("alphabetic", "top", "middle", "bottom", "line-top", "line-bottom"));
        XPROPERTY(xtl::xoptional<std::string>, mark_text, dir, xtl::missing<std::string>(), XEITHER_OPTIONAL("ltr", "rtl"));
        XPROPERTY(xtl::xoptional<double>, mark_text, dx);
        XPROPERTY(xtl::xoptional<double>, mark_text, dy);
        XPROPERTY(xtl::xoptional<std::string>, mark_text, ellipsis);
        XPROPERTY(xtl::xoptional<std::string>, mark_text, font);
        XPROPERTY(xtl::xoptional<double>, mark_text, fontSize);
        XPROPERTY(xtl::xoptional<std::string>, mark_text, fontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, mark_text, fontWeight);
        XPROPERTY(xtl::xoptional<double>, mark_text, limit);
        XPROPERTY(xtl::xoptional<double>, mark_text, lineHeight);
        XPROPERTY(xtl::xoptional<double>, mark_text, radius);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, mark_text, text);
        XPROPERTY(xtl::xoptional<double>, mark_text, theta);

        mark_text()
        {
            type = "text";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            // Fill in Text Mark Properties
            serialize(j, angle(), "angle");
            serialize(j, align(), "align");
            serialize(j, baseline(), "baseline");
            serialize(j, dir(), "dir");
            serialize(j, dx(), "dx");
            serialize(j, dy(), "dy");
            serialize(j, ellipsis(), "ellipsis");
            serialize(j, font(), "font");
            serialize(j, fontSize(), "fontSize");
            serialize(j, fontStyle(), "fontStyle");
            serialize(j, fontWeight(), "fontWeight");
            serialize(j, limit(), "limit");
            serialize(j, lineHeight(), "lineHeight");
            serialize(j, radius(), "radius");
            serialize(j, text(), "text");
            serialize(j, theta(), "theta");
        }
    };
}

#endif
