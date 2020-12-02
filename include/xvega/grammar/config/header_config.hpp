// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_HEADER_CONFIG_HPP
#define XVEGA_HEADER_CONFIG_HPP

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    struct header_config : public xp::xobserved<header_config>
    {
        XPROPERTY(xtl::xoptional<string_vec_none_type>, header_config, title);

        XPROPERTY(xtl::xoptional<string_object_type>, header_config, format);
        XPROPERTY(xtl::xoptional<std::string>, header_config, formatType);

        XPROPERTY(xtl::xoptional<std::string>, header_config, labelAlign);
        XPROPERTY(xtl::xoptional<string_none_type>, header_config, labelAnchor);
        XPROPERTY(xtl::xoptional<double>, header_config, labelAngle);
        XPROPERTY(xtl::xoptional<std::string>, header_config, labelBaseline);
        XPROPERTY(xtl::xoptional<string_none_type>, header_config, labelColor);
        XPROPERTY(xtl::xoptional<std::string>, header_config, labelExpr);
        XPROPERTY(xtl::xoptional<std::string>, header_config, labelFont);
        XPROPERTY(xtl::xoptional<double>, header_config, labelFontSize);
        XPROPERTY(xtl::xoptional<std::string>, header_config, labelFontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, header_config, labelFontWeight);
        XPROPERTY(xtl::xoptional<double>, header_config, labelLimit);
        XPROPERTY(xtl::xoptional<double>, header_config, labelLineHeight);
        XPROPERTY(xtl::xoptional<std::string>, header_config, labelOrient);
        XPROPERTY(xtl::xoptional<double>, header_config, labelPadding);

        XPROPERTY(xtl::xoptional<bool>, header_config, labels);
        XPROPERTY(xtl::xoptional<std::string>, header_config, orient);

        XPROPERTY(xtl::xoptional<std::string>, header_config, titleAlign);
        XPROPERTY(xtl::xoptional<string_none_type>, header_config, titleAnchor);
        XPROPERTY(xtl::xoptional<double>, header_config, titleAngle);
        XPROPERTY(xtl::xoptional<std::string>, header_config, titleBaseline);
        XPROPERTY(xtl::xoptional<string_none_type>, header_config, titleColor);
        XPROPERTY(xtl::xoptional<std::string>, header_config, titleFont);
        XPROPERTY(xtl::xoptional<double>, header_config, titleFontSize);
        XPROPERTY(xtl::xoptional<std::string>, header_config, titleFontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, header_config, titleFontWeight);
        XPROPERTY(xtl::xoptional<double>, header_config, titleLimit);
        XPROPERTY(xtl::xoptional<double>, header_config, titleLineHeight);
        XPROPERTY(xtl::xoptional<std::string>, header_config, titleOrient);
        XPROPERTY(xtl::xoptional<double>, header_config, titlePadding);
    };

    XVEGA_API void to_json(nl::json& j, const header_config& data);
}

#endif
