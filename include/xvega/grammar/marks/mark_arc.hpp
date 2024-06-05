// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_ARC_HPP
#define XVEGA_MARK_ARC_HPP

#include <optional>

#include "../marks.hpp"

namespace xv
{
    struct mark_arc : public mark<mark_arc>
    {
        // Arc Mark Properties
        XPROPERTY(std::optional<double>, mark_arc, radius);
        XPROPERTY(std::optional<double>, mark_arc, radius2);
        XPROPERTY(std::optional<double>, mark_arc, innerRadius);
        XPROPERTY(std::optional<double>, mark_arc, outerRadius);
        XPROPERTY(std::optional<double>, mark_arc, theta);
        XPROPERTY(std::optional<double>, mark_arc, theta2);
        XPROPERTY(std::optional<double>, mark_arc, cornerRadius);
        XPROPERTY(std::optional<double>, mark_arc, padAngle);
        XPROPERTY(std::optional<double>, mark_arc, radiusOffset);
        XPROPERTY(std::optional<double>, mark_arc, radius2Offset);
        XPROPERTY(std::optional<double>, mark_arc, thetaOffset);
        XPROPERTY(std::optional<double>, mark_arc, theta2Offset);

        XVEGA_API mark_arc();
    };

    XVEGA_API void to_json(nl::json&, const mark_arc&);
}

#endif
