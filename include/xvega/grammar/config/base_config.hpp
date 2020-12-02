// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BASE_CONFIG_HPP
#define XVEGA_BASE_CONFIG_HPP

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    template<class D>
    struct base_config : public xp::xobserved<D>
    {
        XPROPERTY(xtl::xoptional<std::string>, D, align);
        XPROPERTY(xtl::xoptional<double>, D, angle);
        XPROPERTY(xtl::xoptional<bool>, D, aspect);
        XPROPERTY(xtl::xoptional<std::string>, D, baseline);
        XPROPERTY(xtl::xoptional<std::string>, D, blend);
        XPROPERTY(xtl::xoptional<color_type>, D, color);
        XPROPERTY(xtl::xoptional<double>, D, cornerRadius);
        XPROPERTY(xtl::xoptional<double>, D, cornerRadiusBottomLeft);
        XPROPERTY(xtl::xoptional<double>, D, cornerRadiusBottomRight);
        XPROPERTY(xtl::xoptional<double>, D, cornerRadiusTopLeft);
        XPROPERTY(xtl::xoptional<double>, D, cornerRadiusTopRight);
        XPROPERTY(xtl::xoptional<std::string>, D, cursor);
        XPROPERTY(xtl::xoptional<std::string>, D, dir);
        XPROPERTY(xtl::xoptional<double>, D, dx);
        XPROPERTY(xtl::xoptional<double>, D, dy);
        XPROPERTY(xtl::xoptional<std::string>, D, ellipsis);
        XPROPERTY(xtl::xoptional<color_none_type>, D, fill);
        XPROPERTY(xtl::xoptional<double>, D, fillOpacity);
        XPROPERTY(xtl::xoptional<bool>, D, filled);
        XPROPERTY(xtl::xoptional<std::string>, D, font);
        XPROPERTY(xtl::xoptional<double>, D, fontSize);
        XPROPERTY(xtl::xoptional<std::string>, D, fontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, D, fontWeight);
        XPROPERTY(xtl::xoptional<double>, D, height);
        XPROPERTY(xtl::xoptional<std::string>, D, href);
        XPROPERTY(xtl::xoptional<std::string>, D, interpolate);
        XPROPERTY(xtl::xoptional<string_none_type>, D, invalid);
        XPROPERTY(xtl::xoptional<double>, D, limit);
        XPROPERTY(xtl::xoptional<std::string>, D, lineBreak);
        XPROPERTY(xtl::xoptional<double>, D, lineHeight);
        XPROPERTY(xtl::xoptional<double>, D, opacity);
        XPROPERTY(xtl::xoptional<bool_none_type>, D, order);
        XPROPERTY(xtl::xoptional<std::string>, D, orient);
        XPROPERTY(xtl::xoptional<double>, D, radius);
        XPROPERTY(xtl::xoptional<std::string>, D, shape);
        XPROPERTY(xtl::xoptional<double>, D, size);
        XPROPERTY(xtl::xoptional<color_none_type>, D, stroke);
        XPROPERTY(xtl::xoptional<std::string>, D, strokeCap);
        XPROPERTY(xtl::xoptional<std::vector<double>>, D, strokeDash);
        XPROPERTY(xtl::xoptional<double>, D, strokeDashOffset);
        XPROPERTY(xtl::xoptional<std::string>, D, strokeJoin);
        XPROPERTY(xtl::xoptional<double>, D, strokeMiterLimit);
        XPROPERTY(xtl::xoptional<double>, D, strokeOffset);
        XPROPERTY(xtl::xoptional<double>, D, strokeOpacity);
        XPROPERTY(xtl::xoptional<double>, D, strokeWidth);
        XPROPERTY(xtl::xoptional<double>, D, tension);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, D, text);
        XPROPERTY(xtl::xoptional<double>, D, theta);
        XPROPERTY(xtl::xoptional<double>, D, timeUnitBand);
        XPROPERTY(xtl::xoptional<double>, D, timeUnitBandPosition);
        XPROPERTY(xtl::xoptional<tooltip_type>, D, tooltip);
        XPROPERTY(xtl::xoptional<double>, D, width);
        XPROPERTY(xtl::xoptional<string_num_type>, D, x);
        XPROPERTY(xtl::xoptional<string_num_type>, D, x2);
        XPROPERTY(xtl::xoptional<string_num_type>, D, y);
        XPROPERTY(xtl::xoptional<string_num_type>, D, y2);
    };
}

#endif
