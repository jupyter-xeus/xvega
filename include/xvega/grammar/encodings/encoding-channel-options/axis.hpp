// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_AXIS_HPP
#define XVEGA_ENCODING_OPTIONS_AXIS_HPP

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
    struct Axis : public xp::xobserved<Axis>
    {
        // General Axis Properties
        XPROPERTY(std::optional<bool>, Axis, aria); // Not Present in Altair Docs, but present in Vega-Lite Docs
        XPROPERTY(std::optional<double>, Axis, bandPosition);
        XPROPERTY(std::optional<std::string>, Axis, description); // Not Present in Altair Docs, but present in Vega-Lite Docs
        XPROPERTY(std::optional<double>, Axis, maxExtent);
        XPROPERTY(std::optional<double>, Axis, minExtent);
        XPROPERTY(std::optional<std::string>, Axis, orient);
        XPROPERTY(std::optional<double>, Axis, offset);
        XPROPERTY(std::optional<double>, Axis, position);
        XPROPERTY(std::optional<std::vector<std::string>>, Axis, style);
        XPROPERTY(std::optional<double>, Axis, translate);
        XPROPERTY(std::optional<double>, Axis, zindex);

        // Domain Axis Properties
        XPROPERTY(std::optional<bool>, Axis, domain);
        XPROPERTY(std::optional<std::string>, Axis, domainCap); // Not Present in Altair Docs, but present in Vega-Lite Docs
        XPROPERTY(std::optional<string_none_type>, Axis, domainColor);
        XPROPERTY(std::optional<double>, Axis, domainOpacity);
        XPROPERTY(std::optional<double>, Axis, domainWidth);
        XPROPERTY(std::optional<std::vector<double>>, Axis, domainDash);
        XPROPERTY(std::optional<double>, Axis, domainDashOffset);

        // Label Axis Properties
        XPROPERTY(std::optional<string_object_type>, Axis, format);
        XPROPERTY(std::optional<std::string>, Axis, formatType);
        XPROPERTY(std::optional<bool>, Axis, labels);
        XPROPERTY(std::optional<std::string>, Axis, labelAlign); // Implement ConditionalAxisLabelAlign
        XPROPERTY(std::optional<double>, Axis, labelAngle);
        XPROPERTY(std::optional<std::string>, Axis, labelBaseline); // Implement ConditionalAxisLabelBaseline
        XPROPERTY(std::optional<bool_num_type>, Axis, labelBound);
        XPROPERTY(std::optional<string_none_type>, Axis, labelColor); // Implement ConditionalAxisColor
        XPROPERTY(std::optional<std::string>, Axis, labelExpr);
        XPROPERTY(std::optional<bool_num_type>, Axis, labelFlush);
        XPROPERTY(std::optional<double>, Axis, labelFlushOffset);
        XPROPERTY(std::optional<std::string>, Axis, labelFont); // Implement ConditionalAxisString
        XPROPERTY(std::optional<double>, Axis, labelFontSize); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<std::string>, Axis, labelFontStyle); // Implement ConditionalAxisLabelFontStyle
        XPROPERTY(std::optional<string_num_type>, Axis, labelFontWeight); // Implement ConditionalAxisLabelFontWeight
        XPROPERTY(std::optional<double>, Axis, labelLimit);
        XPROPERTY(std::optional<double>, Axis, labelLineHeight);
        XPROPERTY(std::optional<double>, Axis, labelOffset); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<double>, Axis, labelOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<bool_string_type>, Axis, labelOverlap);
        XPROPERTY(std::optional<double>, Axis, labelPadding); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<double>, Axis, labelSeparation);

        // Ticks Axis Properties
        XPROPERTY(std::optional<bool>, Axis, ticks);
        XPROPERTY(std::optional<std::string>, Axis, tickBand);
        XPROPERTY(std::optional<std::string>, Axis, tickCap); // Not Present in Altair Docs, but present in Vega-Lite Docs
        XPROPERTY(std::optional<string_none_type>, Axis, tickColor); // Implement ConditionalAxisColor
        XPROPERTY(std::optional<double>, Axis, tickCount); // Difference in Altair and Vega-Lite docs for it's type
        XPROPERTY(std::optional<std::vector<double>>, Axis, tickDash); // Implement ConditionalAxisNumberArray
        XPROPERTY(std::optional<double>, Axis, tickDashOffset); // Implement ConditionalAxisNumber, Present in Altair Docs, but not present in Vega-Lite Docs
        XPROPERTY(std::optional<bool>, Axis, tickExtra);
        XPROPERTY(std::optional<double>, Axis, tickMinStep);
        XPROPERTY(std::optional<double>, Axis, tickOffset);
        XPROPERTY(std::optional<double>, Axis, tickOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<bool>, Axis, tickRound);
        XPROPERTY(std::optional<double>, Axis, tickSize); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<double>, Axis, tickWidth); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<any_array_type>, Axis, values);

        // Title Axis Properties
        XPROPERTY(std::optional<string_vec_none_type>, Axis, title);
        XPROPERTY(std::optional<std::string>, Axis, titleAlign);
        XPROPERTY(std::optional<string_none_type>, Axis, titleAnchor);
        XPROPERTY(std::optional<double>, Axis, titleAngle);
        XPROPERTY(std::optional<std::string>, Axis, titleBaseline);
        XPROPERTY(std::optional<string_none_type>, Axis, titleColor);
        XPROPERTY(std::optional<std::string>, Axis, titleFont);
        XPROPERTY(std::optional<double>, Axis, titleFontSize);
        XPROPERTY(std::optional<std::string>, Axis, titleFontStyle);
        XPROPERTY(std::optional<string_num_type>, Axis, titleFontWeight);
        XPROPERTY(std::optional<double>, Axis, titleLimit);
        XPROPERTY(std::optional<double>, Axis, titleLineHeight);
        XPROPERTY(std::optional<double>, Axis, titleOpacity);
        XPROPERTY(std::optional<double>, Axis, titlePadding);
        XPROPERTY(std::optional<double>, Axis, titleX);
        XPROPERTY(std::optional<double>, Axis, titleY);

        // Grid Axis Properties
        XPROPERTY(std::optional<bool>, Axis, grid);
        XPROPERTY(std::optional<std::string>, Axis, gridCap); // Not Present in Altair Docs, but present in Vega-Lite Docs
        XPROPERTY(std::optional<string_none_type>, Axis, gridColor); // Implement ConditionalAxisColor
        XPROPERTY(std::optional<std::vector<double>>, Axis, gridDash); // Implement ConditionalAxisNumberArray
        XPROPERTY(std::optional<double>, Axis, gridDashOffset); // Implement ConditionalAxisNumber, Present in Altair Docs, but not present in Vega-Lite Docs
        XPROPERTY(std::optional<double>, Axis, gridOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<double>, Axis, gridWidth); // Implement ConditionalAxisNumber
    };

    XVEGA_API void to_json(nl::json& j, const Axis& data);

    using axis_type = std::variant<Axis, std::nullptr_t>;
}

#endif
