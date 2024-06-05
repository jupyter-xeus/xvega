// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BASE_CONFIG_HPP
#define XVEGA_BASE_CONFIG_HPP

#include <optional>

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    template<class D>
    struct base_config : public xp::xobserved<D>
    {
        XPROPERTY(std::optional<std::string>, D, align);
        XPROPERTY(std::optional<double>, D, angle);
        XPROPERTY(std::optional<bool>, D, aspect);
        XPROPERTY(std::optional<std::string>, D, baseline);
        XPROPERTY(std::optional<std::string>, D, blend);
        XPROPERTY(std::optional<color_type>, D, color);
        XPROPERTY(std::optional<double>, D, cornerRadius);
        XPROPERTY(std::optional<double>, D, cornerRadiusBottomLeft);
        XPROPERTY(std::optional<double>, D, cornerRadiusBottomRight);
        XPROPERTY(std::optional<double>, D, cornerRadiusTopLeft);
        XPROPERTY(std::optional<double>, D, cornerRadiusTopRight);
        XPROPERTY(std::optional<std::string>, D, cursor);
        XPROPERTY(std::optional<std::string>, D, dir);
        XPROPERTY(std::optional<double>, D, dx);
        XPROPERTY(std::optional<double>, D, dy);
        XPROPERTY(std::optional<std::string>, D, ellipsis);
        XPROPERTY(std::optional<color_none_type>, D, fill);
        XPROPERTY(std::optional<double>, D, fillOpacity);
        XPROPERTY(std::optional<bool>, D, filled);
        XPROPERTY(std::optional<std::string>, D, font);
        XPROPERTY(std::optional<double>, D, fontSize);
        XPROPERTY(std::optional<std::string>, D, fontStyle);
        XPROPERTY(std::optional<string_num_type>, D, fontWeight);
        XPROPERTY(std::optional<double>, D, height);
        XPROPERTY(std::optional<std::string>, D, href);
        XPROPERTY(std::optional<std::string>, D, interpolate);
        XPROPERTY(std::optional<string_none_type>, D, invalid);
        XPROPERTY(std::optional<double>, D, limit);
        XPROPERTY(std::optional<std::string>, D, lineBreak);
        XPROPERTY(std::optional<double>, D, lineHeight);
        XPROPERTY(std::optional<double>, D, opacity);
        XPROPERTY(std::optional<bool_none_type>, D, order);
        XPROPERTY(std::optional<std::string>, D, orient);
        XPROPERTY(std::optional<double>, D, radius);
        XPROPERTY(std::optional<std::string>, D, shape);
        XPROPERTY(std::optional<double>, D, size);
        XPROPERTY(std::optional<color_none_type>, D, stroke);
        XPROPERTY(std::optional<std::string>, D, strokeCap);
        XPROPERTY(std::optional<std::vector<double>>, D, strokeDash);
        XPROPERTY(std::optional<double>, D, strokeDashOffset);
        XPROPERTY(std::optional<std::string>, D, strokeJoin);
        XPROPERTY(std::optional<double>, D, strokeMiterLimit);
        XPROPERTY(std::optional<double>, D, strokeOffset);
        XPROPERTY(std::optional<double>, D, strokeOpacity);
        XPROPERTY(std::optional<double>, D, strokeWidth);
        XPROPERTY(std::optional<double>, D, tension);
        XPROPERTY(std::optional<std::vector<std::string>>, D, text);
        XPROPERTY(std::optional<double>, D, theta);
        XPROPERTY(std::optional<double>, D, timeUnitBand);
        XPROPERTY(std::optional<double>, D, timeUnitBandPosition);
        XPROPERTY(std::optional<tooltip_type>, D, tooltip);
        XPROPERTY(std::optional<double>, D, width);
        XPROPERTY(std::optional<string_num_type>, D, x);
        XPROPERTY(std::optional<string_num_type>, D, x2);
        XPROPERTY(std::optional<string_num_type>, D, y);
        XPROPERTY(std::optional<string_num_type>, D, y2);
    };
}

#endif
