// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_LEGEND_HPP
#define XVEGA_ENCODING_OPTIONS_LEGEND_HPP

#include <optional>
#include <variant>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "./datetime.hpp"
#include "../../../xvega_config.hpp"
#include "../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Legend : public xp::xobserved<Legend>
    {
        // General Legend Properties
        XPROPERTY(std::optional<bool>, Legend, aria);
        XPROPERTY(std::optional<double>, Legend, cornerRadius);
        XPROPERTY(std::optional<std::string>, Legend, description);
        XPROPERTY(std::optional<std::string>, Legend, direction);
        XPROPERTY(std::optional<string_none_type>, Legend, fillColor);
        XPROPERTY(std::optional<double>, Legend, legendX);
        XPROPERTY(std::optional<double>, Legend, legendY);
        XPROPERTY(std::optional<double>, Legend, offset);
        XPROPERTY(std::optional<std::string>, Legend, orient);
        XPROPERTY(std::optional<double>, Legend, padding);
        XPROPERTY(std::optional<string_none_type>, Legend, strokeColor);
        XPROPERTY(std::optional<std::string>, Legend, type);
        XPROPERTY(std::optional<string_num_type>, Legend, tickCount);
        XPROPERTY(std::optional<double>, Legend, tickMinStep);
        XPROPERTY(std::optional<any_array_type>, Legend, values);
        XPROPERTY(std::optional<double>, Legend, zindex);

        // Gradient Legend Properties
        XPROPERTY(std::optional<double>, Legend, gradientLength);
        XPROPERTY(std::optional<double>, Legend, gradientOpacity);
        XPROPERTY(std::optional<string_none_type>, Legend, gradientStrokeColor);
        XPROPERTY(std::optional<double>, Legend, gradientStrokeWidth);
        XPROPERTY(std::optional<double>, Legend, gradientThickness);

        // Labels Legend Properties
        XPROPERTY(std::optional<string_object_type>, Legend, format);
        XPROPERTY(std::optional<std::string>, Legend, formatType);
        XPROPERTY(std::optional<std::string>, Legend, labelAlign);
        XPROPERTY(std::optional<std::string>, Legend, labelBaseline);
        XPROPERTY(std::optional<string_none_type>, Legend, labelColor);
        XPROPERTY(std::optional<std::string>, Legend, labelFont);
        XPROPERTY(std::optional<double>, Legend, labelFontSize);
        XPROPERTY(std::optional<std::string>, Legend, labelFontStyle);
        XPROPERTY(std::optional<string_num_type>, Legend, labelFontWeight);
        XPROPERTY(std::optional<double>, Legend, labelLimit);
        XPROPERTY(std::optional<double>, Legend, labelOffset);
        XPROPERTY(std::optional<bool_string_type>, Legend, labelOverlap);
        XPROPERTY(std::optional<double>, Legend, labelPadding);
        XPROPERTY(std::optional<double>, Legend, labelSeparation);

        // Symbols Legend Properties
        XPROPERTY(std::optional<std::vector<double>>, Legend, symbolDash);
        XPROPERTY(std::optional<double>, Legend, symbolDashOffset);
        XPROPERTY(std::optional<string_none_type>, Legend, symbolFillColor);
        XPROPERTY(std::optional<double>, Legend, symbolOffset);
        XPROPERTY(std::optional<double>, Legend, symbolOpacity);
        XPROPERTY(std::optional<double>, Legend, symbolSize);
        XPROPERTY(std::optional<string_none_type>, Legend, symbolStrokeColor);
        XPROPERTY(std::optional<double>, Legend, symbolStrokeWidth);
        XPROPERTY(std::optional<std::string>, Legend, symbolType);

        // Symbol Layout Legend Properties
        XPROPERTY(std::optional<double>, Legend, clipHeight);
        XPROPERTY(std::optional<double>, Legend, columnPadding);
        XPROPERTY(std::optional<double>, Legend, columns);
        XPROPERTY(std::optional<std::string>, Legend, gridAlign);
        XPROPERTY(std::optional<double>, Legend, rowPadding);
        XPROPERTY(std::optional<double>, Legend, symbolLimit);

        // Title Legend Properties
        XPROPERTY(std::optional<string_vec_none_type>, Legend, title);
        XPROPERTY(std::optional<std::string>, Legend, titleAlign);
        XPROPERTY(std::optional<string_none_type>, Legend, titleAnchor);
        XPROPERTY(std::optional<std::string>, Legend, titleBaseline);
        XPROPERTY(std::optional<string_none_type>, Legend, titleColor);
        XPROPERTY(std::optional<std::string>, Legend, titleFont);
        XPROPERTY(std::optional<double>, Legend, titleFontSize);
        XPROPERTY(std::optional<std::string>, Legend, titleFontStyle);
        XPROPERTY(std::optional<string_num_type>, Legend, titleFontWeight);
        XPROPERTY(std::optional<double>, Legend, titleLimit);
        XPROPERTY(std::optional<double>, Legend, titleLineHeight);
        XPROPERTY(std::optional<double>, Legend, titleOpacity);
        XPROPERTY(std::optional<std::string>, Legend, titleOrient);
        XPROPERTY(std::optional<double>, Legend, titlePadding);
    };

    XVEGA_API void to_json(nl::json& j, const Legend& data);

    using legend_type = std::variant<Legend, std::nullptr_t>;
}

#endif
