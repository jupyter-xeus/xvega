// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TITLE_CONFIG_HPP
#define XVEGA_TITLE_CONFIG_HPP

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    struct title_config : public xp::xobserved<title_config>
    {
        XPROPERTY(xtl::xoptional<std::string>, title_config, align);
        XPROPERTY(xtl::xoptional<string_none_type>, title_config, anchor);
        XPROPERTY(xtl::xoptional<double>, title_config, angle);
        XPROPERTY(xtl::xoptional<std::string>, title_config, baseline);
        XPROPERTY(xtl::xoptional<string_none_type>, title_config, color);
        XPROPERTY(xtl::xoptional<double>, title_config, dx);
        XPROPERTY(xtl::xoptional<double>, title_config, dy);
        XPROPERTY(xtl::xoptional<std::string>, title_config, font);
        XPROPERTY(xtl::xoptional<double>, title_config, fontSize);
        XPROPERTY(xtl::xoptional<std::string>, title_config, fontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, title_config, fontWeight);
        XPROPERTY(xtl::xoptional<std::string>, title_config, frame);
        XPROPERTY(xtl::xoptional<double>, title_config, limit);
        XPROPERTY(xtl::xoptional<double>, title_config, lineHeight);
        XPROPERTY(xtl::xoptional<double>, title_config, offset);
        XPROPERTY(xtl::xoptional<std::string>, title_config, orient);
        XPROPERTY(xtl::xoptional<string_none_type>, title_config, subtitleColor);
        XPROPERTY(xtl::xoptional<std::string>, title_config, subtitleFont);
        XPROPERTY(xtl::xoptional<double>, title_config, subtitleFontSize);
        XPROPERTY(xtl::xoptional<std::string>, title_config, subtitleFontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, title_config, subtitleFontWeight);
        XPROPERTY(xtl::xoptional<double>, title_config, subtitleLineHeight);
        XPROPERTY(xtl::xoptional<double>, title_config, subtitlePadding);
    };

    XVEGA_API void to_json(nl::json& j, const title_config& data);
}

#endif
