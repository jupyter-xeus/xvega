// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_AXIS_CONFIG_HPP
#define XVEGA_AXIS_CONFIG_HPP

#include "../../xvega_config.hpp"
#include "xproperty/xobserved.hpp"
#include "../../utils/xeither.hpp"
#include "../../utils/custom_datatypes.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    using bool_num_type = xtl::variant<double, int, bool>;
    using bool_string_type = xtl::variant<std::string, bool>;
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;

    struct axis_config : public xp::xobserved<axis_config>
    {
        XPROPERTY(xtl::xoptional<double>, axis_config, bandPosition);
        XPROPERTY(xtl::xoptional<bool>, axis_config, disable);
        XPROPERTY(xtl::xoptional<bool>, axis_config, domain);
        XPROPERTY(xtl::xoptional<string_none_type>, axis_config, domainColor);
        XPROPERTY(xtl::xoptional<std::vector<double>>, axis_config, domainDash);
        XPROPERTY(xtl::xoptional<double>, axis_config, domainDashOffset);
        XPROPERTY(xtl::xoptional<double>, axis_config, domainOpacity);
        XPROPERTY(xtl::xoptional<double>, axis_config, domainWidth);
        XPROPERTY(xtl::xoptional<bool>, axis_config, grid);
        XPROPERTY(xtl::xoptional<string_none_type>, axis_config, gridColor); // Implement ConditionalAxisColor
        XPROPERTY(xtl::xoptional<std::vector<double>>, axis_config, gridDash); // Implement ConditionalAxisNumberArray
        XPROPERTY(xtl::xoptional<double>, axis_config, gridDashOffset); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<double>, axis_config, gridOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<double>, axis_config, gridWidth); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<std::string>, axis_config, labelAlign); // Implement ConditionalAxisLabelAlign
        XPROPERTY(xtl::xoptional<double>, axis_config, labelAngle);
        XPROPERTY(xtl::xoptional<std::string>, axis_config, labelBaseline); // Implement ConditionalAxisLabelBaseline
        XPROPERTY(xtl::xoptional<bool_num_type>, axis_config, labelBound);
        XPROPERTY(xtl::xoptional<string_none_type>, axis_config, labelColor); // Implement ConditionalAxisColor
        XPROPERTY(xtl::xoptional<std::string>, axis_config, labelExpr);
        XPROPERTY(xtl::xoptional<bool_num_type>, axis_config, labelFlush);
        XPROPERTY(xtl::xoptional<double>, axis_config, labelFlushOffset);
        XPROPERTY(xtl::xoptional<std::string>, axis_config, labelFont); // Implement ConditionalAxisString
        XPROPERTY(xtl::xoptional<double>, axis_config, labelFontSize); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<std::string>, axis_config, labelFontStyle); // Implement ConditionalAxisLabelFontStyle
        XPROPERTY(xtl::xoptional<string_num_type>, axis_config, labelFontWeight); // Implement ConditionalAxisLabelFontWeight
        XPROPERTY(xtl::xoptional<double>, axis_config, labelLimit);
        XPROPERTY(xtl::xoptional<double>, axis_config, labelLineHeight);
        XPROPERTY(xtl::xoptional<double>, axis_config, labelOffset); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<double>, axis_config, labelOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<bool_string_type>, axis_config, labelOverlap);
        XPROPERTY(xtl::xoptional<double>, axis_config, labelPadding); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<double>, axis_config, labelSeparation);
        XPROPERTY(xtl::xoptional<bool>, axis_config, labels);
        XPROPERTY(xtl::xoptional<double>, axis_config, maxExtent);
        XPROPERTY(xtl::xoptional<double>, axis_config, minExtent);
        XPROPERTY(xtl::xoptional<std::string>, axis_config, orient);
        XPROPERTY(xtl::xoptional<double>, axis_config, offset);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, axis_config, style);
        XPROPERTY(xtl::xoptional<std::string>, axis_config, tickBand);
        XPROPERTY(xtl::xoptional<string_none_type>, axis_config, tickColor); // Implement ConditionalAxisColor
        XPROPERTY(xtl::xoptional<double>, axis_config, tickCount); // Difference in Altair and Vega-Lite docs for it's type
        XPROPERTY(xtl::xoptional<std::vector<double>>, axis_config, tickDash); // Implement ConditionalAxisNumberArray
        XPROPERTY(xtl::xoptional<double>, axis_config, tickDashOffset); // Implement ConditionalAxisNumber, Present in Altair Docs, but not present in Vega-Lite Docs
        XPROPERTY(xtl::xoptional<bool>, axis_config, tickExtra);
        XPROPERTY(xtl::xoptional<double>, axis_config, tickOffset);
        XPROPERTY(xtl::xoptional<double>, axis_config, tickOpacity); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<bool>, axis_config, tickRound);
        XPROPERTY(xtl::xoptional<double>, axis_config, tickSize); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<double>, axis_config, tickWidth); // Implement ConditionalAxisNumber
        XPROPERTY(xtl::xoptional<bool>, axis_config, ticks);
        XPROPERTY(xtl::xoptional<string_vec_none_type>, axis_config, title);
        XPROPERTY(xtl::xoptional<std::string>, axis_config, titleAlign);
        XPROPERTY(xtl::xoptional<string_none_type>, axis_config, titleAnchor);
        XPROPERTY(xtl::xoptional<double>, axis_config, titleAngle);
        XPROPERTY(xtl::xoptional<std::string>, axis_config, titleBaseline);
        XPROPERTY(xtl::xoptional<string_none_type>, axis_config, titleColor);
        XPROPERTY(xtl::xoptional<std::string>, axis_config, titleFont);
        XPROPERTY(xtl::xoptional<double>, axis_config, titleFontSize);
        XPROPERTY(xtl::xoptional<std::string>, axis_config, titleFontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, axis_config, titleFontWeight);
        XPROPERTY(xtl::xoptional<double>, axis_config, titleLimit);
        XPROPERTY(xtl::xoptional<double>, axis_config, titleLineHeight);
        XPROPERTY(xtl::xoptional<double>, axis_config, titleOpacity);
        XPROPERTY(xtl::xoptional<double>, axis_config, titlePadding);
        XPROPERTY(xtl::xoptional<double>, axis_config, titleX);
        XPROPERTY(xtl::xoptional<double>, axis_config, titleY);
        XPROPERTY(xtl::xoptional<double>, axis_config, translate);
    };

    void to_json(nl::json& j, const axis_config& data);
}

#endif
