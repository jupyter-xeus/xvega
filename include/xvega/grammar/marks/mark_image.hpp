// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_IMAGE_HPP
#define XVEGA_MARK_IMAGE_HPP

#include <optional>

#include "../marks.hpp"

namespace xv
{
    struct mark_image : public mark<mark_image>
    {
        // Image Mark Properties
        XPROPERTY(std::optional<any_type>, mark_image, url);
        XPROPERTY(std::optional<bool>, mark_image, aspect);
        XPROPERTY(std::optional<std::string>, mark_image, align);
        XPROPERTY(std::optional<std::string>, mark_image, baseline);

        XVEGA_API mark_image();
    };

    XVEGA_API void to_json(nl::json&, const mark_image&);
}

#endif
