// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_OVERLAY_MARK_DEF_HPP
#define XVEGA_OVERLAY_MARK_DEF_HPP

#include <optional>

#include "./base_config.hpp"

namespace xv
{
    struct overlay_mark_def : public base_config<overlay_mark_def>
    {
        XPROPERTY(std::optional<bool>, overlay_mark_def, clip);
        XPROPERTY(std::optional<std::vector<std::string>>, overlay_mark_def, style);
        XPROPERTY(std::optional<double>, overlay_mark_def, xOffset);
        XPROPERTY(std::optional<double>, overlay_mark_def, x2Offset);
        XPROPERTY(std::optional<double>, overlay_mark_def, yOffset);
        XPROPERTY(std::optional<double>, overlay_mark_def, y2Offset);
    };

    XVEGA_API void to_json(nl::json&, const overlay_mark_def&);
}

#endif
