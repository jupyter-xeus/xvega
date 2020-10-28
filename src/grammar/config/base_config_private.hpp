#ifndef BASECONFIG_PRIVATE_HPP
#define BASECONFIG_PRIVATE_HPP

#include "xvega/grammar/config/base_config.hpp"

namespace xv
{
    template <class D>
    void private_to_json(const base_config<D>& c, nl::json& j)
    {
        // Fill in General base_config Properties
        serialize(j, c.align(), "align");
        serialize(j, c.angle(), "angle");
        serialize(j, c.aspect(), "aspect");
        serialize(j, c.baseline(), "baseline");
        serialize(j, c.blend(), "blend");
        serialize(j, c.color(), "color");
        serialize(j, c.cornerRadius(), "cornerRadius");
        serialize(j, c.cornerRadiusBottomLeft(), "cornerRadiusBottomLeft");
        serialize(j, c.cornerRadiusBottomRight(), "cornerRadiusBottomRight");
        serialize(j, c.cornerRadiusTopLeft(), "cornerRadiusTopLeft");
        serialize(j, c.cornerRadiusTopRight(), "cornerRadiusTopRight");
        serialize(j, c.cursor(), "cursor");
        serialize(j, c.dir(), "dir");
        serialize(j, c.dx(), "dx");
        serialize(j, c.dy(), "dy");
        serialize(j, c.ellipsis(), "ellipsis");
        serialize(j, c.fill(), "fill");
        serialize(j, c.fillOpacity(), "fillOpacity");
        serialize(j, c.filled(), "filled");
        serialize(j, c.font(), "font");
        serialize(j, c.fontSize(), "fontSize");
        serialize(j, c.fontStyle(), "fontStyle");
        serialize(j, c.fontWeight(), "fontWeight");
        serialize(j, c.height(), "height");
        serialize(j, c.href(), "href");
        serialize(j, c.interpolate(), "interpolate");
        serialize(j, c.invalid(), "invalid");
        serialize(j, c.limit(), "limit");
        serialize(j, c.lineBreak(), "lineBreak");
        serialize(j, c.lineHeight(), "lineHeight");
        serialize(j, c.opacity(), "opacity");
        serialize(j, c.order(), "order");
        serialize(j, c.orient(), "orient");
        serialize(j, c.radius(), "radius");
        serialize(j, c.shape(), "shape");
        serialize(j, c.size(), "size");
        serialize(j, c.stroke(), "stroke");
        serialize(j, c.strokeCap(), "strokeCap");
        serialize(j, c.strokeDash(), "strokeDash");
        serialize(j, c.strokeDashOffset(), "strokeDashOffset");
        serialize(j, c.strokeJoin(), "strokeJoin");
        serialize(j, c.strokeMiterLimit(), "strokeMiterLimit");
        serialize(j, c.strokeOffset(), "strokeOffset");
        serialize(j, c.strokeOpacity(), "strokeOpacity");
        serialize(j, c.strokeWidth(), "strokeWidth");
        serialize(j, c.tension(), "tension");
        serialize(j, c.text(), "text");
        serialize(j, c.theta(), "theta");
        serialize(j, c.timeUnitBand(), "timeUnitBand");
        serialize(j, c.timeUnitBandPosition(), "timeUnitBandPosition");
        serialize(j, c.tooltip(), "tooltip");
        serialize(j, c.width(), "width");
        serialize(j, c.x(), "x");
        serialize(j, c.x2(), "x2");
        serialize(j, c.y(), "y");
        serialize(j, c.y2(), "y2");
    }
}
#endif
