// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_LINE_HPP
#define XVEGA_MARK_LINE_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_line : public mark<mark_line>
    {
        using base_type = mark<mark_line>;

        // Line Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, mark_line, orient);
        XPROPERTY(xtl::xoptional<std::string>, mark_line, interpolate);
        XPROPERTY(xtl::xoptional<double>, mark_line, tension);
        XPROPERTY(xtl::xoptional<bool_string_object_type>, mark_line, point);

        XVEGA_API mark_line();

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
