// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_TEXT
#define XVEGA_MARK_TEXT

#include "../marks.hpp"

namespace xv
{
    struct mark_text : public Marks<mark_text>
    {
        using base_type = Marks<mark_text>;

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
        XPROPERTY(xtl::xoptional<stringNumType>, mark_text, fontWeight);
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
            if(angle().has_value())
            {
                j["angle"] = angle().value();
            }
            if(align().has_value())
            {
                j["align"] = align().value();
            }
            if(baseline().has_value())
            {
                j["baseline"] = baseline().value();
            }
            if(dir().has_value())
            {
                j["dir"] = dir().value();
            }
            if(dx().has_value())
            {
                j["dx"] = dx().value();
            }
            if(dy().has_value())
            {
                j["dy"] = dy().value();
            }
            if(ellipsis().has_value())
            {
                j["ellipsis"] = ellipsis().value();
            }
            if(font().has_value())
            {
                j["font"] = font().value();
            }
            if(fontSize().has_value())
            {
                j["fontSize"] = fontSize().value();
            }
            if(fontStyle().has_value())
            {
                j["fontStyle"] = fontStyle().value();
            }
            if(fontWeight().has_value())
            {
                j["fontWeight"] = fontWeight().value();
            }
            if(limit().has_value())
            {
                j["limit"] = limit().value();
            }
            if(lineHeight().has_value())
            {
                j["lineHeight"] = lineHeight().value();
            }
            if(radius().has_value())
            {
                j["radius"] = radius().value();
            }
            if(text().has_value())
            {
                j["text"] = text().value();
            }
            if(theta().has_value())
            {
                j["theta"] = theta().value();
            }
        }
    };
}

#endif
