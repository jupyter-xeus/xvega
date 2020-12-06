// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TITLE_HPP
#define XVEGA_TITLE_HPP

#include "xproperty/xobserved.hpp"

#include "../xvega_config.hpp"
#include "../utils/custom_datatypes.hpp"

namespace xv
{
    struct Title : public xp::xobserved<Title>
    {
        XPROPERTY(xtl::xoptional<std::string>, Title, text);
        XPROPERTY(xtl::xoptional<std::string>, Title, align);
        XPROPERTY(xtl::xoptional<string_none_type>, Title, anchor);
        XPROPERTY(xtl::xoptional<double>, Title, angle);
        XPROPERTY(xtl::xoptional<std::string>, Title, baseline);
        XPROPERTY(xtl::xoptional<string_none_type>, Title, color);
        XPROPERTY(xtl::xoptional<double>, Title, dx);
        XPROPERTY(xtl::xoptional<double>, Title, dy);
        XPROPERTY(xtl::xoptional<std::string>, Title, font);
        XPROPERTY(xtl::xoptional<double>, Title, fontSize);
        XPROPERTY(xtl::xoptional<std::string>, Title, fontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, Title, fontWeight);
        XPROPERTY(xtl::xoptional<std::string>, Title, frame);
        XPROPERTY(xtl::xoptional<double>, Title, limit);
        XPROPERTY(xtl::xoptional<double>, Title, lineHeight);
        XPROPERTY(xtl::xoptional<double>, Title, offset);
        XPROPERTY(xtl::xoptional<std::string>, Title, orient);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, Title, style);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, Title, subtitle);
        XPROPERTY(xtl::xoptional<string_none_type>, Title, subtitleColor);
        XPROPERTY(xtl::xoptional<std::string>, Title, subtitleFont);
        XPROPERTY(xtl::xoptional<double>, Title, subtitleFontSize);
        XPROPERTY(xtl::xoptional<std::string>, Title, subtitleFontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, Title, subtitleFontWeight);
        XPROPERTY(xtl::xoptional<double>, Title, subtitleLineHeight);
        XPROPERTY(xtl::xoptional<double>, Title, subtitlePadding);
        XPROPERTY(xtl::xoptional<double>, Title, zindex);
    };

    XVEGA_API void to_json(nl::json& j, const Title& data);
}

#endif
