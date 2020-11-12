// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_LINE_CONFIG_HPP
#define XVEGA_LINE_CONFIG_HPP

#include "./base_config.hpp"
#include "./overlay_mark_def.hpp"

namespace xv
{
    using bool_overlay_string_type = xtl::variant<bool, overlay_mark_def, std::string>;

    struct line_config : public base_config<line_config>
    {
        XPROPERTY(xtl::xoptional<bool_overlay_string_type>, line_config, point);
    };

    XVEGA_API void to_json(nl::json&, const line_config&);
}

#endif
