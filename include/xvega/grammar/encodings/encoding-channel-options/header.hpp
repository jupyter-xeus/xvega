// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_HEADER_HPP
#define XVEGA_ENCODING_OPTIONS_HEADER_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../../xvega_config.hpp"
#include "../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Header : public xp::xobserved<Header>
    {
        XPROPERTY(std::optional<string_vec_none_type>, Header, title);

        XPROPERTY(std::optional<string_object_type>, Header, format);
        XPROPERTY(std::optional<std::string>, Header, formatType);

        XPROPERTY(std::optional<std::string>, Header, labelAlign);
        XPROPERTY(std::optional<string_none_type>, Header, labelAnchor);
        XPROPERTY(std::optional<double>, Header, labelAngle);
        XPROPERTY(std::optional<std::string>, Header, labelBaseline);
        XPROPERTY(std::optional<string_none_type>, Header, labelColor);
        XPROPERTY(std::optional<std::string>, Header, labelExpr);
        XPROPERTY(std::optional<std::string>, Header, labelFont);
        XPROPERTY(std::optional<double>, Header, labelFontSize);
        XPROPERTY(std::optional<std::string>, Header, labelFontStyle);
        XPROPERTY(std::optional<string_num_type>, Header, labelFontWeight);
        XPROPERTY(std::optional<double>, Header, labelLimit);
        XPROPERTY(std::optional<double>, Header, labelLineHeight);
        XPROPERTY(std::optional<std::string>, Header, labelOrient);
        XPROPERTY(std::optional<double>, Header, labelPadding);

        XPROPERTY(std::optional<bool>, Header, labels);
        XPROPERTY(std::optional<std::string>, Header, orient);

        XPROPERTY(std::optional<std::string>, Header, titleAlign);
        XPROPERTY(std::optional<string_none_type>, Header, titleAnchor);
        XPROPERTY(std::optional<double>, Header, titleAngle);
        XPROPERTY(std::optional<std::string>, Header, titleBaseline);
        XPROPERTY(std::optional<string_none_type>, Header, titleColor);
        XPROPERTY(std::optional<std::string>, Header, titleFont);
        XPROPERTY(std::optional<double>, Header, titleFontSize);
        XPROPERTY(std::optional<std::string>, Header, titleFontStyle);
        XPROPERTY(std::optional<string_num_type>, Header, titleFontWeight);
        XPROPERTY(std::optional<double>, Header, titleLimit);
        XPROPERTY(std::optional<double>, Header, titleLineHeight);
        XPROPERTY(std::optional<std::string>, Header, titleOrient);
        XPROPERTY(std::optional<double>, Header, titlePadding);
    };

    XVEGA_API void to_json(nl::json& j, const Header& data);
}

#endif
