// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_LEGEND_CONFIG_HPP
#define XVEGA_LEGEND_CONFIG_HPP

#include <optional>

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    struct legend_config : public xp::xobserved<legend_config>
    {
        XPROPERTY(std::optional<double>, legend_config, clipHeight);
        XPROPERTY(std::optional<double>, legend_config, columnPadding);
        XPROPERTY(std::optional<double>, legend_config, columns);
        XPROPERTY(std::optional<double>, legend_config, cornerRadius);
        XPROPERTY(std::optional<std::string>, legend_config, direction);
        XPROPERTY(std::optional<bool>, legend_config, disable);
        XPROPERTY(std::optional<string_none_type>, legend_config, fillColor);
        XPROPERTY(std::optional<std::string>, legend_config, gradientDirection);
        XPROPERTY(std::optional<double>, legend_config, gradientHorizontalMaxLength);
        XPROPERTY(std::optional<double>, legend_config, gradientHorizontalMinLength);
        XPROPERTY(std::optional<double>, legend_config, gradientLabelLimit);
        XPROPERTY(std::optional<double>, legend_config, gradientLabelOffset);
        XPROPERTY(std::optional<double>, legend_config, gradientLength);
        XPROPERTY(std::optional<double>, legend_config, gradientOpacity);
        XPROPERTY(std::optional<string_none_type>, legend_config, gradientStrokeColor);
        XPROPERTY(std::optional<double>, legend_config, gradientStrokeWidth);
        XPROPERTY(std::optional<double>, legend_config, gradientThickness);
        XPROPERTY(std::optional<double>, legend_config, gradientVerticalMaxLength);
        XPROPERTY(std::optional<double>, legend_config, gradientVerticalMinLength);
        XPROPERTY(std::optional<std::string>, legend_config, gridAlign);
        XPROPERTY(std::optional<std::string>, legend_config, labelAlign);
        XPROPERTY(std::optional<std::string>, legend_config, labelBaseline);
        XPROPERTY(std::optional<string_none_type>, legend_config, labelColor);
        XPROPERTY(std::optional<std::string>, legend_config, labelFont);
        XPROPERTY(std::optional<double>, legend_config, labelFontSize);
        XPROPERTY(std::optional<std::string>, legend_config, labelFontStyle);
        XPROPERTY(std::optional<string_num_type>, legend_config, labelFontWeight);
        XPROPERTY(std::optional<double>, legend_config, labelLimit);
        XPROPERTY(std::optional<double>, legend_config, labelOffset);
        XPROPERTY(std::optional<double>, legend_config, labelOpacity);
        XPROPERTY(std::optional<bool_string_type>, legend_config, labelOverlap);
        XPROPERTY(std::optional<double>, legend_config, labelPadding);
        XPROPERTY(std::optional<double>, legend_config, labelSeparation);
        XPROPERTY(std::optional<double>, legend_config, legendX);
        XPROPERTY(std::optional<double>, legend_config, legendY);
        XPROPERTY(std::optional<double>, legend_config, offset);
        XPROPERTY(std::optional<std::string>, legend_config, orient);
        XPROPERTY(std::optional<double>, legend_config, padding);
        XPROPERTY(std::optional<double>, legend_config, rowPadding);
        XPROPERTY(std::optional<string_none_type>, legend_config, strokeColor);
        XPROPERTY(std::optional<std::vector<double>>, legend_config, strokeDash);
        XPROPERTY(std::optional<double>, legend_config, strokeWidth);
        XPROPERTY(std::optional<string_none_type>, legend_config, symbolBaseFillColor);
        XPROPERTY(std::optional<string_none_type>, legend_config, symbolBaseStrokeColor);
        XPROPERTY(std::optional<std::vector<double>>, legend_config, symbolDash);
        XPROPERTY(std::optional<double>, legend_config, symbolDashOffset);
        XPROPERTY(std::optional<std::string>, legend_config, symbolDirection);
        XPROPERTY(std::optional<string_none_type>, legend_config, symbolFillColor);
        XPROPERTY(std::optional<double>, legend_config, symbolLimit);
        XPROPERTY(std::optional<double>, legend_config, symbolOffset);
        XPROPERTY(std::optional<double>, legend_config, symbolOpacity);
        XPROPERTY(std::optional<double>, legend_config, symbolSize);
        XPROPERTY(std::optional<string_none_type>, legend_config, symbolStrokeColor);
        XPROPERTY(std::optional<double>, legend_config, symbolStrokeWidth);
        XPROPERTY(std::optional<std::string>, legend_config, symbolType);
        XPROPERTY(std::optional<string_num_type>, legend_config, tickCount);
        XPROPERTY(std::optional<string_vec_none_type>, legend_config, title);
        XPROPERTY(std::optional<std::string>, legend_config, titleAlign);
        XPROPERTY(std::optional<string_none_type>, legend_config, titleAnchor);
        XPROPERTY(std::optional<std::string>, legend_config, titleBaseline);
        XPROPERTY(std::optional<string_none_type>, legend_config, titleColor);
        XPROPERTY(std::optional<std::string>, legend_config, titleFont);
        XPROPERTY(std::optional<double>, legend_config, titleFontSize);
        XPROPERTY(std::optional<std::string>, legend_config, titleFontStyle);
        XPROPERTY(std::optional<string_num_type>, legend_config, titleFontWeight);
        XPROPERTY(std::optional<double>, legend_config, titleLimit);
        XPROPERTY(std::optional<double>, legend_config, titleLineHeight);
        XPROPERTY(std::optional<double>, legend_config, titleOpacity);
        XPROPERTY(std::optional<std::string>, legend_config, titleOrient);
        XPROPERTY(std::optional<double>, legend_config, titlePadding);
        XPROPERTY(std::optional<double>, legend_config, unselectedOpacity);
    };

    XVEGA_API void to_json(nl::json& j, const legend_config& data);
}

#endif
