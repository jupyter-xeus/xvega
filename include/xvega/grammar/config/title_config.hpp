// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TITLE_CONFIG_HPP
#define XVEGA_TITLE_CONFIG_HPP

#include <optional>

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    struct title_config : public xp::xobserved<title_config>
    {
        XPROPERTY(std::optional<std::string>, title_config, align);
        XPROPERTY(std::optional<string_none_type>, title_config, anchor);
        XPROPERTY(std::optional<double>, title_config, angle);
        XPROPERTY(std::optional<std::string>, title_config, baseline);
        XPROPERTY(std::optional<string_none_type>, title_config, color);
        XPROPERTY(std::optional<double>, title_config, dx);
        XPROPERTY(std::optional<double>, title_config, dy);
        XPROPERTY(std::optional<std::string>, title_config, font);
        XPROPERTY(std::optional<double>, title_config, fontSize);
        XPROPERTY(std::optional<std::string>, title_config, fontStyle);
        XPROPERTY(std::optional<string_num_type>, title_config, fontWeight);
        XPROPERTY(std::optional<std::string>, title_config, frame);
        XPROPERTY(std::optional<double>, title_config, limit);
        XPROPERTY(std::optional<double>, title_config, lineHeight);
        XPROPERTY(std::optional<double>, title_config, offset);
        XPROPERTY(std::optional<std::string>, title_config, orient);
        XPROPERTY(std::optional<string_none_type>, title_config, subtitleColor);
        XPROPERTY(std::optional<std::string>, title_config, subtitleFont);
        XPROPERTY(std::optional<double>, title_config, subtitleFontSize);
        XPROPERTY(std::optional<std::string>, title_config, subtitleFontStyle);
        XPROPERTY(std::optional<string_num_type>, title_config, subtitleFontWeight);
        XPROPERTY(std::optional<double>, title_config, subtitleLineHeight);
        XPROPERTY(std::optional<double>, title_config, subtitlePadding);
    };

    XVEGA_API void to_json(nl::json& j, const title_config& data);
}

#endif
