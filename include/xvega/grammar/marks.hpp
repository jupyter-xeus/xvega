#include "xproperty/xobserved.hpp"
#include "../utils/xeither.hpp"
#include "../utils/custom_datatypes.hpp"

struct Marks : public xp::xobserved<Marks>
{
    // General Mark Properties
    XPROPERTY(xtl::xoptional<std::string>, Marks, type, xtl::missing<std::string>(), XEITHER_OPTIONAL("arc", "bar", "circle", "square", "tick", "line", "area", "point", "geoshape", "rule", "text", "image"));
    XPROPERTY(xtl::xoptional<bool>, Marks, aria);
    XPROPERTY(xtl::xoptional<std::string>, Marks, description);
    XPROPERTY(xtl::xoptional<std::vector<std::string>>, Marks, style);
    XPROPERTY(xtl::xoptional<tooltipType>, Marks, tooltip);
    XPROPERTY(xtl::xoptional<bool>, Marks, clip);
    XPROPERTY(xtl::xoptional<stringNoneType>, Marks, invalid);
    XPROPERTY(xtl::xoptional<boolNoneType>, Marks, order);

    // Position and Offset Properties
    XPROPERTY(xtl::xoptional<stringNumType>, Marks, x);
    XPROPERTY(xtl::xoptional<stringNumType>, Marks, x2);
    XPROPERTY(xtl::xoptional<double>, Marks, width);
    XPROPERTY(xtl::xoptional<double>, Marks, height);
    XPROPERTY(xtl::xoptional<stringNumType>, Marks, y);
    XPROPERTY(xtl::xoptional<stringNumType>, Marks, y2);
    XPROPERTY(xtl::xoptional<double>, Marks, xOffset);
    XPROPERTY(xtl::xoptional<double>, Marks, x2Offset);
    XPROPERTY(xtl::xoptional<double>, Marks, yOffset);
    XPROPERTY(xtl::xoptional<double>, Marks, y2Offset);

    // Color Properties
    XPROPERTY(xtl::xoptional<bool>, Marks, filled);
    XPROPERTY(xtl::xoptional<colorType>, Marks, color);
    XPROPERTY(xtl::xoptional<colorNoneType>, Marks, fill);
    XPROPERTY(xtl::xoptional<colorNoneType>, Marks, stroke);
    XPROPERTY(xtl::xoptional<std::string>, Marks, blend, xtl::missing<std::string>(), XEITHER_OPTIONAL("multiply", "screen", "overlay", "darken", "lighten", "color-dodge", "color-burn", "hard-light", "soft-light", "difference", "exclusion", "hue", "saturation", "color", "luminosity"));
    XPROPERTY(xtl::xoptional<double>, Marks, opacity);
    XPROPERTY(xtl::xoptional<double>, Marks, fillOpacity);
    XPROPERTY(xtl::xoptional<double>, Marks, strokeOpacity);
    XPROPERTY(xtl::xoptional<std::string>, Marks, strokeCap, xtl::missing<std::string>(), XEITHER_OPTIONAL("butt", "round", "square"));
    XPROPERTY(xtl::xoptional<std::vector<double>>, Marks, strokeDash);
    XPROPERTY(xtl::xoptional<double>, Marks, strokeDashOffset);
    XPROPERTY(xtl::xoptional<std::string>, Marks, strokeJoin, xtl::missing<std::string>(), XEITHER_OPTIONAL("miter", "round", "bevel"));
    XPROPERTY(xtl::xoptional<double>, Marks, strokeMiterLimit);
    XPROPERTY(xtl::xoptional<double>, Marks, strokeWidth);

    // Hyperlink Properties
    XPROPERTY(xtl::xoptional<std::string>, Marks, href);
    XPROPERTY(xtl::xoptional<std::string>, Marks, cursor, xtl::missing<std::string>(), XEITHER_OPTIONAL("auto", "default", "none", "context-menu", "help", "pointer", "progress", "wait", "cell", "crosshair", "text", "vertical-text", "alias", "copy", "move", "no-drop", "not-allowed", "e-resize", "n-resize", "ne-resize", "nw-resize", "s-resize", "se-resize", "sw-resize", "w-resize", "ew-resize", "ns-resize", "nesw-resize", "nwse-resize", "col-resize", "row-resize", "all-scroll", "zoom-in", "zoom-out", "grab", "grabbing"));

    // Arc Mark Properties
    XPROPERTY(xtl::xoptional<double>, Marks, radius);
    XPROPERTY(xtl::xoptional<double>, Marks, radius2);
    XPROPERTY(xtl::xoptional<double>, Marks, innerRadius);
    XPROPERTY(xtl::xoptional<double>, Marks, outerRadius);
    XPROPERTY(xtl::xoptional<double>, Marks, theta);
    XPROPERTY(xtl::xoptional<double>, Marks, theta2);
    XPROPERTY(xtl::xoptional<double>, Marks, cornerRadius);
    XPROPERTY(xtl::xoptional<double>, Marks, padAngle);
    XPROPERTY(xtl::xoptional<double>, Marks, radiusOffset);
    XPROPERTY(xtl::xoptional<double>, Marks, radius2Offset);
    XPROPERTY(xtl::xoptional<double>, Marks, thetaOffset);
    XPROPERTY(xtl::xoptional<double>, Marks, theta2Offset);

    // Area Mark Properties
    XPROPERTY(xtl::xoptional<std::string>, Marks, align, xtl::missing<std::string>(), XEITHER_OPTIONAL("left", "right", "center"));
    XPROPERTY(xtl::xoptional<std::string>, Marks, baseline, xtl::missing<std::string>(), XEITHER_OPTIONAL("alphabetic", "top", "middle", "bottom", "line-top", "line-bottom"));
    XPROPERTY(xtl::xoptional<std::string>, Marks, orient, xtl::missing<std::string>(), XEITHER_OPTIONAL("horizontal", "vertical"));
    XPROPERTY(xtl::xoptional<std::string>, Marks, interpolate, xtl::missing<std::string>(), XEITHER_OPTIONAL("basis", "basis-open", "basis-closed", "bundle", "cardinal", "cardinal-open", "cardinal-closed", "catmull-rom", "linear", "linear-closed", "monotone", "natural", "step", "step-before", "step-after"));
    XPROPERTY(xtl::xoptional<double>, Marks, tension);
    XPROPERTY(xtl::xoptional<boolObjectType>, Marks, line);
    XPROPERTY(xtl::xoptional<boolStringObjectType>, Marks, point);

    // Bar Mark Properties
    // XPROPERTY(xtl::xoptional<std::string>, Marks, orient, xtl::missing<std::string>(), XEITHER_OPTIONAL("horizontal", "vertical"));
    // XPROPERTY(xtl::xoptional<std::string>, Marks, align, xtl::missing<std::string>(), XEITHER_OPTIONAL("left", "right", "center"));
    // XPROPERTY(xtl::xoptional<std::string>, Marks, baseline, xtl::missing<std::string>(), XEITHER_OPTIONAL("alphabetic", "top", "middle", "bottom", "line-top", "line-bottom"));
    XPROPERTY(xtl::xoptional<double>, Marks, binSpacing);
    // XPROPERTY(xtl::xoptional<double>, Marks, cornerRadius);
    XPROPERTY(xtl::xoptional<double>, Marks, cornerRadiusEnd);
    XPROPERTY(xtl::xoptional<double>, Marks, cornerRadiusTopLeft);
    XPROPERTY(xtl::xoptional<double>, Marks, cornerRadiusTopRight);
    XPROPERTY(xtl::xoptional<double>, Marks, cornerRadiusBottomRight);
    XPROPERTY(xtl::xoptional<double>, Marks, cornerRadiusBottomLeft);

    // Circle Mark Properties
    XPROPERTY(xtl::xoptional<double>, Marks, size);

    // Geoshape Mark Properties
    // ----

    // Image Mark Properties
    XPROPERTY(xtl::xoptional<anyType>, Marks, url);
    XPROPERTY(xtl::xoptional<bool>, Marks, aspect);
    // XPROPERTY(xtl::xoptional<std::string>, Marks, align, xtl::missing<std::string>(), XEITHER_OPTIONAL("left", "right", "center"));
    // XPROPERTY(xtl::xoptional<std::string>, Marks, baseline, xtl::missing<std::string>(), XEITHER_OPTIONAL("alphabetic", "top", "middle", "bottom", "line-top", "line-bottom"));
    
    // Line Mark Properties
    // XPROPERTY(xtl::xoptional<std::string>, Marks, orient, xtl::missing<std::string>(), XEITHER_OPTIONAL("horizontal", "vertical"));
    // XPROPERTY(xtl::xoptional<std::string>, Marks, interpolate, xtl::missing<std::string>(), XEITHER_OPTIONAL("basis", "basis-open", "basis-closed", "bundle", "cardinal", "cardinal-open", "cardinal-closed", "catmull-rom", "linear", "linear-closed", "monotone", "natural", "step", "step-before", "step-after"));
    // XPROPERTY(xtl::xoptional<double>, Marks, tension);
    // XPROPERTY(xtl::xoptional<boolStringObjectType>, Marks, point);

    // Point Mark Properties
    XPROPERTY(xtl::xoptional<std::string>, Marks, shape);
    // XPROPERTY(xtl::xoptional<double>, Marks, size);

    // Rect Mark Properties
    // XPROPERTY(xtl::xoptional<std::string>, Marks, align, xtl::missing<std::string>(), XEITHER_OPTIONAL("left", "right", "center"));
    // XPROPERTY(xtl::xoptional<std::string>, Marks, baseline, xtl::missing<std::string>(), XEITHER_OPTIONAL("alphabetic", "top", "middle", "bottom", "line-top", "line-bottom"));
    // XPROPERTY(xtl::xoptional<double>, Marks, cornerRadius);

    // Rule Mark Properties
    // ---

    // Square Mark Properties
    // XPROPERTY(xtl::xoptional<double>, Marks, size);

    // Text Mark Properties
    XPROPERTY(xtl::xoptional<double>, Marks, angle);
    // XPROPERTY(xtl::xoptional<std::string>, Marks, align, xtl::missing<std::string>(), XEITHER_OPTIONAL("left", "right", "center"));
    // XPROPERTY(xtl::xoptional<std::string>, Marks, baseline, xtl::missing<std::string>(), XEITHER_OPTIONAL("alphabetic", "top", "middle", "bottom", "line-top", "line-bottom"));
    XPROPERTY(xtl::xoptional<std::string>, Marks, dir, xtl::missing<std::string>(), XEITHER_OPTIONAL("ltr", "rtl"));
    XPROPERTY(xtl::xoptional<double>, Marks, dx);
    XPROPERTY(xtl::xoptional<double>, Marks, dy);
    XPROPERTY(xtl::xoptional<std::string>, Marks, ellipsis);
    XPROPERTY(xtl::xoptional<std::string>, Marks, font);
    XPROPERTY(xtl::xoptional<double>, Marks, fontSize);
    XPROPERTY(xtl::xoptional<std::string>, Marks, fontStyle);
    XPROPERTY(xtl::xoptional<stringNumType>, Marks, fontWeight);
    XPROPERTY(xtl::xoptional<double>, Marks, limit);
    XPROPERTY(xtl::xoptional<double>, Marks, lineHeight);
    // XPROPERTY(xtl::xoptional<double>, Marks, radius);
    XPROPERTY(xtl::xoptional<std::vector<std::string>>, Marks, text);
    // XPROPERTY(xtl::xoptional<double>, Marks, theta);

    // Tick Mark Properties
    // XPROPERTY(xtl::xoptional<double>, Marks, cornerRadius);
    // XPROPERTY(xtl::xoptional<std::string>, Marks, orient, xtl::missing<std::string>(), XEITHER_OPTIONAL("horizontal", "vertical"));
    
    // Trail Mark Properties
    // XPROPERTY(xtl::xoptional<std::string>, Marks, orient, xtl::missing<std::string>(), XEITHER_OPTIONAL("horizontal", "vertical"));
};