// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARKS_HPP
#define XVEGA_MARKS_HPP

#include "xproperty/xobserved.hpp"

#include "../xvega_config.hpp"
#include "../utils/custom_datatypes.hpp"

namespace xv
{
    template<class D>
    struct mark : public xp::xobserved<D>
    {
        // General Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, D, type);
        XPROPERTY(xtl::xoptional<bool>, D, aria);
        XPROPERTY(xtl::xoptional<std::string>, D, description);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, D, style);
        XPROPERTY(xtl::xoptional<tooltip_type>, D, tooltip);
        XPROPERTY(xtl::xoptional<bool>, D, clip);
        XPROPERTY(xtl::xoptional<string_none_type>, D, invalid);
        XPROPERTY(xtl::xoptional<bool_none_type>, D, order);

        // Position and Offset Properties
        XPROPERTY(xtl::xoptional<string_num_type>, D, x);
        XPROPERTY(xtl::xoptional<string_num_type>, D, x2);
        XPROPERTY(xtl::xoptional<double>, D, width);
        XPROPERTY(xtl::xoptional<double>, D, height);
        XPROPERTY(xtl::xoptional<string_num_type>, D, y);
        XPROPERTY(xtl::xoptional<string_num_type>, D, y2);
        XPROPERTY(xtl::xoptional<double>, D, xOffset);
        XPROPERTY(xtl::xoptional<double>, D, x2Offset);
        XPROPERTY(xtl::xoptional<double>, D, yOffset);
        XPROPERTY(xtl::xoptional<double>, D, y2Offset);

        // Color Properties
        XPROPERTY(xtl::xoptional<bool>, D, filled);
        XPROPERTY(xtl::xoptional<color_type>, D, color);
        XPROPERTY(xtl::xoptional<color_none_type>, D, fill);
        XPROPERTY(xtl::xoptional<color_none_type>, D, stroke);
        XPROPERTY(xtl::xoptional<std::string>, D, blend);
        XPROPERTY(xtl::xoptional<double>, D, opacity);
        XPROPERTY(xtl::xoptional<double>, D, fillOpacity);
        XPROPERTY(xtl::xoptional<double>, D, strokeOpacity);
        XPROPERTY(xtl::xoptional<std::string>, D, strokeCap);
        XPROPERTY(xtl::xoptional<std::vector<double>>, D, strokeDash);
        XPROPERTY(xtl::xoptional<double>, D, strokeDashOffset);
        XPROPERTY(xtl::xoptional<std::string>, D, strokeJoin);
        XPROPERTY(xtl::xoptional<double>, D, strokeMiterLimit);
        XPROPERTY(xtl::xoptional<double>, D, strokeWidth);

        // Hyperlink Properties
        XPROPERTY(xtl::xoptional<std::string>, D, href);
        XPROPERTY(xtl::xoptional<std::string>, D, cursor);
    
        void to_json(nl::json& j) const
        {
            // Fill in General Mark Properties
            serialize(j, type(), "type");
            serialize(j, aria(), "aria");
            serialize(j, description(), "description");
            serialize(j, style(), "style");
            serialize(j, tooltip(), "tooltip");
            serialize(j, clip(), "clip");
            serialize(j, invalid(), "invalid");
            serialize(j, order(), "order");

            // Fill in Position and Offset Properties
            serialize(j, x(), "x");
            serialize(j, x2(), "x2");
            serialize(j, width(), "width");
            serialize(j, height(), "height");
            serialize(j, y(), "y");
            serialize(j, y2(), "y2");
            serialize(j, xOffset(), "xOffset");
            serialize(j, x2Offset(), "x2Offset");
            serialize(j, yOffset(), "yOffset");
            serialize(j, y2Offset(), "y2Offset");

            // Fill in Color Properties
            serialize(j, filled(), "filled");
            serialize(j, color(), "color");
            serialize(j, fill(), "fill");
            serialize(j, stroke(), "stroke");
            serialize(j, blend(), "blend");
            serialize(j, opacity(), "opacity");
            serialize(j, fillOpacity(), "fillOpacity");
            serialize(j, strokeOpacity(), "strokeOpacity");
            serialize(j, strokeCap(), "strokeCap");
            serialize(j, strokeDash(), "strokeDash");
            serialize(j, strokeDashOffset(), "strokeDashOffset");
            serialize(j, strokeJoin(), "strokeJoin");
            serialize(j, strokeMiterLimit(), "strokeMiterLimit");
            serialize(j, strokeWidth(), "strokeWidth");

            // Fill in Hyperlink Properties
            serialize(j, href(), "href");
            serialize(j, cursor(), "cursor");
        }

    protected:

        mark() = default;
        ~mark() = default;

        mark(const mark&) = default;
        mark& operator=(const mark&) = default;

        mark(mark&&) = default;
        mark& operator=(mark&&) = default;
        
    };

    template<class D>
    void to_json(nl::json& j, const mark<D>& data)
    {
        data.derived_cast().to_json(j);
    }
}

#endif
