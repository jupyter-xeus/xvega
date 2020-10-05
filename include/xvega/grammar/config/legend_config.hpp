// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_LEGEND_CONFIG_HPP
#define XVEGA_LEGEND_CONFIG_HPP

#include "../../xvega_config.hpp"
#include "xproperty/xobserved.hpp"
#include "../../utils/xeither.hpp"
#include "../../utils/custom_datatypes.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    using bool_string_type = xtl::variant<std::string, bool>;
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct legend_config : public xp::xobserved<legend_config>
    {
        XPROPERTY(xtl::xoptional<double>, legend_config, clipHeight);
        XPROPERTY(xtl::xoptional<double>, legend_config, columnPadding);
        XPROPERTY(xtl::xoptional<double>, legend_config, columns);
        XPROPERTY(xtl::xoptional<double>, legend_config, cornerRadius);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, direction);
        XPROPERTY(xtl::xoptional<bool>, legend_config, disable);
        XPROPERTY(xtl::xoptional<string_none_type>, legend_config, fillColor);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, gradientDirection);
        XPROPERTY(xtl::xoptional<double>, legend_config, gradientHorizontalMaxLength);
        XPROPERTY(xtl::xoptional<double>, legend_config, gradientHorizontalMinLength);
        XPROPERTY(xtl::xoptional<double>, legend_config, gradientLabelLimit);
        XPROPERTY(xtl::xoptional<double>, legend_config, gradientLabelOffset);
        XPROPERTY(xtl::xoptional<double>, legend_config, gradientLength);
        XPROPERTY(xtl::xoptional<double>, legend_config, gradientOpacity);
        XPROPERTY(xtl::xoptional<string_none_type>, legend_config, gradientStrokeColor);
        XPROPERTY(xtl::xoptional<double>, legend_config, gradientStrokeWidth);
        XPROPERTY(xtl::xoptional<double>, legend_config, gradientThickness);
        XPROPERTY(xtl::xoptional<double>, legend_config, gradientVerticalMaxLength);
        XPROPERTY(xtl::xoptional<double>, legend_config, gradientVerticalMinLength);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, gridAlign);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, labelAlign);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, labelBaseline);
        XPROPERTY(xtl::xoptional<string_none_type>, legend_config, labelColor);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, labelFont);
        XPROPERTY(xtl::xoptional<double>, legend_config, labelFontSize);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, labelFontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, legend_config, labelFontWeight);
        XPROPERTY(xtl::xoptional<double>, legend_config, labelLimit);
        XPROPERTY(xtl::xoptional<double>, legend_config, labelOffset);
        XPROPERTY(xtl::xoptional<double>, legend_config, labelOpacity);
        XPROPERTY(xtl::xoptional<bool_string_type>, legend_config, labelOverlap);
        XPROPERTY(xtl::xoptional<double>, legend_config, labelPadding);
        XPROPERTY(xtl::xoptional<double>, legend_config, labelSeparation);
        XPROPERTY(xtl::xoptional<double>, legend_config, legendX);
        XPROPERTY(xtl::xoptional<double>, legend_config, legendY);
        XPROPERTY(xtl::xoptional<double>, legend_config, offset);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, orient);
        XPROPERTY(xtl::xoptional<double>, legend_config, padding);
        XPROPERTY(xtl::xoptional<double>, legend_config, rowPadding);
        XPROPERTY(xtl::xoptional<string_none_type>, legend_config, strokeColor);
        XPROPERTY(xtl::xoptional<std::vector<double>>, legend_config, strokeDash);
        XPROPERTY(xtl::xoptional<double>, legend_config, strokeWidth);
        XPROPERTY(xtl::xoptional<string_none_type>, legend_config, symbolBaseFillColor);
        XPROPERTY(xtl::xoptional<string_none_type>, legend_config, symbolBaseStrokeColor);
        XPROPERTY(xtl::xoptional<std::vector<double>>, legend_config, symbolDash);
        XPROPERTY(xtl::xoptional<double>, legend_config, symbolDashOffset);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, symbolDirection);
        XPROPERTY(xtl::xoptional<string_none_type>, legend_config, symbolFillColor);
        XPROPERTY(xtl::xoptional<double>, legend_config, symbolLimit);
        XPROPERTY(xtl::xoptional<double>, legend_config, symbolOffset);
        XPROPERTY(xtl::xoptional<double>, legend_config, symbolOpacity);
        XPROPERTY(xtl::xoptional<double>, legend_config, symbolSize);
        XPROPERTY(xtl::xoptional<string_none_type>, legend_config, symbolStrokeColor);
        XPROPERTY(xtl::xoptional<double>, legend_config, symbolStrokeWidth);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, symbolType);
        XPROPERTY(xtl::xoptional<string_num_type>, legend_config, tickCount);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, legend_config, title);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, titleAlign);
        XPROPERTY(xtl::xoptional<string_none_type>, legend_config, titleAnchor);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, titleBaseline);
        XPROPERTY(xtl::xoptional<string_none_type>, legend_config, titleColor);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, titleFont);
        XPROPERTY(xtl::xoptional<double>, legend_config, titleFontSize);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, titleFontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, legend_config, titleFontWeight);
        XPROPERTY(xtl::xoptional<double>, legend_config, titleLimit);
        XPROPERTY(xtl::xoptional<double>, legend_config, titleLineHeight);
        XPROPERTY(xtl::xoptional<double>, legend_config, titleOpacity);
        XPROPERTY(xtl::xoptional<std::string>, legend_config, titleOrient);
        XPROPERTY(xtl::xoptional<double>, legend_config, titlePadding);
        XPROPERTY(xtl::xoptional<double>, legend_config, unselectedOpacity);
    };

    void to_json(nl::json& j, const legend_config& data);
}

#endif