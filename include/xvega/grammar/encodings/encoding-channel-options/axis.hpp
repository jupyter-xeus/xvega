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
#include "../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_num_type = xtl::variant<double, int, std::string>;
    using string_none_type = xtl::variant<std::nullptr_t, std::string>;
    using string_object_type = xtl::variant<nl::json, std::string>;
    using bool_num_type = xtl::variant<double, int, bool>;
    using bool_string_type = xtl::variant<std::string, bool>;
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;
    using any_array_type = xtl::variant<
                                std::vector<std::string>, 
                                std::vector<double>, 
                                std::vector<int>, 
                                std::vector<bool>, 
                                std::vector<DateTime>
                                >;

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
        XPROPERTY(xtl::xoptional<string_none_type>, Axis, domainColor);
        XPROPERTY(xtl::xoptional<double>, Axis, domainOpacity);
        XPROPERTY(xtl::xoptional<double>, Axis, domainWidth);
        XPROPERTY(xtl::xoptional<std::vector<double>>, Axis, domainDash);
        XPROPERTY(xtl::xoptional<double>, Axis, domainDashOffset);

        // Label Axis Properties
        XPROPERTY(xtl::xoptional<string_object_type>, Axis, format);
        XPROPERTY(xtl::xoptional<std::string>, Axis, formatType);
        XPROPERTY(xtl::xoptional<bool>, Axis, labels);
        XPROPERTY(xtl::xoptional<std::string>, Axis, labelAlign); // Implement ConditionalAxisLabelAlign
        XPROPERTY(xtl::xoptional<double>, Axis, labelAngle);
        XPROPERTY(xtl::xoptional<std::string>, Axis, labelBaseline); // Implement ConditionalAxisLabelBaseline
        XPROPERTY(xtl::xoptional<bool_num_type>, Axis, labelBound);
        XPROPERTY(xtl::xoptional<string_none_type>, Axis, labelColor); // Implement ConditionalAxisColor
        XPROPERTY(xtl::xoptional<std::string>, Axis, labelExpr);
        XPROPERTY(xtl::xoptional<bool_num_type>, Axis, labelFlush);
        XPROPERTY(xtl::xoptional<double>, Axis, labelFlushOffset);
        XPROPERTY(xtl::xoptional<std::string>, Axis, labelFont); // Implement ConditionalAxisString
        XPROPERTY(xtl::xoptional<double>, Axis, labelFontSize); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<std::string>, Axis, labelFontStyle); // Implement ConditionalAxisLabelFontStyle
        XPROPERTY(xtl::xoptional<string_num_type>, Axis, labelFontWeight); // Implement ConditionalAxisLabelFontWeight
        XPROPERTY(xtl::xoptional<double>, Axis, labelLimit);
        XPROPERTY(xtl::xoptional<double>, Axis, labelLineHeight);
        XPROPERTY(xtl::xoptional<double>, Axis, labelOffset); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<double>, Axis, labelOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<bool_string_type>, Axis, labelOverlap);
        XPROPERTY(xtl::xoptional<double>, Axis, labelPadding); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<double>, Axis, labelSeparation);

        // Ticks Axis Properties
        XPROPERTY(xtl::xoptional<bool>, Axis, ticks);
        XPROPERTY(xtl::xoptional<std::string>, Axis, tickBand);
        XPROPERTY(xtl::xoptional<std::string>, Axis, tickCap); // Not Present in Altair Docs, but present in Vega-Lite Docs
        XPROPERTY(xtl::xoptional<string_none_type>, Axis, tickColor); // Implement ConditionalAxisColor
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
        XPROPERTY(xtl::xoptional<any_array_type>, Axis, values);

        // Title Axis Properties
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Axis, title);
        XPROPERTY(xtl::xoptional<std::string>, Axis, titleAlign);
        XPROPERTY(xtl::xoptional<string_none_type>, Axis, titleAnchor);
        XPROPERTY(xtl::xoptional<double>, Axis, titleAngle);
        XPROPERTY(xtl::xoptional<std::string>, Axis, titleBaseline);
        XPROPERTY(xtl::xoptional<string_none_type>, Axis, titleColor);
        XPROPERTY(xtl::xoptional<std::string>, Axis, titleFont);
        XPROPERTY(xtl::xoptional<double>, Axis, titleFontSize);
        XPROPERTY(xtl::xoptional<std::string>, Axis, titleFontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, Axis, titleFontWeight);
        XPROPERTY(xtl::xoptional<double>, Axis, titleLimit);
        XPROPERTY(xtl::xoptional<double>, Axis, titleLineHeight);
        XPROPERTY(xtl::xoptional<double>, Axis, titleOpacity);
        XPROPERTY(xtl::xoptional<double>, Axis, titlePadding);
        XPROPERTY(xtl::xoptional<double>, Axis, titleX);
        XPROPERTY(xtl::xoptional<double>, Axis, titleY);

        // Grid Axis Properties
        XPROPERTY(xtl::xoptional<bool>, Axis, grid);
        XPROPERTY(xtl::xoptional<std::string>, Axis, gridCap); // Not Present in Altair Docs, but present in Vega-Lite Docs
        XPROPERTY(xtl::xoptional<string_none_type>, Axis, gridColor); // Implement ConditionalAxisColor
        XPROPERTY(xtl::xoptional<std::vector<double>>, Axis, gridDash); // Implement ConditionalAxisNumberArray
        XPROPERTY(xtl::xoptional<double>, Axis, gridDashOffset); // Implement ConditionalAxisNumber, Present in Altair Docs, but not present in Vega-Lite Docs
        XPROPERTY(xtl::xoptional<double>, Axis, gridOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<double>, Axis, gridWidth); // Implement ConditionalAxisNumber
    };

    void to_json(nl::json& j, const Axis& data)
    {
        // Fill in General Axis Properties
        serialize(j, data.aria(), "aria");
        serialize(j, data.bandPosition(), "bandPosition");
        serialize(j, data.description(), "description");
        serialize(j, data.maxExtent(), "maxExtent");
        serialize(j, data.minExtent(), "minExtent");
        serialize(j, data.orient(), "orient");
        serialize(j, data.offset(), "offset");
        serialize(j, data.position(), "position");
        serialize(j, data.style(), "style");
        serialize(j, data.translate(), "translate");
        serialize(j, data.zindex(), "zindex");

        // Fill in Domain Axis Properties
        serialize(j, data.domain(), "domain");
        serialize(j, data.domainCap(), "domainCap");
        serialize(j, data.domainColor(), "domainColor");
        serialize(j, data.domainOpacity(), "domainOpacity");
        serialize(j, data.domainWidth(), "domainWidth");
        serialize(j, data.domainDash(), "domainDash");
        serialize(j, data.domainDashOffset(), "domainDashOffset");

        // Fill in Label Axis Properties
        serialize(j, data.format(), "format");
        serialize(j, data.formatType(), "formatType");
        serialize(j, data.labels(), "labels");
        serialize(j, data.labelAlign(), "labelAlign");
        serialize(j, data.labelAngle(), "labelAngle");
        serialize(j, data.labelBaseline(), "labelBaseline");
        serialize(j, data.labelBound(), "labelBound");
        serialize(j, data.labelColor(), "labelColor");
        serialize(j, data.labelExpr(), "labelExpr");
        serialize(j, data.labelFlush(), "labelFlush");
        serialize(j, data.labelFlushOffset(), "labelFlushOffset");
        serialize(j, data.labelFont(), "labelFont");
        serialize(j, data.labelFontSize(), "labelFontSize");
        serialize(j, data.labelFontStyle(), "labelFontStyle");
        serialize(j, data.labelFontWeight(), "labelFontWeight");
        serialize(j, data.labelLimit(), "labelLimit");
        serialize(j, data.labelLineHeight(), "labelLineHeight");
        serialize(j, data.labelOffset(), "labelOffset");
        serialize(j, data.labelOpacity(), "labelOpacity");
        serialize(j, data.labelOverlap(), "labelOverlap");
        serialize(j, data.labelPadding(), "labelPadding");
        serialize(j, data.labelSeparation(), "labelSeparation");

        // Fill in Ticks Axis Properties
        serialize(j, data.ticks(), "ticks");
        serialize(j, data.tickBand(), "tickBand");
        serialize(j, data.tickCap(), "tickCap");
        serialize(j, data.tickColor(), "tickColor");
        serialize(j, data.tickCount(), "tickCount");
        serialize(j, data.tickDash(), "tickDash");
        serialize(j, data.tickDashOffset(), "tickDashOffset");
        serialize(j, data.tickExtra(), "tickExtra");
        serialize(j, data.tickMinStep(), "tickMinStep");
        serialize(j, data.tickOffset(), "tickOffset");
        serialize(j, data.tickOpacity(), "tickOpacity");
        serialize(j, data.tickRound(), "tickRound");
        serialize(j, data.tickSize(), "tickSize");
        serialize(j, data.tickWidth(), "tickWidth");
        serialize(j, data.values(), "values");

        // Fill in Title Axis Properties
        serialize(j, data.title(), "title");
        serialize(j, data.titleAlign(), "titleAlign");
        serialize(j, data.titleAnchor(), "titleAnchor");
        serialize(j, data.titleAngle(), "titleAngle");
        serialize(j, data.titleBaseline(), "titleBaseline");
        serialize(j, data.titleColor(), "titleColor");
        serialize(j, data.titleFont(), "titleFont");
        serialize(j, data.titleFontSize(), "titleFontSize");
        serialize(j, data.titleFontStyle(), "titleFontStyle");
        serialize(j, data.titleFontWeight(), "titleFontWeight");
        serialize(j, data.titleLimit(), "titleLimit");
        serialize(j, data.titleLineHeight(), "titleLineHeight");
        serialize(j, data.titleOpacity(), "titleOpacity");
        serialize(j, data.titlePadding(), "titlePadding");
        serialize(j, data.titleX(), "titleX");
        serialize(j, data.titleY(), "titleY");
        
        // Fill in Grid Axis Properties
        serialize(j, data.grid(), "grid");
        serialize(j, data.gridCap(), "gridCap");
        serialize(j, data.gridColor(), "gridColor");
        serialize(j, data.gridDash(), "gridDash");
        serialize(j, data.gridDashOffset(), "gridDashOffset");
        serialize(j, data.gridOpacity(), "gridOpacity");
        serialize(j, data.gridWidth(), "gridWidth");
    }

    using axis_type = xtl::variant<Axis, std::nullptr_t>;
}

#endif