// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "../utils/custom_datatypes.hpp"

#include "./encodings/encoding-channels/position-channels/x.hpp"
#include "./encodings/encoding-channels/position-channels/y.hpp"
#include "./encodings/encoding-channels/position-channels/x2.hpp"
#include "./encodings/encoding-channels/position-channels/y2.hpp"
#include "./encodings/encoding-channels/position-channels/xerror.hpp"
#include "./encodings/encoding-channels/position-channels/yerror.hpp"
#include "./encodings/encoding-channels/position-channels/xerror2.hpp"
#include "./encodings/encoding-channels/position-channels/yerror2.hpp"
#include "./encodings/encoding-channels/position-channels/longitude.hpp"
#include "./encodings/encoding-channels/position-channels/latitude.hpp"
#include "./encodings/encoding-channels/position-channels/longitude2.hpp"
#include "./encodings/encoding-channels/position-channels/latitude2.hpp"

#include "./encodings/encoding-channels/mark-property-channels/color.hpp"
#include "./encodings/encoding-channels/mark-property-channels/fill.hpp"
#include "./encodings/encoding-channels/mark-property-channels/fillOpacity.hpp"
#include "./encodings/encoding-channels/mark-property-channels/opacity.hpp"
#include "./encodings/encoding-channels/mark-property-channels/shape.hpp"
#include "./encodings/encoding-channels/mark-property-channels/size.hpp"
#include "./encodings/encoding-channels/mark-property-channels/stroke.hpp"
#include "./encodings/encoding-channels/mark-property-channels/strokeDash.hpp"
#include "./encodings/encoding-channels/mark-property-channels/strokeOpacity.hpp"
#include "./encodings/encoding-channels/mark-property-channels/strokeWidth.hpp"

#include "./encodings/encoding-channels/text-tooltip-channels/text.hpp"
#include "./encodings/encoding-channels/text-tooltip-channels/key.hpp"
#include "./encodings/encoding-channels/text-tooltip-channels/tooltip.hpp"

#include "./encodings/encoding-channels/hyperlink-channels/href.hpp"

#include "./encodings/encoding-channels/detail-channel/detail.hpp"

#include "./encodings/encoding-channels/order-channel/order.hpp"

#include "./encodings/encoding-channels/facet-channels/row.hpp"
#include "./encodings/encoding-channels/facet-channels/facet.hpp"
#include "./encodings/encoding-channels/facet-channels/column.hpp"

namespace xv
{
    struct Encodings : public xp::xobserved<Encodings>
    {
        XPROPERTY(xtl::xoptional<X>, Encodings, x);
        XPROPERTY(xtl::xoptional<Y>, Encodings, y);
        XPROPERTY(xtl::xoptional<X2>, Encodings, x2);
        XPROPERTY(xtl::xoptional<Y2>, Encodings, y2);
        XPROPERTY(xtl::xoptional<XError>, Encodings, xError);
        XPROPERTY(xtl::xoptional<YError>, Encodings, yError);
        XPROPERTY(xtl::xoptional<XError2>, Encodings, xError2);
        XPROPERTY(xtl::xoptional<YError2>, Encodings, yError2);
        XPROPERTY(xtl::xoptional<Longitude>, Encodings, longitude);
        XPROPERTY(xtl::xoptional<Latitude>, Encodings, latitude);
        XPROPERTY(xtl::xoptional<Longitude2>, Encodings, longitude2);
        XPROPERTY(xtl::xoptional<Latitude2>, Encodings, latitude2);

        XPROPERTY(xtl::xoptional<Color>, Encodings, color);
        XPROPERTY(xtl::xoptional<Fill>, Encodings, fill);
        XPROPERTY(xtl::xoptional<FillOpacity>, Encodings, fillOpacity);
        XPROPERTY(xtl::xoptional<Opacity>, Encodings, opacity);
        XPROPERTY(xtl::xoptional<Shape>, Encodings, shape);
        XPROPERTY(xtl::xoptional<Size>, Encodings, size);
        XPROPERTY(xtl::xoptional<Stroke>, Encodings, stroke);
        XPROPERTY(xtl::xoptional<StrokeDash>, Encodings, strokeDash);
        XPROPERTY(xtl::xoptional<StrokeOpacity>, Encodings, strokeOpacity);
        XPROPERTY(xtl::xoptional<StrokeWidth>, Encodings, strokeWidth);

        XPROPERTY(xtl::xoptional<Text>, Encodings, text);
        XPROPERTY(xtl::xoptional<Key>, Encodings, key);
        XPROPERTY(xtl::xoptional<std::vector<Tooltip>>, Encodings, tooltip);

        XPROPERTY(xtl::xoptional<Href>, Encodings, href);

        XPROPERTY(xtl::xoptional<Detail>, Encodings, detail);

        XPROPERTY(xtl::xoptional<Order>, Encodings, order);

        XPROPERTY(xtl::xoptional<Row>, Encodings, row);
        XPROPERTY(xtl::xoptional<Facet>, Encodings, facet);
        XPROPERTY(xtl::xoptional<Column>, Encodings, column);
    };

    void to_json(nl::json& j, const Encodings& data)
    {
        if(data.x().has_value())
        {
            j["x"] = data.x().value();
        }
        if(data.y().has_value())
        {
            j["y"] = data.y().value();
        }
        if(data.x2().has_value())
        {
            j["x2"] = data.x2().value();
        }
        if(data.y2().has_value())
        {
            j["y2"] = data.y2().value();
        }
        if(data.xError().has_value())
        {
            j["xError"] = data.xError().value();
        }
        if(data.yError().has_value())
        {
            j["yError"] = data.yError().value();
        }
        if(data.xError2().has_value())
        {
            j["xError2"] = data.xError2().value();
        }
        if(data.yError2().has_value())
        {
            j["yError2"] = data.yError2().value();
        }
        if(data.longitude().has_value())
        {
            j["longitude"] = data.longitude().value();
        }
        if(data.latitude().has_value())
        {
            j["latitude"] = data.latitude().value();
        }
        if(data.longitude2().has_value())
        {
            j["longitude2"] = data.longitude2().value();
        }
        if(data.latitude2().has_value())
        {
            j["latitude2"] = data.latitude2().value();
        }
        if(data.color().has_value())
        {
            j["color"] = data.color().value();
        }
        if(data.fill().has_value())
        {
            j["fill"] = data.fill().value();
        }
        if(data.fillOpacity().has_value())
        {
            j["fillOpacity"] = data.fillOpacity().value();
        }
        if(data.opacity().has_value())
        {
            j["opacity"] = data.opacity().value();
        }
        if(data.shape().has_value())
        {
            j["shape"] = data.shape().value();
        }
        if(data.size().has_value())
        {
            j["size"] = data.size().value();
        }
        if(data.stroke().has_value())
        {
            j["stroke"] = data.stroke().value();
        }
        if(data.strokeDash().has_value())
        {
            j["strokeDash"] = data.strokeDash().value();
        }
        if(data.strokeOpacity().has_value())
        {
            j["strokeOpacity"] = data.strokeOpacity().value();
        }
        if(data.strokeWidth().has_value())
        {
            j["strokeWidth"] = data.strokeWidth().value();
        }
        if(data.text().has_value())
        {
            j["text"] = data.text().value();
        }
        if(data.key().has_value())
        {
            j["key"] = data.key().value();
        }
        if(data.tooltip().has_value())
        {
            j["tooltip"] = data.tooltip().value();
        }
        if(data.href().has_value())
        {
            j["href"] = data.href().value();
        }
        if(data.detail().has_value())
        {
            j["detail"] = data.detail().value();
        }
        if(data.order().has_value())
        {
            j["order"] = data.order().value();
        }
        if(data.row().has_value())
        {
            j["row"] = data.row().value();
        }
        if(data.facet().has_value())
        {
            j["facet"] = data.facet().value();
        }
        if(data.column().has_value())
        {
            j["column"] = data.column().value();
        }
    }
}