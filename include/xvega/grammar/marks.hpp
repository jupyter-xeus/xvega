// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARKS_HPP
#define XVEGA_MARKS_HPP

#include <optional>
#include <variant>

#include "xproperty/xobserved.hpp"

#include "../xvega_config.hpp"
#include "../utils/custom_datatypes.hpp"

namespace xv
{
    template<class D>
    struct mark : public xp::xobserved<D>
    {
        // General Mark Properties
        XPROPERTY(std::optional<std::string>, D, type);
        XPROPERTY(std::optional<bool>, D, aria);
        XPROPERTY(std::optional<std::string>, D, description);
        XPROPERTY(std::optional<std::vector<std::string>>, D, style);
        XPROPERTY(std::optional<tooltip_type>, D, tooltip);
        XPROPERTY(std::optional<bool>, D, clip);
        XPROPERTY(std::optional<string_none_type>, D, invalid);
        XPROPERTY(std::optional<bool_none_type>, D, order);

        // Position and Offset Properties
        XPROPERTY(std::optional<string_num_type>, D, x);
        XPROPERTY(std::optional<string_num_type>, D, x2);
        XPROPERTY(std::optional<double>, D, width);
        XPROPERTY(std::optional<double>, D, height);
        XPROPERTY(std::optional<string_num_type>, D, y);
        XPROPERTY(std::optional<string_num_type>, D, y2);
        XPROPERTY(std::optional<double>, D, xOffset);
        XPROPERTY(std::optional<double>, D, x2Offset);
        XPROPERTY(std::optional<double>, D, yOffset);
        XPROPERTY(std::optional<double>, D, y2Offset);

        // Color Properties
        XPROPERTY(std::optional<bool>, D, filled);
        XPROPERTY(std::optional<color_type>, D, color);
        XPROPERTY(std::optional<color_none_type>, D, fill);
        XPROPERTY(std::optional<color_none_type>, D, stroke);
        XPROPERTY(std::optional<std::string>, D, blend);
        XPROPERTY(std::optional<double>, D, opacity);
        XPROPERTY(std::optional<double>, D, fillOpacity);
        XPROPERTY(std::optional<double>, D, strokeOpacity);
        XPROPERTY(std::optional<std::string>, D, strokeCap);
        XPROPERTY(std::optional<std::vector<double>>, D, strokeDash);
        XPROPERTY(std::optional<double>, D, strokeDashOffset);
        XPROPERTY(std::optional<std::string>, D, strokeJoin);
        XPROPERTY(std::optional<double>, D, strokeMiterLimit);
        XPROPERTY(std::optional<double>, D, strokeWidth);

        // Hyperlink Properties
        XPROPERTY(std::optional<std::string>, D, href);
        XPROPERTY(std::optional<std::string>, D, cursor);

        inline std::string name() const { return ""; }
    };
}

#endif
