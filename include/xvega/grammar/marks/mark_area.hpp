// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_AREA_HPP
#define XVEGA_MARK_AREA_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_area : public mark<mark_area>
    {
        using base_type = mark<mark_area>;

        // Area Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, mark_area, align);
        XPROPERTY(xtl::xoptional<std::string>, mark_area, baseline);
        XPROPERTY(xtl::xoptional<std::string>, mark_area, orient);
        XPROPERTY(xtl::xoptional<std::string>, mark_area, interpolate);
        XPROPERTY(xtl::xoptional<double>, mark_area, tension);
        XPROPERTY(xtl::xoptional<bool_object_type>, mark_area, line);
        XPROPERTY(xtl::xoptional<bool_string_object_type>, mark_area, point);

        XVEGA_API mark_area();

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
