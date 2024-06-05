// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_HEADER_CONFIG_HPP
#define XVEGA_HEADER_CONFIG_HPP

#include <optional>

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    struct header_config : public xp::xobserved<header_config>
    {
        XPROPERTY(std::optional<string_vec_none_type>, header_config, title);

        XPROPERTY(std::optional<string_object_type>, header_config, format);
        XPROPERTY(std::optional<std::string>, header_config, formatType);

        XPROPERTY(std::optional<std::string>, header_config, labelAlign);
        XPROPERTY(std::optional<string_none_type>, header_config, labelAnchor);
        XPROPERTY(std::optional<double>, header_config, labelAngle);
        XPROPERTY(std::optional<std::string>, header_config, labelBaseline);
        XPROPERTY(std::optional<string_none_type>, header_config, labelColor);
        XPROPERTY(std::optional<std::string>, header_config, labelExpr);
        XPROPERTY(std::optional<std::string>, header_config, labelFont);
        XPROPERTY(std::optional<double>, header_config, labelFontSize);
        XPROPERTY(std::optional<std::string>, header_config, labelFontStyle);
        XPROPERTY(std::optional<string_num_type>, header_config, labelFontWeight);
        XPROPERTY(std::optional<double>, header_config, labelLimit);
        XPROPERTY(std::optional<double>, header_config, labelLineHeight);
        XPROPERTY(std::optional<std::string>, header_config, labelOrient);
        XPROPERTY(std::optional<double>, header_config, labelPadding);

        XPROPERTY(std::optional<bool>, header_config, labels);
        XPROPERTY(std::optional<std::string>, header_config, orient);

        XPROPERTY(std::optional<std::string>, header_config, titleAlign);
        XPROPERTY(std::optional<string_none_type>, header_config, titleAnchor);
        XPROPERTY(std::optional<double>, header_config, titleAngle);
        XPROPERTY(std::optional<std::string>, header_config, titleBaseline);
        XPROPERTY(std::optional<string_none_type>, header_config, titleColor);
        XPROPERTY(std::optional<std::string>, header_config, titleFont);
        XPROPERTY(std::optional<double>, header_config, titleFontSize);
        XPROPERTY(std::optional<std::string>, header_config, titleFontStyle);
        XPROPERTY(std::optional<string_num_type>, header_config, titleFontWeight);
        XPROPERTY(std::optional<double>, header_config, titleLimit);
        XPROPERTY(std::optional<double>, header_config, titleLineHeight);
        XPROPERTY(std::optional<std::string>, header_config, titleOrient);
        XPROPERTY(std::optional<double>, header_config, titlePadding);
    };

    XVEGA_API void to_json(nl::json& j, const header_config& data);
}

#endif
