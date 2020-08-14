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

namespace nl = nlohmann;

namespace xv
{
    using stringNoneType = xtl::variant<std::nullptr_t, std::string>;
    using anyArrayType = xtl::variant<std::vector<std::string>, std::vector<double>, std::vector<int>, std::vector<bool>, std::vector<DateTime>>;
    using stringNumType = xtl::variant<double, int, std::string>;
    using stringObjectType = xtl::variant<nl::json, std::string>;
    using boolStringType = xtl::variant<std::string, bool>;
    using stringVecNoneType = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct Legend : public xp::xobserved<Legend>
    {
        // General Legend Properties
        XPROPERTY(xtl::xoptional<bool>, Legend, aria);
        XPROPERTY(xtl::xoptional<double>, Legend, cornerRadius);
        XPROPERTY(xtl::xoptional<std::string>, Legend, description);
        XPROPERTY(xtl::xoptional<std::string>, Legend, direction);
        XPROPERTY(xtl::xoptional<stringNoneType>, Legend, fillColor);
        XPROPERTY(xtl::xoptional<double>, Legend, legendX);
        XPROPERTY(xtl::xoptional<double>, Legend, legendY);
        XPROPERTY(xtl::xoptional<double>, Legend, offset);
        XPROPERTY(xtl::xoptional<std::string>, Legend, orient);
        XPROPERTY(xtl::xoptional<double>, Legend, padding);
        XPROPERTY(xtl::xoptional<stringNoneType>, Legend, strokeColor);
        XPROPERTY(xtl::xoptional<std::string>, Legend, type);
        XPROPERTY(xtl::xoptional<stringNumType>, Legend, tickCount);
        XPROPERTY(xtl::xoptional<double>, Legend, tickMinStep);
        XPROPERTY(xtl::xoptional<anyArrayType>, Legend, values);
        XPROPERTY(xtl::xoptional<double>, Legend, zindex);

        // Gradient Legend Properties
        XPROPERTY(xtl::xoptional<double>, Legend, gradientLength);
        XPROPERTY(xtl::xoptional<double>, Legend, gradientOpacity);
        XPROPERTY(xtl::xoptional<stringNoneType>, Legend, gradientStrokeColor);
        XPROPERTY(xtl::xoptional<double>, Legend, gradientStrokeWidth);
        XPROPERTY(xtl::xoptional<double>, Legend, gradientThickness);

        // Labels Legend Properties
        XPROPERTY(xtl::xoptional<stringObjectType>, Legend, format);
        XPROPERTY(xtl::xoptional<std::string>, Legend, formatType);
        XPROPERTY(xtl::xoptional<std::string>, Legend, labelAlign);
        XPROPERTY(xtl::xoptional<std::string>, Legend, labelBaseline);
        XPROPERTY(xtl::xoptional<stringNoneType>, Legend, labelColor);
        XPROPERTY(xtl::xoptional<std::string>, Legend, labelFont);
        XPROPERTY(xtl::xoptional<double>, Legend, labelFontSize);
        XPROPERTY(xtl::xoptional<std::string>, Legend, labelFontStyle);
        XPROPERTY(xtl::xoptional<stringNumType>, Legend, labelFontWeight);
        XPROPERTY(xtl::xoptional<double>, Legend, labelLimit);
        XPROPERTY(xtl::xoptional<double>, Legend, labelOffset);
        XPROPERTY(xtl::xoptional<boolStringType>, Legend, labelOverlap);
        XPROPERTY(xtl::xoptional<double>, Legend, labelPadding);
        XPROPERTY(xtl::xoptional<double>, Legend, labelSeparation);

        // Symbols Legend Properties
        XPROPERTY(xtl::xoptional<std::vector<double>>, Legend, symbolDash);
        XPROPERTY(xtl::xoptional<double>, Legend, symbolDashOffset);
        XPROPERTY(xtl::xoptional<stringNoneType>, Legend, symbolFillColor);
        XPROPERTY(xtl::xoptional<double>, Legend, symbolOffset);
        XPROPERTY(xtl::xoptional<double>, Legend, symbolOpacity);
        XPROPERTY(xtl::xoptional<double>, Legend, symbolSize);
        XPROPERTY(xtl::xoptional<stringNoneType>, Legend, symbolStrokeColor);
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
        XPROPERTY(xtl::xoptional<stringVecNoneType>, Legend, title);
        XPROPERTY(xtl::xoptional<std::string>, Legend, titleAlign);
        XPROPERTY(xtl::xoptional<stringNoneType>, Legend, titleAnchor);
        XPROPERTY(xtl::xoptional<std::string>, Legend, titleBaseline);
        XPROPERTY(xtl::xoptional<stringNoneType>, Legend, titleColor);
        XPROPERTY(xtl::xoptional<std::string>, Legend, titleFont);
        XPROPERTY(xtl::xoptional<double>, Legend, titleFontSize);
        XPROPERTY(xtl::xoptional<std::string>, Legend, titleFontStyle);
        XPROPERTY(xtl::xoptional<stringNumType>, Legend, titleFontWeight);
        XPROPERTY(xtl::xoptional<double>, Legend, titleLimit);
        XPROPERTY(xtl::xoptional<double>, Legend, titleLineHeight);
        XPROPERTY(xtl::xoptional<double>, Legend, titleOpacity);
        XPROPERTY(xtl::xoptional<std::string>, Legend, titleOrient);
        XPROPERTY(xtl::xoptional<double>, Legend, titlePadding);
    };

    void to_json(nl::json& j, const Legend& data)
    {
        if(data.aria().has_value())
        {
            j["aria"] = data.aria().value();
        }
        if(data.cornerRadius().has_value())
        {
            j["cornerRadius"] = data.cornerRadius().value();
        }
        if(data.description().has_value())
        {
            j["description"] = data.description().value();
        }
        if(data.direction().has_value())
        {
            j["direction"] = data.direction().value();
        }
        if(data.fillColor().has_value())
        {
            j["fillColor"] = data.fillColor().value();
        }
        if(data.legendX().has_value())
        {
            j["legendX"] = data.legendX().value();
        }
        if(data.legendY().has_value())
        {
            j["legendY"] = data.legendY().value();
        }
        if(data.offset().has_value())
        {
            j["offset"] = data.offset().value();
        }
        if(data.orient().has_value())
        {
            j["orient"] = data.orient().value();
        }
        if(data.padding().has_value())
        {
            j["padding"] = data.padding().value();
        }
        if(data.strokeColor().has_value())
        {
            j["strokeColor"] = data.strokeColor().value();
        }
        if(data.type().has_value())
        {
            j["type"] = data.type().value();
        }
        if(data.tickCount().has_value())
        {
            j["tickCount"] = data.tickCount().value();
        }
        if(data.tickMinStep().has_value())
        {
            j["tickMinStep"] = data.tickMinStep().value();
        }
        if(data.values().has_value())
        {
            j["values"] = data.values().value();
        }
        if(data.zindex().has_value())
        {
            j["zindex"] = data.zindex().value();
        }
        if(data.gradientLength().has_value())
        {
            j["gradientLength"] = data.gradientLength().value();
        }
        if(data.gradientOpacity().has_value())
        {
            j["gradientOpacity"] = data.gradientOpacity().value();
        }
        if(data.gradientStrokeColor().has_value())
        {
            j["gradientStrokeColor"] = data.gradientStrokeColor().value();
        }
        if(data.gradientStrokeWidth().has_value())
        {
            j["gradientStrokeWidth"] = data.gradientStrokeWidth().value();
        }
        if(data.gradientThickness().has_value())
        {
            j["gradientThickness"] = data.gradientThickness().value();
        }
        if(data.format().has_value())
        {
            j["format"] = data.format().value();
        }
        if(data.formatType().has_value())
        {
            j["formatType"] = data.formatType().value();
        }
        if(data.labelAlign().has_value())
        {
            j["labelAlign"] = data.labelAlign().value();
        }
        if(data.labelBaseline().has_value())
        {
            j["labelBaseline"] = data.labelBaseline().value();
        }
        if(data.labelColor().has_value())
        {
            j["labelColor"] = data.labelColor().value();
        }
        if(data.labelFont().has_value())
        {
            j["labelFont"] = data.labelFont().value();
        }
        if(data.labelFontSize().has_value())
        {
            j["labelFontSize"] = data.labelFontSize().value();
        }
        if(data.labelFontStyle().has_value())
        {
            j["labelFontStyle"] = data.labelFontStyle().value();
        }
        if(data.labelFontWeight().has_value())
        {
            j["labelFontWeight"] = data.labelFontWeight().value();
        }
        if(data.labelLimit().has_value())
        {
            j["labelLimit"] = data.labelLimit().value();
        }
        if(data.labelOffset().has_value())
        {
            j["labelOffset"] = data.labelOffset().value();
        }
        if(data.labelOverlap().has_value())
        {
            j["labelOverlap"] = data.labelOverlap().value();
        }
        if(data.labelPadding().has_value())
        {
            j["labelPadding"] = data.labelPadding().value();
        }
        if(data.labelSeparation().has_value())
        {
            j["labelSeparation"] = data.labelSeparation().value();
        }
        if(data.symbolDash().has_value())
        {
            j["symbolDash"] = data.symbolDash().value();
        }
        if(data.symbolDashOffset().has_value())
        {
            j["symbolDashOffset"] = data.symbolDashOffset().value();
        }
        if(data.symbolFillColor().has_value())
        {
            j["symbolFillColor"] = data.symbolFillColor().value();
        }
        if(data.symbolOffset().has_value())
        {
            j["symbolOffset"] = data.symbolOffset().value();
        }
        if(data.symbolOpacity().has_value())
        {
            j["symbolOpacity"] = data.symbolOpacity().value();
        }
        if(data.symbolSize().has_value())
        {
            j["symbolSize"] = data.symbolSize().value();
        }
        if(data.symbolStrokeColor().has_value())
        {
            j["symbolStrokeColor"] = data.symbolStrokeColor().value();
        }
        if(data.symbolStrokeWidth().has_value())
        {
            j["symbolStrokeWidth"] = data.symbolStrokeWidth().value();
        }
        if(data.symbolType().has_value())
        {
            j["symbolType"] = data.symbolType().value();
        }
        if(data.clipHeight().has_value())
        {
            j["clipHeight"] = data.clipHeight().value();
        }
        if(data.columnPadding().has_value())
        {
            j["columnPadding"] = data.columnPadding().value();
        }
        if(data.columns().has_value())
        {
            j["columns"] = data.columns().value();
        }
        if(data.gridAlign().has_value())
        {
            j["gridAlign"] = data.gridAlign().value();
        }
        if(data.rowPadding().has_value())
        {
            j["rowPadding"] = data.rowPadding().value();
        }
        if(data.symbolLimit().has_value())
        {
            j["symbolLimit"] = data.symbolLimit().value();
        }
        if(data.title().has_value())
        {
            j["title"] = data.title().value();
        }
        if(data.titleAlign().has_value())
        {
            j["titleAlign"] = data.titleAlign().value();
        }
        if(data.titleAnchor().has_value())
        {
            j["titleAnchor"] = data.titleAnchor().value();
        }
        if(data.titleBaseline().has_value())
        {
            j["titleBaseline"] = data.titleBaseline().value();
        }
        if(data.titleColor().has_value())
        {
            j["titleColor"] = data.titleColor().value();
        }
        if(data.titleFont().has_value())
        {
            j["titleFont"] = data.titleFont().value();
        }
        if(data.titleFontSize().has_value())
        {
            j["titleFontSize"] = data.titleFontSize().value();
        }
        if(data.titleFontStyle().has_value())
        {
            j["titleFontStyle"] = data.titleFontStyle().value();
        }
        if(data.titleFontWeight().has_value())
        {
            j["titleFontWeight"] = data.titleFontWeight().value();
        }
        if(data.titleLimit().has_value())
        {
            j["titleLimit"] = data.titleLimit().value();
        }
        if(data.titleLineHeight().has_value())
        {
            j["titleLineHeight"] = data.titleLineHeight().value();
        }
        if(data.titleOpacity().has_value())
        {
            j["titleOpacity"] = data.titleOpacity().value();
        }
        if(data.titleOrient().has_value())
        {
            j["titleOrient"] = data.titleOrient().value();
        }
        if(data.titlePadding().has_value())
        {
            j["titlePadding"] = data.titlePadding().value();
        }
    }

    using legendType = xtl::variant<Legend, std::nullptr_t>;
}

#endif