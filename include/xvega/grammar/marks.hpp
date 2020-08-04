#include "xproperty/xobserved.hpp"
#include "../utils/xeither.hpp"
#include "../utils/custom_datatypes.hpp"

namespace xv
{
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

    void to_json(nl::json& j, const Marks& data)
    {
        // Fill in General Mark Properties
        if(data.type().has_value())
        {
            j["type"] = data.type().value();
        }
        if(data.aria().has_value())
        {
            j["aria"] = data.aria().value();
        }
        if(data.description().has_value())
        {
            j["description"] = data.description().value();
        }
        if(data.style().has_value())
        {
            j["style"] = data.style().value();
        }
        if(data.tooltip().has_value())
        {
            j["tooltip"] = data.tooltip().value();
        }
        if(data.clip().has_value())
        {
            j["clip"] = data.clip().value();
        }
        if(data.invalid().has_value())
        {
            j["invalid"] = data.invalid().value();
        }
        if(data.order().has_value())
        {
            j["order"] = data.order().value();
        }

        // Fill in Position and Offset Properties
        if(data.x().has_value())
        {
            j["x"] = data.x().value();
        }
        if(data.x2().has_value())
        {
            j["x2"] = data.x2().value();
        }
        if(data.width().has_value())
        {
            j["width"] = data.width().value();
        }
        if(data.height().has_value())
        {
            j["height"] = data.height().value();
        }
        if(data.y().has_value())
        {
            j["y"] = data.y().value();
        }
        if(data.y2().has_value())
        {
            j["y2"] = data.y2().value();
        }
        if(data.xOffset().has_value())
        {
            j["xOffset"] = data.xOffset().value();
        }
        if(data.x2Offset().has_value())
        {
            j["x2Offset"] = data.x2Offset().value();
        }
        if(data.yOffset().has_value())
        {
            j["yOffset"] = data.yOffset().value();
        }
        if(data.y2Offset().has_value())
        {
            j["y2Offset"] = data.y2Offset().value();
        }

        // Fill in Color Properties
        if(data.filled().has_value())
        {
            j["filled"] = data.filled().value();
        }
        if(data.color().has_value())
        {
            j["color"] = data.color().value();
        }
        if(data.fill().has_value())
        {
            j["fill"] = data.fill().value();
        }
        if(data.stroke().has_value())
        {
            j["stroke"] = data.stroke().value();
        }
        if(data.blend().has_value())
        {
            j["blend"] = data.blend().value();
        }
        if(data.opacity().has_value())
        {
            j["opacity"] = data.opacity().value();
        }
        if(data.fillOpacity().has_value())
        {
            j["fillOpacity"] = data.fillOpacity().value();
        }
        if(data.strokeOpacity().has_value())
        {
            j["strokeOpacity"] = data.strokeOpacity().value();
        }
        if(data.strokeCap().has_value())
        {
            j["strokeCap"] = data.strokeCap().value();
        }
        if(data.strokeDash().has_value())
        {
            j["strokeDash"] = data.strokeDash().value();
        }
        if(data.strokeDashOffset().has_value())
        {
            j["strokeDashOffset"] = data.strokeDashOffset().value();
        }
        if(data.strokeJoin().has_value())
        {
            j["strokeJoin"] = data.strokeJoin().value();
        }
        if(data.strokeMiterLimit().has_value())
        {
            j["strokeMiterLimit"] = data.strokeMiterLimit().value();
        }
        if(data.strokeWidth().has_value())
        {
            j["strokeWidth"] = data.strokeWidth().value();
        }

        // Fill in Hyperlink Properties
        if(data.href().has_value())
        {
            j["href"] = data.href().value();
        }
        if(data.cursor().has_value())
        {
            j["cursor"] = data.cursor().value();
        }

        // Fill in Arc Mark Properties
        if(data.radius().has_value())
        {
            j["radius"] = data.radius().value();
        }
        if(data.radius2().has_value())
        {
            j["radius2"] = data.radius2().value();
        }
        if(data.innerRadius().has_value())
        {
            j["innerRadius"] = data.innerRadius().value();
        }
        if(data.outerRadius().has_value())
        {
            j["outerRadius"] = data.outerRadius().value();
        }
        if(data.theta().has_value())
        {
            j["theta"] = data.theta().value();
        }
        if(data.theta2().has_value())
        {
            j["theta2"] = data.theta2().value();
        }
        if(data.cornerRadius().has_value())
        {
            j["cornerRadius"] = data.cornerRadius().value();
        }
        if(data.padAngle().has_value())
        {
            j["padAngle"] = data.padAngle().value();
        }
        if(data.radiusOffset().has_value())
        {
            j["radiusOffset"] = data.radiusOffset().value();
        }
        if(data.radius2Offset().has_value())
        {
            j["radius2Offset"] = data.radius2Offset().value();
        }
        if(data.thetaOffset().has_value())
        {
            j["thetaOffset"] = data.thetaOffset().value();
        }
        if(data.theta2Offset().has_value())
        {
            j["theta2Offset"] = data.theta2Offset().value();
        }

        // Fill in Area Mark Properties
        if(data.align().has_value())
        {
            j["align"] = data.align().value();
        }
        if(data.baseline().has_value())
        {
            j["baseline"] = data.baseline().value();
        }
        if(data.orient().has_value())
        {
            j["orient"] = data.orient().value();
        }
        if(data.interpolate().has_value())
        {
            j["interpolate"] = data.interpolate().value();
        }
        if(data.tension().has_value())
        {
            j["tension"] = data.tension().value();
        }
        if(data.line().has_value())
        {
            j["line"] = data.line().value();
        }
        if(data.point().has_value())
        {
            j["point"] = data.point().value();
        }

        // Fill in Bar Mark Properties
        if(data.binSpacing().has_value())
        {
            j["binSpacing"] = data.binSpacing().value();
        }
        if(data.cornerRadiusEnd().has_value())
        {
            j["cornerRadiusEnd"] = data.cornerRadiusEnd().value();
        }
        if(data.cornerRadiusTopLeft().has_value())
        {
            j["cornerRadiusTopLeft"] = data.cornerRadiusTopLeft().value();
        }
        if(data.cornerRadiusTopRight().has_value())
        {
            j["cornerRadiusTopRight"] = data.cornerRadiusTopRight().value();
        }
        if(data.cornerRadiusBottomLeft().has_value())
        {
            j["cornerRadiusBottomLeft"] = data.cornerRadiusBottomLeft().value();
        }
        if(data.cornerRadiusBottomRight().has_value())
        {
            j["cornerRadiusBottomRight"] = data.cornerRadiusBottomRight().value();
        }

        // Fill in Circle Mark Properties
        if(data.size().has_value())
        {
            j["size"] = data.size().value();
        }

        // Fill in Image Mark Properties
        if(data.url().has_value())
        {
            j["url"] = data.url().value();
        }
        if(data.aspect().has_value())
        {
            j["aspect"] = data.aspect().value();
        }

        // Fill in Point Mark Properties
        if(data.shape().has_value())
        {
            j["shape"] = data.shape().value();
        }

        // Fill in Text Mark Properties
        if(data.angle().has_value())
        {
            j["angle"] = data.angle().value();
        }
        if(data.dir().has_value())
        {
            j["dir"] = data.dir().value();
        }
        if(data.dx().has_value())
        {
            j["dx"] = data.dx().value();
        }
        if(data.dy().has_value())
        {
            j["dy"] = data.dy().value();
        }
        if(data.ellipsis().has_value())
        {
            j["ellipsis"] = data.ellipsis().value();
        }
        if(data.font().has_value())
        {
            j["font"] = data.font().value();
        }
        if(data.fontSize().has_value())
        {
            j["fontSize"] = data.fontSize().value();
        }
        if(data.fontStyle().has_value())
        {
            j["fontStyle"] = data.fontStyle().value();
        }
        if(data.fontWeight().has_value())
        {
            j["fontWeight"] = data.fontWeight().value();
        }
        if(data.limit().has_value())
        {
            j["limit"] = data.limit().value();
        }
        if(data.lineHeight().has_value())
        {
            j["lineHeight"] = data.lineHeight().value();
        }
        if(data.text().has_value())
        {
            j["text"] = data.text().value();
        }
    }

}