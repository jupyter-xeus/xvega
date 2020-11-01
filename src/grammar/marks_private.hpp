#ifndef MARKS_PRIVATE_HPP
#define MARKS_PRIVATE_HPP

#include "xvega/grammar/marks.hpp"
#include "../utils/serialize.hpp"

namespace xv
{
    template <class D>
    void private_to_json(const mark<D>& c, nl::json& j)
    {
        // Fill in General Mark Properties
        serialize(j, c.type(), "type");
        serialize(j, c.aria(), "aria");
        serialize(j, c.description(), "description");
        serialize(j, c.style(), "style");
        serialize(j, c.tooltip(), "tooltip");
        serialize(j, c.clip(), "clip");
        serialize(j, c.invalid(), "invalid");
        serialize(j, c.order(), "order");

        // Fill in Position and Offset Properties
        serialize(j, c.x(), "x");
        serialize(j, c.x2(), "x2");
        serialize(j, c.width(), "width");
        serialize(j, c.height(), "height");
        serialize(j, c.y(), "y");
        serialize(j, c.y2(), "y2");
        serialize(j, c.xOffset(), "xOffset");
        serialize(j, c.x2Offset(), "x2Offset");
        serialize(j, c.yOffset(), "yOffset");
        serialize(j, c.y2Offset(), "y2Offset");

        // Fill in Color Properties
        serialize(j, c.filled(), "filled");
        serialize(j, c.color(), "color");
        serialize(j, c.fill(), "fill");
        serialize(j, c.stroke(), "stroke");
        serialize(j, c.blend(), "blend");
        serialize(j, c.opacity(), "opacity");
        serialize(j, c.fillOpacity(), "fillOpacity");
        serialize(j, c.strokeOpacity(), "strokeOpacity");
        serialize(j, c.strokeCap(), "strokeCap");
        serialize(j, c.strokeDash(), "strokeDash");
        serialize(j, c.strokeDashOffset(), "strokeDashOffset");
        serialize(j, c.strokeJoin(), "strokeJoin");
        serialize(j, c.strokeMiterLimit(), "strokeMiterLimit");
        serialize(j, c.strokeWidth(), "strokeWidth");

        // Fill in Hyperlink Properties
        serialize(j, c.href(), "href");
        serialize(j, c.cursor(), "cursor");
    }
}
#endif
