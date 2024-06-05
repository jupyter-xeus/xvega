// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODINGS_HPP
#define XVEGA_ENCODINGS_HPP

#include <optional>
#include <variant>

#include "../xvega_config.hpp"

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
        XPROPERTY(std::optional<X>, Encodings, x);
        XPROPERTY(std::optional<Y>, Encodings, y);
        XPROPERTY(std::optional<X2>, Encodings, x2);
        XPROPERTY(std::optional<Y2>, Encodings, y2);
        XPROPERTY(std::optional<XError>, Encodings, xError);
        XPROPERTY(std::optional<YError>, Encodings, yError);
        XPROPERTY(std::optional<XError2>, Encodings, xError2);
        XPROPERTY(std::optional<YError2>, Encodings, yError2);
        XPROPERTY(std::optional<Longitude>, Encodings, longitude);
        XPROPERTY(std::optional<Latitude>, Encodings, latitude);
        XPROPERTY(std::optional<Longitude2>, Encodings, longitude2);
        XPROPERTY(std::optional<Latitude2>, Encodings, latitude2);

        XPROPERTY(std::optional<Color>, Encodings, color);
        XPROPERTY(std::optional<Fill>, Encodings, fill);
        XPROPERTY(std::optional<FillOpacity>, Encodings, fillOpacity);
        XPROPERTY(std::optional<Opacity>, Encodings, opacity);
        XPROPERTY(std::optional<Shape>, Encodings, shape);
        XPROPERTY(std::optional<Size>, Encodings, size);
        XPROPERTY(std::optional<Stroke>, Encodings, stroke);
        XPROPERTY(std::optional<StrokeDash>, Encodings, strokeDash);
        XPROPERTY(std::optional<StrokeOpacity>, Encodings, strokeOpacity);
        XPROPERTY(std::optional<StrokeWidth>, Encodings, strokeWidth);

        XPROPERTY(std::optional<Text>, Encodings, text);
        XPROPERTY(std::optional<Key>, Encodings, key);
        XPROPERTY(std::optional<std::vector<Tooltip>>, Encodings, tooltip);

        XPROPERTY(std::optional<Href>, Encodings, href);

        XPROPERTY(std::optional<Detail>, Encodings, detail);

        XPROPERTY(std::optional<Order>, Encodings, order);

        XPROPERTY(std::optional<Row>, Encodings, row);
        XPROPERTY(std::optional<Facet>, Encodings, facet);
        XPROPERTY(std::optional<Column>, Encodings, column);
    };

    XVEGA_API void to_json(nl::json& j, const Encodings& data);
}

#endif
