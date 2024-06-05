// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_LINE_HPP
#define XVEGA_MARK_LINE_HPP

#include <optional>

#include "../marks.hpp"

namespace xv
{
    struct mark_line : public mark<mark_line>
    {
        // Line Mark Properties
        XPROPERTY(std::optional<std::string>, mark_line, orient);
        XPROPERTY(std::optional<std::string>, mark_line, interpolate);
        XPROPERTY(std::optional<double>, mark_line, tension);
        XPROPERTY(std::optional<bool_string_object_type>, mark_line, point);

        XVEGA_API mark_line();
    };

    XVEGA_API void to_json(nl::json&, const mark_line&);
}

#endif
