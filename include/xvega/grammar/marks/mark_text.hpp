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
        XPROPERTY(xtl::xoptional<std::string>, mark_text, align);
        XPROPERTY(xtl::xoptional<std::string>, mark_text, baseline);
        XPROPERTY(xtl::xoptional<std::string>, mark_text, dir);
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

        XVEGA_API mark_text();

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
