// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_OVERLAY_MARK_DEF_HPP
#define XVEGA_OVERLAY_MARK_DEF_HPP

#include "./base_config.hpp"

namespace xv
{
    struct overlay_mark_def : public base_config<overlay_mark_def>
    {
        XPROPERTY(xtl::xoptional<bool>, overlay_mark_def, clip);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, overlay_mark_def, style);
        XPROPERTY(xtl::xoptional<double>, overlay_mark_def, xOffset);
        XPROPERTY(xtl::xoptional<double>, overlay_mark_def, x2Offset);
        XPROPERTY(xtl::xoptional<double>, overlay_mark_def, yOffset);
        XPROPERTY(xtl::xoptional<double>, overlay_mark_def, y2Offset);

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
