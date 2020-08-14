// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_AXIS_HPP
#define XVEGA_ENCODING_OPTIONS_AXIS_HPP

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
    using stringObjectType = xtl::variant<nl::json, std::string>;
    using boolNumType = xtl::variant<double, int, bool>;
    using boolStringType = xtl::variant<std::string, bool>;
    using stringVecNoneType = xtl::variant<std::vector<std::string>, std::nullptr_t>;
    using anyArrayType = xtl::variant<std::vector<std::string>, std::vector<double>, std::vector<int>, std::vector<bool>, std::vector<DateTime>>;

    struct Axis : public xp::xobserved<Axis>
    {
        // General Axis Properties
        XPROPERTY(xtl::xoptional<bool>, Axis, aria); // Not Present in Altair Docs, but present in Vega-Lite Docs
        XPROPERTY(xtl::xoptional<double>, Axis, bandPosition);
        XPROPERTY(xtl::xoptional<std::string>, Axis, description); // Not Present in Altair Docs, but present in Vega-Lite Docs
        XPROPERTY(xtl::xoptional<double>, Axis, maxExtent);
        XPROPERTY(xtl::xoptional<double>, Axis, minExtent);
        XPROPERTY(xtl::xoptional<std::string>, Axis, orient);
        XPROPERTY(xtl::xoptional<double>, Axis, offset);
        XPROPERTY(xtl::xoptional<double>, Axis, position);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, Axis, style);
        XPROPERTY(xtl::xoptional<double>, Axis, translate);
        XPROPERTY(xtl::xoptional<double>, Axis, zindex);

        // Domain Axis Properties
        XPROPERTY(xtl::xoptional<bool>, Axis, domain);
        XPROPERTY(xtl::xoptional<std::string>, Axis, domainCap); // Not Present in Altair Docs, but present in Vega-Lite Docs
        XPROPERTY(xtl::xoptional<stringNoneType>, Axis, domainColor);
        XPROPERTY(xtl::xoptional<double>, Axis, domainOpacity);
        XPROPERTY(xtl::xoptional<double>, Axis, domainWidth);
        XPROPERTY(xtl::xoptional<std::vector<double>>, Axis, domainDash);
        XPROPERTY(xtl::xoptional<double>, Axis, domainDashOffset);

        // Label Axis Properties
        XPROPERTY(xtl::xoptional<stringObjectType>, Axis, format);
        XPROPERTY(xtl::xoptional<std::string>, Axis, formatType);
        XPROPERTY(xtl::xoptional<bool>, Axis, labels);
        XPROPERTY(xtl::xoptional<std::string>, Axis, labelAlign); // Implement ConditionalAxisLabelAlign
        XPROPERTY(xtl::xoptional<double>, Axis, labelAngle);
        XPROPERTY(xtl::xoptional<std::string>, Axis, labelBaseline); // Implement ConditionalAxisLabelBaseline
        XPROPERTY(xtl::xoptional<boolNumType>, Axis, labelBound);
        XPROPERTY(xtl::xoptional<stringNoneType>, Axis, labelColor); // Implement ConditionalAxisColor
        XPROPERTY(xtl::xoptional<std::string>, Axis, labelExpr);
        XPROPERTY(xtl::xoptional<boolNumType>, Axis, labelFlush);
        XPROPERTY(xtl::xoptional<double>, Axis, labelFlushOffset);
        XPROPERTY(xtl::xoptional<std::string>, Axis, labelFont); // Implement ConditionalAxisString
        XPROPERTY(xtl::xoptional<double>, Axis, labelFontSize); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<std::string>, Axis, labelFontStyle); // Implement ConditionalAxisLabelFontStyle
        XPROPERTY(xtl::xoptional<stringNumType>, Axis, labelFontWeight); // Implement ConditionalAxisLabelFontWeight
        XPROPERTY(xtl::xoptional<double>, Axis, labelLimit);
        XPROPERTY(xtl::xoptional<double>, Axis, labelLineHeight);
        XPROPERTY(xtl::xoptional<double>, Axis, labelOffset); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<double>, Axis, labelOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<boolStringType>, Axis, labelOverlap);
        XPROPERTY(xtl::xoptional<double>, Axis, labelPadding); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<double>, Axis, labelSeparation);

        // Ticks Axis Properties
        XPROPERTY(xtl::xoptional<bool>, Axis, ticks);
        XPROPERTY(xtl::xoptional<std::string>, Axis, tickBand);
        XPROPERTY(xtl::xoptional<std::string>, Axis, tickCap); // Not Present in Altair Docs, but present in Vega-Lite Docs
        XPROPERTY(xtl::xoptional<stringNoneType>, Axis, tickColor); // Implement ConditionalAxisColor
        XPROPERTY(xtl::xoptional<double>, Axis, tickCount); // Difference in Altair and Vega-Lite docs for it's type
        XPROPERTY(xtl::xoptional<std::vector<double>>, Axis, tickDash); // Implement ConditionalAxisNumberArray
        XPROPERTY(xtl::xoptional<double>, Axis, tickDashOffset); // Implement ConditionalAxisNumber, Present in Altair Docs, but not present in Vega-Lite Docs
        XPROPERTY(xtl::xoptional<bool>, Axis, tickExtra);
        XPROPERTY(xtl::xoptional<double>, Axis, tickMinStep);
        XPROPERTY(xtl::xoptional<double>, Axis, tickOffset);
        XPROPERTY(xtl::xoptional<double>, Axis, tickOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<bool>, Axis, tickRound);
        XPROPERTY(xtl::xoptional<double>, Axis, tickSize); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<double>, Axis, tickWidth); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<anyArrayType>, Axis, values);

        // Title Axis Properties
        XPROPERTY(xtl::xoptional<stringVecNoneType>, Axis, title);
        XPROPERTY(xtl::xoptional<std::string>, Axis, titleAlign);
        XPROPERTY(xtl::xoptional<stringNoneType>, Axis, titleAnchor);
        XPROPERTY(xtl::xoptional<double>, Axis, titleAngle);
        XPROPERTY(xtl::xoptional<std::string>, Axis, titleBaseline);
        XPROPERTY(xtl::xoptional<stringNoneType>, Axis, titleColor);
        XPROPERTY(xtl::xoptional<std::string>, Axis, titleFont);
        XPROPERTY(xtl::xoptional<double>, Axis, titleFontSize);
        XPROPERTY(xtl::xoptional<std::string>, Axis, titleFontStyle);
        XPROPERTY(xtl::xoptional<stringNumType>, Axis, titleFontWeight);
        XPROPERTY(xtl::xoptional<double>, Axis, titleLimit);
        XPROPERTY(xtl::xoptional<double>, Axis, titleLineHeight);
        XPROPERTY(xtl::xoptional<double>, Axis, titleOpacity);
        XPROPERTY(xtl::xoptional<double>, Axis, titlePadding);
        XPROPERTY(xtl::xoptional<double>, Axis, titleX);
        XPROPERTY(xtl::xoptional<double>, Axis, titleY);

        // Grid Axis Properties
        XPROPERTY(xtl::xoptional<bool>, Axis, grid);
        XPROPERTY(xtl::xoptional<std::string>, Axis, gridCap); // Not Present in Altair Docs, but present in Vega-Lite Docs
        XPROPERTY(xtl::xoptional<stringNoneType>, Axis, gridColor); // Implement ConditionalAxisColor
        XPROPERTY(xtl::xoptional<std::vector<double>>, Axis, gridDash); // Implement ConditionalAxisNumberArray
        XPROPERTY(xtl::xoptional<double>, Axis, gridDashOffset); // Implement ConditionalAxisNumber, Present in Altair Docs, but not present in Vega-Lite Docs
        XPROPERTY(xtl::xoptional<double>, Axis, gridOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<double>, Axis, gridWidth); // Implement ConditionalAxisNumber
    };

    void to_json(nl::json& j, const Axis& data)
    {
        if(data.aria().has_value())
        {
            j["aria"] = data.aria().value();
        }
        if(data.bandPosition().has_value())
        {
            j["bandPosition"] = data.bandPosition().value();
        }
        if(data.description().has_value())
        {
            j["description"] = data.description().value();
        }
        if(data.maxExtent().has_value())
        {
            j["maxExtent"] = data.maxExtent().value();
        }
        if(data.minExtent().has_value())
        {
            j["minExtent"] = data.minExtent().value();
        }
        if(data.orient().has_value())
        {
            j["orient"] = data.orient().value();
        }
        if(data.offset().has_value())
        {
            j["offset"] = data.offset().value();
        }
        if(data.position().has_value())
        {
            j["position"] = data.position().value();
        }
        if(data.style().has_value())
        {
            j["style"] = data.style().value();
        }
        if(data.translate().has_value())
        {
            j["translate"] = data.translate().value();
        }
        if(data.zindex().has_value())
        {
            j["zindex"] = data.zindex().value();
        }
        if(data.domain().has_value())
        {
            j["domain"] = data.domain().value();
        }
        if(data.domainCap().has_value())
        {
            j["domainCap"] = data.domainCap().value();
        }
        if(data.domainColor().has_value())
        {
            j["domainColor"] = data.domainColor().value();
        }
        if(data.domainOpacity().has_value())
        {
            j["domainOpacity"] = data.domainOpacity().value();
        }
        if(data.domainWidth().has_value())
        {
            j["domainWidth"] = data.domainWidth().value();
        }
        if(data.domainDash().has_value())
        {
            j["domainDash"] = data.domainDash().value();
        }
        if(data.domainDashOffset().has_value())
        {
            j["domainDashOffset"] = data.domainDashOffset().value();
        }
        if(data.format().has_value())
        {
            j["format"] = data.format().value();
        }
        if(data.formatType().has_value())
        {
            j["formatType"] = data.formatType().value();
        }
        if(data.labels().has_value())
        {
            j["labels"] = data.labels().value();
        }
        if(data.labelAlign().has_value())
        {
            j["labelAlign"] = data.labelAlign().value();
        }
        if(data.labelAngle().has_value())
        {
            j["labelAngle"] = data.labelAngle().value();
        }
        if(data.labelBaseline().has_value())
        {
            j["labelBaseline"] = data.labelBaseline().value();
        }
        if(data.labelBound().has_value())
        {
            j["labelBound"] = data.labelBound().value();
        }
        if(data.labelColor().has_value())
        {
            j["labelColor"] = data.labelColor().value();
        }
        if(data.labelExpr().has_value())
        {
            j["labelExpr"] = data.labelExpr().value();
        }
        if(data.labelFlush().has_value())
        {
            j["labelFlush"] = data.labelFlush().value();
        }
        if(data.labelFlushOffset().has_value())
        {
            j["labelFlushOffset"] = data.labelFlushOffset().value();
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
        if(data.labelLineHeight().has_value())
        {
            j["labelLineHeight"] = data.labelLineHeight().value();
        }
        if(data.labelOffset().has_value())
        {
            j["labelOffset"] = data.labelOffset().value();
        }
        if(data.labelOpacity().has_value())
        {
            j["labelOpacity"] = data.labelOpacity().value();
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
        if(data.ticks().has_value())
        {
            j["ticks"] = data.ticks().value();
        }
        if(data.tickBand().has_value())
        {
            j["tickBand"] = data.tickBand().value();
        }
        if(data.tickCap().has_value())
        {
            j["tickCap"] = data.tickCap().value();
        }
        if(data.tickColor().has_value())
        {
            j["tickColor"] = data.tickColor().value();
        }
        if(data.tickCount().has_value())
        {
            j["tickCount"] = data.tickCount().value();
        }
        if(data.tickDash().has_value())
        {
            j["tickDash"] = data.tickDash().value();
        }
        if(data.tickDashOffset().has_value())
        {
            j["tickDashOffset"] = data.tickDashOffset().value();
        }
        if(data.tickExtra().has_value())
        {
            j["tickExtra"] = data.tickExtra().value();
        }
        if(data.tickMinStep().has_value())
        {
            j["tickMinStep"] = data.tickMinStep().value();
        }
        if(data.tickOffset().has_value())
        {
            j["tickOffset"] = data.tickOffset().value();
        }
        if(data.tickOpacity().has_value())
        {
            j["tickOpacity"] = data.tickOpacity().value();
        }
        if(data.tickRound().has_value())
        {
            j["tickRound"] = data.tickRound().value();
        }
        if(data.tickSize().has_value())
        {
            j["tickSize"] = data.tickSize().value();
        }
        if(data.tickWidth().has_value())
        {
            j["tickWidth"] = data.tickWidth().value();
        }
        if(data.values().has_value())
        {
            j["values"] = data.values().value();
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
        if(data.titleAngle().has_value())
        {
            j["titleAngle"] = data.titleAngle().value();
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
        if(data.titlePadding().has_value())
        {
            j["titlePadding"] = data.titlePadding().value();
        }
        if(data.titleX().has_value())
        {
            j["titleX"] = data.titleX().value();
        }
        if(data.titleY().has_value())
        {
            j["titleY"] = data.titleY().value();
        }
        if(data.grid().has_value())
        {
            j["grid"] = data.grid().value();
        }
        if(data.gridCap().has_value())
        {
            j["gridCap"] = data.gridCap().value();
        }
        if(data.gridColor().has_value())
        {
            j["gridColor"] = data.gridColor().value();
        }
        if(data.gridDash().has_value())
        {
            j["gridDash"] = data.gridDash().value();
        }
        if(data.gridDashOffset().has_value())
        {
            j["gridDashOffset"] = data.gridDashOffset().value();
        }
        if(data.gridOpacity().has_value())
        {
            j["gridOpacity"] = data.gridOpacity().value();
        }
        if(data.gridWidth().has_value())
        {
            j["gridWidth"] = data.gridWidth().value();
        }
    }

    using axisType = xtl::variant<Axis, std::nullptr_t>;
}

#endif