// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_AREA_HPP
#define XVEGA_MARK_AREA_HPP

#include <optional>

#include "../marks.hpp"

namespace xv
{
    struct mark_area : public mark<mark_area>
    {
        // Area Mark Properties
        XPROPERTY(std::optional<std::string>, mark_area, align);
        XPROPERTY(std::optional<std::string>, mark_area, baseline);
        XPROPERTY(std::optional<std::string>, mark_area, orient);
        XPROPERTY(std::optional<std::string>, mark_area, interpolate);
        XPROPERTY(std::optional<double>, mark_area, tension);
        XPROPERTY(std::optional<bool_object_type>, mark_area, line);
        XPROPERTY(std::optional<bool_string_object_type>, mark_area, point);

        XVEGA_API mark_area();
    };

    XVEGA_API void to_json(nl::json&, const mark_area&);
}

#endif
