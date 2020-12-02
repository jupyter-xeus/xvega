// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_LEGEND_HPP
#define XVEGA_ENCODING_OPTIONS_LEGEND_HPP

#include <xproperty/xobserved.hpp>

#include <xtl/xoptional.hpp>
#include <xtl/xjson.hpp>

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
        XPROPERTY(xtl::xoptional<bool>, Legend, aria);
        XPROPERTY(xtl::xoptional<double>, Legend, cornerRadius);
        XPROPERTY(xtl::xoptional<std::string>, Legend, description);
        XPROPERTY(xtl::xoptional<std::string>, Legend, direction);
        XPROPERTY(xtl::xoptional<string_none_type>, Legend, fillColor);
        XPROPERTY(xtl::xoptional<double>, Legend, legendX);
        XPROPERTY(xtl::xoptional<double>, Legend, legendY);
        XPROPERTY(xtl::xoptional<double>, Legend, offset);
        XPROPERTY(xtl::xoptional<std::string>, Legend, orient);
        XPROPERTY(xtl::xoptional<double>, Legend, padding);
        XPROPERTY(xtl::xoptional<string_none_type>, Legend, strokeColor);
        XPROPERTY(xtl::xoptional<std::string>, Legend, type);
        XPROPERTY(xtl::xoptional<string_num_type>, Legend, tickCount);
        XPROPERTY(xtl::xoptional<double>, Legend, tickMinStep);
        XPROPERTY(xtl::xoptional<any_array_type>, Legend, values);
        XPROPERTY(xtl::xoptional<double>, Legend, zindex);

        // Gradient Legend Properties
        XPROPERTY(xtl::xoptional<double>, Legend, gradientLength);
        XPROPERTY(xtl::xoptional<double>, Legend, gradientOpacity);
        XPROPERTY(xtl::xoptional<string_none_type>, Legend, gradientStrokeColor);
        XPROPERTY(xtl::xoptional<double>, Legend, gradientStrokeWidth);
        XPROPERTY(xtl::xoptional<double>, Legend, gradientThickness);

        // Labels Legend Properties
        XPROPERTY(xtl::xoptional<string_object_type>, Legend, format);
        XPROPERTY(xtl::xoptional<std::string>, Legend, formatType);
        XPROPERTY(xtl::xoptional<std::string>, Legend, labelAlign);
        XPROPERTY(xtl::xoptional<std::string>, Legend, labelBaseline);
        XPROPERTY(xtl::xoptional<string_none_type>, Legend, labelColor);
        XPROPERTY(xtl::xoptional<std::string>, Legend, labelFont);
        XPROPERTY(xtl::xoptional<double>, Legend, labelFontSize);
        XPROPERTY(xtl::xoptional<std::string>, Legend, labelFontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, Legend, labelFontWeight);
        XPROPERTY(xtl::xoptional<double>, Legend, labelLimit);
        XPROPERTY(xtl::xoptional<double>, Legend, labelOffset);
        XPROPERTY(xtl::xoptional<bool_string_type>, Legend, labelOverlap);
        XPROPERTY(xtl::xoptional<double>, Legend, labelPadding);
        XPROPERTY(xtl::xoptional<double>, Legend, labelSeparation);

        // Symbols Legend Properties
        XPROPERTY(xtl::xoptional<std::vector<double>>, Legend, symbolDash);
        XPROPERTY(xtl::xoptional<double>, Legend, symbolDashOffset);
        XPROPERTY(xtl::xoptional<string_none_type>, Legend, symbolFillColor);
        XPROPERTY(xtl::xoptional<double>, Legend, symbolOffset);
        XPROPERTY(xtl::xoptional<double>, Legend, symbolOpacity);
        XPROPERTY(xtl::xoptional<double>, Legend, symbolSize);
        XPROPERTY(xtl::xoptional<string_none_type>, Legend, symbolStrokeColor);
        XPROPERTY(xtl::xoptional<double>, Legend, symbolStrokeWidth);
        XPROPERTY(xtl::xoptional<std::string>, Legend, symbolType);

        // Symbol Layout Legend Properties
        XPROPERTY(xtl::xoptional<double>, Legend, clipHeight);
        XPROPERTY(xtl::xoptional<double>, Legend, columnPadding);
        XPROPERTY(xtl::xoptional<double>, Legend, columns);
        XPROPERTY(xtl::xoptional<std::string>, Legend, gridAlign);
        XPROPERTY(xtl::xoptional<double>, Legend, rowPadding);
        XPROPERTY(xtl::xoptional<double>, Legend, symbolLimit);

        // Title Legend Properties
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Legend, title);
        XPROPERTY(xtl::xoptional<std::string>, Legend, titleAlign);
        XPROPERTY(xtl::xoptional<string_none_type>, Legend, titleAnchor);
        XPROPERTY(xtl::xoptional<std::string>, Legend, titleBaseline);
        XPROPERTY(xtl::xoptional<string_none_type>, Legend, titleColor);
        XPROPERTY(xtl::xoptional<std::string>, Legend, titleFont);
        XPROPERTY(xtl::xoptional<double>, Legend, titleFontSize);
        XPROPERTY(xtl::xoptional<std::string>, Legend, titleFontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, Legend, titleFontWeight);
        XPROPERTY(xtl::xoptional<double>, Legend, titleLimit);
        XPROPERTY(xtl::xoptional<double>, Legend, titleLineHeight);
        XPROPERTY(xtl::xoptional<double>, Legend, titleOpacity);
        XPROPERTY(xtl::xoptional<std::string>, Legend, titleOrient);
        XPROPERTY(xtl::xoptional<double>, Legend, titlePadding);
    };

    XVEGA_API void to_json(nl::json& j, const Legend& data);

    using legend_type = xtl::variant<Legend, std::nullptr_t>;
}

#endif
