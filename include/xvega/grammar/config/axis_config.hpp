// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_AXIS_CONFIG_HPP
#define XVEGA_AXIS_CONFIG_HPP

#include <optional>

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    struct axis_config : public xp::xobserved<axis_config>
    {
        XPROPERTY(std::optional<double>, axis_config, bandPosition);
        XPROPERTY(std::optional<bool>, axis_config, disable);
        XPROPERTY(std::optional<bool>, axis_config, domain);
        XPROPERTY(std::optional<string_none_type>, axis_config, domainColor);
        XPROPERTY(std::optional<std::vector<double>>, axis_config, domainDash);
        XPROPERTY(std::optional<double>, axis_config, domainDashOffset);
        XPROPERTY(std::optional<double>, axis_config, domainOpacity);
        XPROPERTY(std::optional<double>, axis_config, domainWidth);
        XPROPERTY(std::optional<bool>, axis_config, grid);
        XPROPERTY(std::optional<string_none_type>, axis_config, gridColor); // Implement ConditionalAxisColor
        XPROPERTY(std::optional<std::vector<double>>, axis_config, gridDash); // Implement ConditionalAxisNumberArray
        XPROPERTY(std::optional<double>, axis_config, gridDashOffset); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<double>, axis_config, gridOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<double>, axis_config, gridWidth); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<std::string>, axis_config, labelAlign); // Implement ConditionalAxisLabelAlign
        XPROPERTY(std::optional<double>, axis_config, labelAngle);
        XPROPERTY(std::optional<std::string>, axis_config, labelBaseline); // Implement ConditionalAxisLabelBaseline
        XPROPERTY(std::optional<bool_num_type>, axis_config, labelBound);
        XPROPERTY(std::optional<string_none_type>, axis_config, labelColor); // Implement ConditionalAxisColor
        XPROPERTY(std::optional<std::string>, axis_config, labelExpr);
        XPROPERTY(std::optional<bool_num_type>, axis_config, labelFlush);
        XPROPERTY(std::optional<double>, axis_config, labelFlushOffset);
        XPROPERTY(std::optional<std::string>, axis_config, labelFont); // Implement ConditionalAxisString
        XPROPERTY(std::optional<double>, axis_config, labelFontSize); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<std::string>, axis_config, labelFontStyle); // Implement ConditionalAxisLabelFontStyle
        XPROPERTY(std::optional<string_num_type>, axis_config, labelFontWeight); // Implement ConditionalAxisLabelFontWeight
        XPROPERTY(std::optional<double>, axis_config, labelLimit);
        XPROPERTY(std::optional<double>, axis_config, labelLineHeight);
        XPROPERTY(std::optional<double>, axis_config, labelOffset); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<double>, axis_config, labelOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<bool_string_type>, axis_config, labelOverlap);
        XPROPERTY(std::optional<double>, axis_config, labelPadding); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<double>, axis_config, labelSeparation);
        XPROPERTY(std::optional<bool>, axis_config, labels);
        XPROPERTY(std::optional<double>, axis_config, maxExtent);
        XPROPERTY(std::optional<double>, axis_config, minExtent);
        XPROPERTY(std::optional<std::string>, axis_config, orient);
        XPROPERTY(std::optional<double>, axis_config, offset);
        XPROPERTY(std::optional<std::vector<std::string>>, axis_config, style);
        XPROPERTY(std::optional<std::string>, axis_config, tickBand);
        XPROPERTY(std::optional<string_none_type>, axis_config, tickColor); // Implement ConditionalAxisColor
        XPROPERTY(std::optional<double>, axis_config, tickCount); // Difference in Altair and Vega-Lite docs for it's type
        XPROPERTY(std::optional<std::vector<double>>, axis_config, tickDash); // Implement ConditionalAxisNumberArray
        XPROPERTY(std::optional<double>, axis_config, tickDashOffset); // Implement ConditionalAxisNumber, Present in Altair Docs, but not present in Vega-Lite Docs
        XPROPERTY(std::optional<bool>, axis_config, tickExtra);
        XPROPERTY(std::optional<double>, axis_config, tickOffset);
        XPROPERTY(std::optional<double>, axis_config, tickOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<bool>, axis_config, tickRound);
        XPROPERTY(std::optional<double>, axis_config, tickSize); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<double>, axis_config, tickWidth); // Implement ConditionalAxisNumber
        XPROPERTY(std::optional<bool>, axis_config, ticks);
        XPROPERTY(std::optional<string_vec_none_type>, axis_config, title);
        XPROPERTY(std::optional<std::string>, axis_config, titleAlign);
        XPROPERTY(std::optional<string_none_type>, axis_config, titleAnchor);
        XPROPERTY(std::optional<double>, axis_config, titleAngle);
        XPROPERTY(std::optional<std::string>, axis_config, titleBaseline);
        XPROPERTY(std::optional<string_none_type>, axis_config, titleColor);
        XPROPERTY(std::optional<std::string>, axis_config, titleFont);
        XPROPERTY(std::optional<double>, axis_config, titleFontSize);
        XPROPERTY(std::optional<std::string>, axis_config, titleFontStyle);
        XPROPERTY(std::optional<string_num_type>, axis_config, titleFontWeight);
        XPROPERTY(std::optional<double>, axis_config, titleLimit);
        XPROPERTY(std::optional<double>, axis_config, titleLineHeight);
        XPROPERTY(std::optional<double>, axis_config, titleOpacity);
        XPROPERTY(std::optional<double>, axis_config, titlePadding);
        XPROPERTY(std::optional<double>, axis_config, titleX);
        XPROPERTY(std::optional<double>, axis_config, titleY);
        XPROPERTY(std::optional<double>, axis_config, translate);
    };

    XVEGA_API void to_json(nl::json& j, const axis_config& data);
}

#endif
