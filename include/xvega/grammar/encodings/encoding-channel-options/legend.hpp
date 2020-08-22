// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_LEGEND_HPP
#define XVEGA_ENCODING_OPTIONS_LEGEND_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "./datetime.hpp"
#include "../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_none_type = xtl::variant<std::nullptr_t, std::string>;
    using any_array_type = xtl::variant<
                                std::vector<std::string>, 
                                std::vector<double>, 
                                std::vector<int>, 
                                std::vector<bool>, 
                                std::vector<DateTime>
                                >;
    using string_num_type = xtl::variant<double, int, std::string>;
    using string_object_type = xtl::variant<nl::json, std::string>;
    using bool_string_type = xtl::variant<std::string, bool>;
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;

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

    void to_json(nl::json& j, const Legend& data)
    {
        // Fill in General Legend Properties
        serialize(j, data.aria(), "aria");
        serialize(j, data.cornerRadius(), "cornerRadius");
        serialize(j, data.description(), "description");
        serialize(j, data.direction(), "direction");
        serialize(j, data.fillColor(), "fillColor");
        serialize(j, data.legendX(), "legendX");
        serialize(j, data.legendY(), "legendY");
        serialize(j, data.offset(), "offset");
        serialize(j, data.orient(), "orient");
        serialize(j, data.padding(), "padding");
        serialize(j, data.strokeColor(), "strokeColor");
        serialize(j, data.type(), "type");
        serialize(j, data.tickCount(), "tickCount");
        serialize(j, data.tickMinStep(), "tickMinStep");
        serialize(j, data.values(), "values");
        serialize(j, data.zindex(), "zindex");

        // Fill in Gradient Legend Properties
        serialize(j, data.gradientLength(), "gradientLength");
        serialize(j, data.gradientOpacity(), "gradientOpacity");
        serialize(j, data.gradientStrokeColor(), "gradientStrokeColor");
        serialize(j, data.gradientStrokeWidth(), "gradientStrokeWidth");
        serialize(j, data.gradientThickness(), "gradientThickness");

        // Fill in Labels Legend Properties
        serialize(j, data.format(), "format");
        serialize(j, data.formatType(), "formatType");
        serialize(j, data.labelAlign(), "labelAlign");
        serialize(j, data.labelBaseline(), "labelBaseline");
        serialize(j, data.labelColor(), "labelColor");
        serialize(j, data.labelFont(), "labelFont");
        serialize(j, data.labelFontSize(), "labelFontSize");
        serialize(j, data.labelFontStyle(), "labelFontStyle");
        serialize(j, data.labelFontWeight(), "labelFontWeight");
        serialize(j, data.labelLimit(), "labelLimit");
        serialize(j, data.labelOffset(), "labelOffset");
        serialize(j, data.labelOverlap(), "labelOverlap");
        serialize(j, data.labelPadding(), "labelPadding");
        serialize(j, data.labelSeparation(), "labelSeparation");

        // Fill in Symbols Legend Properties
        serialize(j, data.symbolDash(), "symbolDash");
        serialize(j, data.symbolDashOffset(), "symbolDashOffset");
        serialize(j, data.symbolFillColor(), "symbolFillColor");
        serialize(j, data.symbolOffset(), "symbolOffset");
        serialize(j, data.symbolOpacity(), "symbolOpacity");
        serialize(j, data.symbolSize(), "symbolSize");
        serialize(j, data.symbolStrokeColor(), "symbolStrokeColor");
        serialize(j, data.symbolStrokeWidth(), "symbolStrokeWidth");
        serialize(j, data.symbolType(), "symbolType");

        // Fill in Symbol Layout Legend Properties
        serialize(j, data.clipHeight(), "clipHeight");
        serialize(j, data.columnPadding(), "columnPadding");
        serialize(j, data.columns(), "columns");
        serialize(j, data.gridAlign(), "gridAlign");
        serialize(j, data.rowPadding(), "rowPadding");
        serialize(j, data.symbolLimit(), "symbolLimit");
        
        // Fill in Title Legend Properties
        serialize(j, data.title(), "title");
        serialize(j, data.titleAlign(), "titleAlign");
        serialize(j, data.titleAnchor(), "titleAnchor");
        serialize(j, data.titleBaseline(), "titleBaseline");
        serialize(j, data.titleColor(), "titleColor");
        serialize(j, data.titleFont(), "titleFont");
        serialize(j, data.titleFontSize(), "titleFontSize");
        serialize(j, data.titleFontStyle(), "titleFontStyle");
        serialize(j, data.titleFontWeight(), "titleFontWeight");
        serialize(j, data.titleLimit(), "titleLimit");
        serialize(j, data.titleLineHeight(), "titleLineHeight");
        serialize(j, data.titleOpacity(), "titleOpacity");
        serialize(j, data.titleOrient(), "titleOrient");
        serialize(j, data.titlePadding(), "titlePadding");
    }

    using legend_type = xtl::variant<Legend, std::nullptr_t>;
}

#endif