// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_SQUARE_HPP
#define XVEGA_MARK_SQUARE_HPP

#include <optional>

#include "../marks.hpp"

namespace xv
{
    struct mark_square : public mark<mark_square>
    {
        // Square Mark Properties
        XPROPERTY(std::optional<double>, mark_square, size);

        XVEGA_API mark_square();
    };

    XVEGA_API void to_json(nl::json&, const mark_square&);
}

#endif
