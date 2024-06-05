// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TITLE_HPP
#define XVEGA_TITLE_HPP

#include <optional>

#include "xproperty/xobserved.hpp"

#include "../xvega_config.hpp"
#include "../utils/custom_datatypes.hpp"

namespace xv
{
    struct Title : public xp::xobserved<Title>
    {
        XPROPERTY(std::optional<std::string>, Title, text);
        XPROPERTY(std::optional<std::string>, Title, align);
        XPROPERTY(std::optional<string_none_type>, Title, anchor);
        XPROPERTY(std::optional<double>, Title, angle);
        XPROPERTY(std::optional<std::string>, Title, baseline);
        XPROPERTY(std::optional<string_none_type>, Title, color);
        XPROPERTY(std::optional<double>, Title, dx);
        XPROPERTY(std::optional<double>, Title, dy);
        XPROPERTY(std::optional<std::string>, Title, font);
        XPROPERTY(std::optional<double>, Title, fontSize);
        XPROPERTY(std::optional<std::string>, Title, fontStyle);
        XPROPERTY(std::optional<string_num_type>, Title, fontWeight);
        XPROPERTY(std::optional<std::string>, Title, frame);
        XPROPERTY(std::optional<double>, Title, limit);
        XPROPERTY(std::optional<double>, Title, lineHeight);
        XPROPERTY(std::optional<double>, Title, offset);
        XPROPERTY(std::optional<std::string>, Title, orient);
        XPROPERTY(std::optional<std::vector<std::string>>, Title, style);
        XPROPERTY(std::optional<std::vector<std::string>>, Title, subtitle);
        XPROPERTY(std::optional<string_none_type>, Title, subtitleColor);
        XPROPERTY(std::optional<std::string>, Title, subtitleFont);
        XPROPERTY(std::optional<double>, Title, subtitleFontSize);
        XPROPERTY(std::optional<std::string>, Title, subtitleFontStyle);
        XPROPERTY(std::optional<string_num_type>, Title, subtitleFontWeight);
        XPROPERTY(std::optional<double>, Title, subtitleLineHeight);
        XPROPERTY(std::optional<double>, Title, subtitlePadding);
        XPROPERTY(std::optional<double>, Title, zindex);
    };

    XVEGA_API void to_json(nl::json& j, const Title& data);
}

#endif
