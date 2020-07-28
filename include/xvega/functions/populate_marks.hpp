#include "../base/xvega-base.hpp"
#include "../utils/custom_datatypes.hpp"
#include <xtl/xvariant.hpp>
#include <xtl/xoptional.hpp>
#include "../utils/xjson.hpp"

namespace xv
{
    void populate_marks(const Chart& v)
    {
        int len_marks = v.marks().size();
        if(len_marks==0)
        {
            std::cerr << "Make sure to include 'mark' in the specification!" << std::endl;
        }
        auto j = json_template;
        for(int i=0; i<len_marks; i++)
        {
            if(len_marks>1)
            {
                j["layer"][i] = nl::json::object();
                j = j["layer"][i];
            }
            
            // Fill in General Mark Properties
            if(v.marks()[i].type().has_value())
            {
                j["mark"]["type"] = v.marks()[i].type().value();
            }
            if(v.marks()[i].aria().has_value())
            {
                j["mark"]["aria"] = v.marks()[i].aria().value();
            }
            if(v.marks()[i].description().has_value())
            {
                j["mark"]["description"] = v.marks()[i].description().value();
            }
            if(v.marks()[i].style().has_value())
            {
                j["mark"]["style"] = v.marks()[i].style().value();
            }
            if(v.marks()[i].tooltip().has_value())
            {
                if(xtl::holds_alternative<std::string>(v.marks()[i].tooltip().value()))
                {
                    std::string tooltip = xtl::get<std::string>(v.marks()[i].tooltip().value());
                    j["mark"]["tooltip"] = tooltip;
                }
                else if(xtl::holds_alternative<bool>(v.marks()[i].tooltip().value()))
                {
                    bool tooltip = xtl::get<bool>(v.marks()[i].tooltip().value());
                    j["mark"]["tooltip"] = tooltip;
                }
                else if(xtl::holds_alternative<double>(v.marks()[i].tooltip().value()))
                {
                    double tooltip = xtl::get<double>(v.marks()[i].tooltip().value());
                    j["mark"]["tooltip"] = tooltip;
                }
                else if(xtl::holds_alternative<std::nullptr_t>(v.marks()[i].tooltip().value()))
                {
                    std::nullptr_t tooltip = xtl::get<std::nullptr_t>(v.marks()[i].tooltip().value());
                    j["mark"]["tooltip"] = tooltip;
                }
                else
                {
                    TooltipContent tooltip = xtl::get<TooltipContent>(v.marks()[i].tooltip().value());
                    if(tooltip.content().has_value())
                    {
                        j["mark"]["tooltip"]["content"] = tooltip.content().value();
                    }
                }
            }
            if(v.marks()[i].clip().has_value())
            {
                j["mark"]["clip"] = v.marks()[i].clip().value();
            }
            if(v.marks()[i].invalid().has_value())
            {
                if(xtl::holds_alternative<std::string>(v.marks()[i].invalid().value()))
                {
                    std::string invalid = xtl::get<std::string>(v.marks()[i].invalid().value());
                    j["mark"]["invalid"] = invalid;
                }
                else
                {
                    std::nullptr_t invalid = xtl::get<std::nullptr_t>(v.marks()[i].invalid().value());
                    j["mark"]["invalid"] = invalid;
                }
            }
            if(v.marks()[i].order().has_value())
            {
                if(xtl::holds_alternative<bool>(v.marks()[i].order().value()))
                {
                    bool order = xtl::get<bool>(v.marks()[i].order().value());
                    j["mark"]["order"] = order;
                }
                else
                {
                    std::nullptr_t order = xtl::get<std::nullptr_t>(v.marks()[i].order().value());
                    j["mark"]["order"] = order;
                }
            }

            // Fill in Position and Offset Properties
            if(v.marks()[i].x().has_value())
            {
                if(xtl::holds_alternative<std::string>(v.marks()[i].x().value()))
                {
                    std::string x = xtl::get<std::string>(v.marks()[i].x().value());
                    j["mark"]["x"] = x;
                }
                else
                {
                    double x = xtl::get<double>(v.marks()[i].x().value());
                    j["mark"]["x"] = x;
                }
            }
            if(v.marks()[i].x2().has_value())
            {
                if(xtl::holds_alternative<std::string>(v.marks()[i].x2().value()))
                {
                    std::string x2 = xtl::get<std::string>(v.marks()[i].x2().value());
                    j["mark"]["x2"] = x2;
                }
                else
                {
                    double x2 = xtl::get<double>(v.marks()[i].x2().value());
                    j["mark"]["x2"] = x2;
                }
            }
            if(v.marks()[i].width().has_value())
            {
                j["mark"]["width"] = v.marks()[i].width().value();
            }
            if(v.marks()[i].height().has_value())
            {
                j["mark"]["height"] = v.marks()[i].height().value();
            }
            if(v.marks()[i].y().has_value())
            {
                if(xtl::holds_alternative<std::string>(v.marks()[i].y().value()))
                {
                    std::string y = xtl::get<std::string>(v.marks()[i].y().value());
                    j["mark"]["y"] = y;
                }
                else
                {
                    double y = xtl::get<double>(v.marks()[i].y().value());
                    j["mark"]["y"] = y;
                }
            }
            if(v.marks()[i].y2().has_value())
            {
                if(xtl::holds_alternative<std::string>(v.marks()[i].y2().value()))
                {
                    std::string y2 = xtl::get<std::string>(v.marks()[i].y2().value());
                    j["mark"]["y2"] = y2;
                }
                else
                {
                    double y2 = xtl::get<double>(v.marks()[i].y2().value());
                    j["mark"]["y2"] = y2;
                }
            }
            if(v.marks()[i].xOffset().has_value())
            {
                j["mark"]["xOffset"] = v.marks()[i].xOffset().value();
            }
            if(v.marks()[i].x2Offset().has_value())
            {
                j["mark"]["x2Offset"] = v.marks()[i].x2Offset().value();
            }
            if(v.marks()[i].yOffset().has_value())
            {
                j["mark"]["yOffset"] = v.marks()[i].yOffset().value();
            }
            if(v.marks()[i].y2Offset().has_value())
            {
                j["mark"]["y2Offset"] = v.marks()[i].y2Offset().value();
            }

            // Fill in Color Properties
            if(v.marks()[i].filled().has_value())
            {
                j["mark"]["filled"] = v.marks()[i].filled().value();
            }
            if(v.marks()[i].color().has_value())
            {
                if(xtl::holds_alternative<std::string>(v.marks()[i].color().value()))
                {
                    std::string color = xtl::get<std::string>(v.marks()[i].color().value());
                    j["mark"]["color"] = color;
                }
                else if(xtl::holds_alternative<LinearGradient>(v.marks()[i].color().value()))
                {
                    LinearGradient color = xtl::get<LinearGradient>(v.marks()[i].color().value());
                    j["mark"]["color"]["gradient"] = color.gradient();
                    if(color.x1().has_value())
                    {
                        j["mark"]["color"]["x1"] = color.x1().value();
                    }
                    if(color.x2().has_value())
                    {
                        j["mark"]["color"]["x2"] = color.x2().value();
                    }
                    if(color.y1().has_value())
                    {
                        j["mark"]["color"]["y1"] = color.y1().value();
                    }
                    if(color.y2().has_value())
                    {
                        j["mark"]["color"]["y2"] = color.y2().value();
                    }
                    std::vector<GradientStop> stops = color.stops();
                    int len_stops = stops.size();
                    if(len_stops > 0)
                    {
                        j["mark"]["color"]["stops"] = {{}};
                        for(int k=0; k<len_stops; k++)
                        {
                            GradientStop each_stop = stops.at(k);
                            if(each_stop.color().has_value())
                            {
                                j["mark"]["color"]["stops"][k]["color"] = each_stop.color().value();
                            }
                            if(each_stop.offset().has_value())
                            {
                                j["mark"]["color"]["stops"][k]["offset"] = each_stop.offset().value();
                            }
                        }
                    }
                }
                else if(xtl::holds_alternative<RadialGradient>(v.marks()[i].color().value()))
                {
                    RadialGradient color = xtl::get<RadialGradient>(v.marks()[i].color().value());
                    j["mark"]["color"]["gradient"] = color.gradient();
                    if(color.x1().has_value())
                    {
                        j["mark"]["color"]["x1"] = color.x1().value();
                    }
                    if(color.x2().has_value())
                    {
                        j["mark"]["color"]["x2"] = color.x2().value();
                    }
                    if(color.y1().has_value())
                    {
                        j["mark"]["color"]["y1"] = color.y1().value();
                    }
                    if(color.y2().has_value())
                    {
                        j["mark"]["color"]["y2"] = color.y2().value();
                    }
                    if(color.r1().has_value())
                    {
                        j["mark"]["color"]["r1"] = color.r1().value();
                    }
                    if(color.r2().has_value())
                    {
                        j["mark"]["color"]["r2"] = color.r2().value();
                    }
                    std::vector<GradientStop> stops = color.stops();
                    int len_stops = stops.size();
                    if(len_stops > 0)
                    {
                        j["mark"]["color"]["stops"] = {{}};
                        for(int k=0; k<len_stops; k++)
                        {
                            GradientStop each_stop = stops.at(k);
                            if(each_stop.color().has_value())
                            {
                                j["mark"]["color"]["stops"][k]["color"] = each_stop.color().value();
                            }
                            if(each_stop.offset().has_value())
                            {
                                j["mark"]["color"]["stops"][k]["offset"] = each_stop.offset().value();
                            }
                        }
                    }
                }
            }
            if(v.marks()[i].fill().has_value())
            {
                if(xtl::holds_alternative<std::string>(v.marks()[i].fill().value()))
                {
                    std::string fill = xtl::get<std::string>(v.marks()[i].fill().value());
                    j["mark"]["fill"] = fill;
                }
                else if(xtl::holds_alternative<LinearGradient>(v.marks()[i].fill().value()))
                {
                    LinearGradient fill = xtl::get<LinearGradient>(v.marks()[i].fill().value());
                    j["mark"]["fill"]["gradient"] = fill.gradient();
                    if(fill.x1().has_value())
                    {
                        j["mark"]["fill"]["x1"] = fill.x1().value();
                    }
                    if(fill.x2().has_value())
                    {
                        j["mark"]["fill"]["x2"] = fill.x2().value();
                    }
                    if(fill.y1().has_value())
                    {
                        j["mark"]["fill"]["y1"] = fill.y1().value();
                    }
                    if(fill.y2().has_value())
                    {
                        j["mark"]["fill"]["y2"] = fill.y2().value();
                    }
                    std::vector<GradientStop> stops = fill.stops();
                    int len_stops = stops.size();
                    if(len_stops > 0)
                    {
                        j["mark"]["fill"]["stops"] = {{}};
                        for(int k=0; k<len_stops; k++)
                        {
                            GradientStop each_stop = stops.at(k);
                            if(each_stop.color().has_value())
                            {
                                j["mark"]["fill"]["stops"][k]["color"] = each_stop.color().value();
                            }
                            if(each_stop.offset().has_value())
                            {
                                j["mark"]["fill"]["stops"][k]["offset"] = each_stop.offset().value();
                            }
                        }
                    }
                }
                else if(xtl::holds_alternative<RadialGradient>(v.marks()[i].fill().value()))
                {
                    RadialGradient fill = xtl::get<RadialGradient>(v.marks()[i].fill().value());
                    j["mark"]["fill"]["gradient"] = fill.gradient();
                    if(fill.x1().has_value())
                    {
                        j["mark"]["fill"]["x1"] = fill.x1().value();
                    }
                    if(fill.x2().has_value())
                    {
                        j["mark"]["fill"]["x2"] = fill.x2().value();
                    }
                    if(fill.y1().has_value())
                    {
                        j["mark"]["fill"]["y1"] = fill.y1().value();
                    }
                    if(fill.y2().has_value())
                    {
                        j["mark"]["fill"]["y2"] = fill.y2().value();
                    }
                    if(fill.r1().has_value())
                    {
                        j["mark"]["fill"]["r1"] = fill.r1().value();
                    }
                    if(fill.r2().has_value())
                    {
                        j["mark"]["fill"]["r2"] = fill.r2().value();
                    }
                    std::vector<GradientStop> stops = fill.stops();
                    int len_stops = stops.size();
                    if(len_stops > 0)
                    {
                        j["mark"]["fill"]["stops"] = {{}};
                        for(int k=0; k<len_stops; k++)
                        {
                            GradientStop each_stop = stops.at(k);
                            if(each_stop.color().has_value())
                            {
                                j["mark"]["fill"]["stops"][k]["color"] = each_stop.color().value();
                            }
                            if(each_stop.offset().has_value())
                            {
                                j["mark"]["fill"]["stops"][k]["offset"] = each_stop.offset().value();
                            }
                        }
                    }
                }
                else
                {
                    std::nullptr_t fill = xtl::get<std::nullptr_t>(v.marks()[i].fill().value());
                    j["mark"]["fill"] = fill;
                }
            }
            if(v.marks()[i].stroke().has_value())
            {
                if(xtl::holds_alternative<std::string>(v.marks()[i].stroke().value()))
                {
                    std::string stroke = xtl::get<std::string>(v.marks()[i].stroke().value());
                    j["mark"]["stroke"] = stroke;
                }
                else if(xtl::holds_alternative<LinearGradient>(v.marks()[i].stroke().value()))
                {
                    LinearGradient stroke = xtl::get<LinearGradient>(v.marks()[i].stroke().value());
                    j["mark"]["stroke"]["gradient"] = stroke.gradient();
                    if(stroke.x1().has_value())
                    {
                        j["mark"]["stroke"]["x1"] = stroke.x1().value();
                    }
                    if(stroke.x2().has_value())
                    {
                        j["mark"]["stroke"]["x2"] = stroke.x2().value();
                    }
                    if(stroke.y1().has_value())
                    {
                        j["mark"]["stroke"]["y1"] = stroke.y1().value();
                    }
                    if(stroke.y2().has_value())
                    {
                        j["mark"]["stroke"]["y2"] = stroke.y2().value();
                    }
                    std::vector<GradientStop> stops = stroke.stops();
                    int len_stops = stops.size();
                    if(len_stops > 0)
                    {
                        j["mark"]["stroke"]["stops"] = {{}};
                        for(int k=0; k<len_stops; k++)
                        {
                            GradientStop each_stop = stops.at(k);
                            if(each_stop.color().has_value())
                            {
                                j["mark"]["stroke"]["stops"][k]["color"] = each_stop.color().value();
                            }
                            if(each_stop.offset().has_value())
                            {
                                j["mark"]["stroke"]["stops"][k]["offset"] = each_stop.offset().value();
                            }
                        }
                    }
                }
                else if(xtl::holds_alternative<RadialGradient>(v.marks()[i].stroke().value()))
                {
                    RadialGradient stroke = xtl::get<RadialGradient>(v.marks()[i].stroke().value());
                    j["mark"]["stroke"]["gradient"] = stroke.gradient();
                    if(stroke.x1().has_value())
                    {
                        j["mark"]["stroke"]["x1"] = stroke.x1().value();
                    }
                    if(stroke.x2().has_value())
                    {
                        j["mark"]["stroke"]["x2"] = stroke.x2().value();
                    }
                    if(stroke.y1().has_value())
                    {
                        j["mark"]["stroke"]["y1"] = stroke.y1().value();
                    }
                    if(stroke.y2().has_value())
                    {
                        j["mark"]["stroke"]["y2"] = stroke.y2().value();
                    }
                    if(stroke.r1().has_value())
                    {
                        j["mark"]["stroke"]["r1"] = stroke.r1().value();
                    }
                    if(stroke.r2().has_value())
                    {
                        j["mark"]["stroke"]["r2"] = stroke.r2().value();
                    }
                    std::vector<GradientStop> stops = stroke.stops();
                    int len_stops = stops.size();
                    if(len_stops > 0)
                    {
                        j["mark"]["stroke"]["stops"] = {{}};
                        for(int k=0; k<len_stops; k++)
                        {
                            GradientStop each_stop = stops.at(k);
                            if(each_stop.color().has_value())
                            {
                                j["mark"]["stroke"]["stops"][k]["color"] = each_stop.color().value();
                            }
                            if(each_stop.offset().has_value())
                            {
                                j["mark"]["stroke"]["stops"][k]["offset"] = each_stop.offset().value();
                            }
                        }
                    }
                }
                else
                {
                    std::nullptr_t stroke = xtl::get<std::nullptr_t>(v.marks()[i].stroke().value());
                    j["mark"]["stroke"] = stroke;
                }
            }
            if(v.marks()[i].blend().has_value())
            {
                j["mark"]["blend"] = v.marks()[i].blend().value();
            }
            if(v.marks()[i].opacity().has_value())
            {
                j["mark"]["opacity"] = v.marks()[i].opacity().value();
            }
            if(v.marks()[i].fillOpacity().has_value())
            {
                j["mark"]["fillOpacity"] = v.marks()[i].fillOpacity().value();
            }
            if(v.marks()[i].strokeOpacity().has_value())
            {
                j["mark"]["strokeOpacity"] = v.marks()[i].strokeOpacity().value();
            }
            if(v.marks()[i].strokeCap().has_value())
            {
                j["mark"]["strokeCap"] = v.marks()[i].strokeCap().value();
            }
            if(v.marks()[i].strokeDash().has_value())
            {
                j["mark"]["strokeDash"] = v.marks()[i].strokeDash().value();
            }
            if(v.marks()[i].strokeDashOffset().has_value())
            {
                j["mark"]["strokeDashOffset"] = v.marks()[i].strokeDashOffset().value();
            }
            if(v.marks()[i].strokeJoin().has_value())
            {
                j["mark"]["strokeJoin"] = v.marks()[i].strokeJoin().value();
            }
            if(v.marks()[i].strokeMiterLimit().has_value())
            {
                j["mark"]["strokeMiterLimit"] = v.marks()[i].strokeMiterLimit().value();
            }
            if(v.marks()[i].strokeWidth().has_value())
            {
                j["mark"]["strokeWidth"] = v.marks()[i].strokeWidth().value();
            }

            // Fill in Hyperlink Properties
            if(v.marks()[i].href().has_value())
            {
                j["mark"]["href"] = v.marks()[i].href().value();
            }
            if(v.marks()[i].cursor().has_value())
            {
                j["mark"]["cursor"] = v.marks()[i].cursor().value();
            }

            // Fill in Arc Mark Properties
            if(v.marks()[i].radius().has_value())
            {
                j["mark"]["radius"] = v.marks()[i].radius().value();
            }
            if(v.marks()[i].radius2().has_value())
            {
                j["mark"]["radius2"] = v.marks()[i].radius2().value();
            }
            if(v.marks()[i].innerRadius().has_value())
            {
                j["mark"]["innerRadius"] = v.marks()[i].innerRadius().value();
            }
            if(v.marks()[i].outerRadius().has_value())
            {
                j["mark"]["outerRadius"] = v.marks()[i].outerRadius().value();
            }
            if(v.marks()[i].theta().has_value())
            {
                j["mark"]["theta"] = v.marks()[i].theta().value();
            }
            if(v.marks()[i].theta2().has_value())
            {
                j["mark"]["theta2"] = v.marks()[i].theta2().value();
            }
            if(v.marks()[i].cornerRadius().has_value())
            {
                j["mark"]["cornerRadius"] = v.marks()[i].cornerRadius().value();
            }
            if(v.marks()[i].padAngle().has_value())
            {
                j["mark"]["padAngle"] = v.marks()[i].padAngle().value();
            }
            if(v.marks()[i].radiusOffset().has_value())
            {
                j["mark"]["radiusOffset"] = v.marks()[i].radiusOffset().value();
            }
            if(v.marks()[i].radius2Offset().has_value())
            {
                j["mark"]["radius2Offset"] = v.marks()[i].radius2Offset().value();
            }
            if(v.marks()[i].thetaOffset().has_value())
            {
                j["mark"]["thetaOffset"] = v.marks()[i].thetaOffset().value();
            }
            if(v.marks()[i].theta2Offset().has_value())
            {
                j["mark"]["theta2Offset"] = v.marks()[i].theta2Offset().value();
            }

            // Fill in Area Mark Properties
            if(v.marks()[i].align().has_value())
            {
                j["mark"]["align"] = v.marks()[i].align().value();
            }
            if(v.marks()[i].baseline().has_value())
            {
                j["mark"]["baseline"] = v.marks()[i].baseline().value();
            }
            if(v.marks()[i].orient().has_value())
            {
                j["mark"]["orient"] = v.marks()[i].orient().value();
            }
            if(v.marks()[i].interpolate().has_value())
            {
                j["mark"]["interpolate"] = v.marks()[i].interpolate().value();
            }
            if(v.marks()[i].tension().has_value())
            {
                j["mark"]["tension"] = v.marks()[i].tension().value();
            }
            if(v.marks()[i].line().has_value())
            {
                if(xtl::holds_alternative<bool>(v.marks()[i].line().value()))
                {
                    bool line = xtl::get<bool>(v.marks()[i].line().value());
                    j["mark"]["line"] = line;
                }
                else
                {
                    nl::json line = xtl::get<nl::json>(v.marks()[i].line().value());
                    j["mark"]["line"] = line;
                }
            }
            if(v.marks()[i].point().has_value())
            {
                if(xtl::holds_alternative<bool>(v.marks()[i].point().value()))
                {
                    bool point = xtl::get<bool>(v.marks()[i].point().value());
                    j["mark"]["point"] = point;
                }
                else if(xtl::holds_alternative<std::string>(v.marks()[i].point().value()))
                {
                    std::string point = xtl::get<std::string>(v.marks()[i].point().value());
                    j["mark"]["point"] = point;
                }
                else
                {
                    nl::json point = xtl::get<nl::json>(v.marks()[i].point().value());
                    j["mark"]["point"] = point;
                }
            }

            // Fill in Bar Mark Properties
            if(v.marks()[i].binSpacing().has_value())
            {
                j["mark"]["binSpacing"] = v.marks()[i].binSpacing().value();
            }
            if(v.marks()[i].cornerRadiusEnd().has_value())
            {
                j["mark"]["cornerRadiusEnd"] = v.marks()[i].cornerRadiusEnd().value();
            }
            if(v.marks()[i].cornerRadiusTopLeft().has_value())
            {
                j["mark"]["cornerRadiusTopLeft"] = v.marks()[i].cornerRadiusTopLeft().value();
            }
            if(v.marks()[i].cornerRadiusTopRight().has_value())
            {
                j["mark"]["cornerRadiusTopRight"] = v.marks()[i].cornerRadiusTopRight().value();
            }
            if(v.marks()[i].cornerRadiusBottomLeft().has_value())
            {
                j["mark"]["cornerRadiusBottomLeft"] = v.marks()[i].cornerRadiusBottomLeft().value();
            }
            if(v.marks()[i].cornerRadiusBottomRight().has_value())
            {
                j["mark"]["cornerRadiusBottomRight"] = v.marks()[i].cornerRadiusBottomRight().value();
            }

            // Fill in Circle Mark Properties
            if(v.marks()[i].size().has_value())
            {
                j["mark"]["size"] = v.marks()[i].size().value();
            }

            // Fill in Image Mark Properties
            if(v.marks()[i].url().has_value())
            {
                if(xtl::holds_alternative<bool>(v.marks()[i].url().value()))
                {
                    bool url = xtl::get<bool>(v.marks()[i].url().value());
                    j["mark"]["url"] = url;
                }
                else if(xtl::holds_alternative<std::string>(v.marks()[i].url().value()))
                {
                    std::string url = xtl::get<std::string>(v.marks()[i].url().value());
                    j["mark"]["url"] = url;
                }
                else if(xtl::holds_alternative<double>(v.marks()[i].url().value()))
                {
                    double url = xtl::get<double>(v.marks()[i].url().value());
                    j["mark"]["url"] = url;
                }
                else
                {
                    std::nullptr_t url = xtl::get<std::nullptr_t>(v.marks()[i].url().value());
                    j["mark"]["url"] = url;
                }
            }
            if(v.marks()[i].aspect().has_value())
            {
                j["mark"]["aspect"] = v.marks()[i].aspect().value();
            }

            // Fill in Point Mark Properties
            if(v.marks()[i].shape().has_value())
            {
                j["mark"]["shape"] = v.marks()[i].shape().value();
            }

            // Fill in Text Mark Properties
            if(v.marks()[i].angle().has_value())
            {
                j["mark"]["angle"] = v.marks()[i].angle().value();
            }
            if(v.marks()[i].dir().has_value())
            {
                j["mark"]["dir"] = v.marks()[i].dir().value();
            }
            if(v.marks()[i].dx().has_value())
            {
                j["mark"]["dx"] = v.marks()[i].dx().value();
            }
            if(v.marks()[i].dy().has_value())
            {
                j["mark"]["dy"] = v.marks()[i].dy().value();
            }
            if(v.marks()[i].ellipsis().has_value())
            {
                j["mark"]["ellipsis"] = v.marks()[i].ellipsis().value();
            }
            if(v.marks()[i].font().has_value())
            {
                j["mark"]["font"] = v.marks()[i].font().value();
            }
            if(v.marks()[i].fontSize().has_value())
            {
                j["mark"]["fontSize"] = v.marks()[i].fontSize().value();
            }
            if(v.marks()[i].fontStyle().has_value())
            {
                j["mark"]["fontStyle"] = v.marks()[i].fontStyle().value();
            }
            if(v.marks()[i].fontWeight().has_value())
            {
                if(xtl::holds_alternative<std::string>(v.marks()[i].fontWeight().value()))
                {
                    std::string fontWeight = xtl::get<std::string>(v.marks()[i].fontWeight().value());
                    j["mark"]["fontWeight"] = fontWeight;
                }
                else if(xtl::holds_alternative<double>(v.marks()[i].fontWeight().value()))
                {
                    double fontWeight = xtl::get<double>(v.marks()[i].fontWeight().value());
                    j["mark"]["fontWeight"] = fontWeight;
                }
            }
            if(v.marks()[i].limit().has_value())
            {
                j["mark"]["limit"] = v.marks()[i].limit().value();
            }
            if(v.marks()[i].lineHeight().has_value())
            {
                j["mark"]["lineHeight"] = v.marks()[i].lineHeight().value();
            }
            if(v.marks()[i].text().has_value())
            {
                j["mark"]["text"] = v.marks()[i].text().value();
            }

            if(len_marks>1)
            {
                json_template["layer"][i]["mark"] = j["mark"];
            }
        }
        if(len_marks == 1)
        {
            json_template["mark"] = j["mark"];
        }
    }
}