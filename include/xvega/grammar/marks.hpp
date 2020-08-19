// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARKS
#define XVEGA_MARKS

#include "xproperty/xobserved.hpp"
#include "../utils/xeither.hpp"
#include "../utils/custom_datatypes.hpp"

namespace xv
{
    template<class D>
    struct Marks : public xp::xobserved<D>
    {
        // General Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, D, type, xtl::missing<std::string>(), XEITHER_OPTIONAL("arc", "bar", "circle", "square", "tick", "line", "area", "point", "geoshape", "rule", "text", "image"));
        XPROPERTY(xtl::xoptional<bool>, D, aria);
        XPROPERTY(xtl::xoptional<std::string>, D, description);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, D, style);
        XPROPERTY(xtl::xoptional<tooltipType>, D, tooltip);
        XPROPERTY(xtl::xoptional<bool>, D, clip);
        XPROPERTY(xtl::xoptional<stringNoneType>, D, invalid);
        XPROPERTY(xtl::xoptional<boolNoneType>, D, order);

        // Position and Offset Properties
        XPROPERTY(xtl::xoptional<stringNumType>, D, x);
        XPROPERTY(xtl::xoptional<stringNumType>, D, x2);
        XPROPERTY(xtl::xoptional<double>, D, width);
        XPROPERTY(xtl::xoptional<double>, D, height);
        XPROPERTY(xtl::xoptional<stringNumType>, D, y);
        XPROPERTY(xtl::xoptional<stringNumType>, D, y2);
        XPROPERTY(xtl::xoptional<double>, D, xOffset);
        XPROPERTY(xtl::xoptional<double>, D, x2Offset);
        XPROPERTY(xtl::xoptional<double>, D, yOffset);
        XPROPERTY(xtl::xoptional<double>, D, y2Offset);

        // Color Properties
        XPROPERTY(xtl::xoptional<bool>, D, filled);
        XPROPERTY(xtl::xoptional<colorType>, D, color);
        XPROPERTY(xtl::xoptional<colorNoneType>, D, fill);
        XPROPERTY(xtl::xoptional<colorNoneType>, D, stroke);
        XPROPERTY(xtl::xoptional<std::string>, D, blend, xtl::missing<std::string>(), XEITHER_OPTIONAL("multiply", "screen", "overlay", "darken", "lighten", "color-dodge", "color-burn", "hard-light", "soft-light", "difference", "exclusion", "hue", "saturation", "color", "luminosity"));
        XPROPERTY(xtl::xoptional<double>, D, opacity);
        XPROPERTY(xtl::xoptional<double>, D, fillOpacity);
        XPROPERTY(xtl::xoptional<double>, D, strokeOpacity);
        XPROPERTY(xtl::xoptional<std::string>, D, strokeCap, xtl::missing<std::string>(), XEITHER_OPTIONAL("butt", "round", "square"));
        XPROPERTY(xtl::xoptional<std::vector<double>>, D, strokeDash);
        XPROPERTY(xtl::xoptional<double>, D, strokeDashOffset);
        XPROPERTY(xtl::xoptional<std::string>, D, strokeJoin, xtl::missing<std::string>(), XEITHER_OPTIONAL("miter", "round", "bevel"));
        XPROPERTY(xtl::xoptional<double>, D, strokeMiterLimit);
        XPROPERTY(xtl::xoptional<double>, D, strokeWidth);

        // Hyperlink Properties
        XPROPERTY(xtl::xoptional<std::string>, D, href);
        XPROPERTY(xtl::xoptional<std::string>, D, cursor, xtl::missing<std::string>(), XEITHER_OPTIONAL("auto", "default", "none", "context-menu", "help", "pointer", "progress", "wait", "cell", "crosshair", "text", "vertical-text", "alias", "copy", "move", "no-drop", "not-allowed", "e-resize", "n-resize", "ne-resize", "nw-resize", "s-resize", "se-resize", "sw-resize", "w-resize", "ew-resize", "ns-resize", "nesw-resize", "nwse-resize", "col-resize", "row-resize", "all-scroll", "zoom-in", "zoom-out", "grab", "grabbing"));
    
        void to_json(nl::json& j) const
        {
            // Fill in General Mark Properties
            if(type().has_value())
            {
                j["type"] = type().value();
            }
            if(aria().has_value())
            {
                j["aria"] = aria().value();
            }
            if(description().has_value())
            {
                j["description"] = description().value();
            }
            if(style().has_value())
            {
                j["style"] = style().value();
            }
            if(tooltip().has_value())
            {
                j["tooltip"] = tooltip().value();
            }
            if(clip().has_value())
            {
                j["clip"] = clip().value();
            }
            if(invalid().has_value())
            {
                j["invalid"] = invalid().value();
            }
            if(order().has_value())
            {
                j["order"] = order().value();
            }

            // Fill in Position and Offset Properties
            if(x().has_value())
            {
                j["x"] = x().value();
            }
            if(x2().has_value())
            {
                j["x2"] = x2().value();
            }
            if(width().has_value())
            {
                j["width"] = width().value();
            }
            if(height().has_value())
            {
                j["height"] = height().value();
            }
            if(y().has_value())
            {
                j["y"] = y().value();
            }
            if(y2().has_value())
            {
                j["y2"] = y2().value();
            }
            if(xOffset().has_value())
            {
                j["xOffset"] = xOffset().value();
            }
            if(x2Offset().has_value())
            {
                j["x2Offset"] = x2Offset().value();
            }
            if(yOffset().has_value())
            {
                j["yOffset"] = yOffset().value();
            }
            if(y2Offset().has_value())
            {
                j["y2Offset"] = y2Offset().value();
            }

            // Fill in Color Properties
            if(filled().has_value())
            {
                j["filled"] = filled().value();
            }
            if(color().has_value())
            {
                j["color"] = color().value();
            }
            if(fill().has_value())
            {
                j["fill"] = fill().value();
            }
            if(stroke().has_value())
            {
                j["stroke"] = stroke().value();
            }
            if(blend().has_value())
            {
                j["blend"] = blend().value();
            }
            if(opacity().has_value())
            {
                j["opacity"] = opacity().value();
            }
            if(fillOpacity().has_value())
            {
                j["fillOpacity"] = fillOpacity().value();
            }
            if(strokeOpacity().has_value())
            {
                j["strokeOpacity"] = strokeOpacity().value();
            }
            if(strokeCap().has_value())
            {
                j["strokeCap"] = strokeCap().value();
            }
            if(strokeDash().has_value())
            {
                j["strokeDash"] = strokeDash().value();
            }
            if(strokeDashOffset().has_value())
            {
                j["strokeDashOffset"] = strokeDashOffset().value();
            }
            if(strokeJoin().has_value())
            {
                j["strokeJoin"] = strokeJoin().value();
            }
            if(strokeMiterLimit().has_value())
            {
                j["strokeMiterLimit"] = strokeMiterLimit().value();
            }
            if(strokeWidth().has_value())
            {
                j["strokeWidth"] = strokeWidth().value();
            }

            // Fill in Hyperlink Properties
            if(href().has_value())
            {
                j["href"] = href().value();
            }
            if(cursor().has_value())
            {
                j["cursor"] = cursor().value();
            }
        }
    };

    template<class D>
    void to_json(nl::json& j, const Marks<D>& data)
    {
        data.derived_cast().to_json(j);
    }
}

#endif
