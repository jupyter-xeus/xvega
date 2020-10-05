// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_AREA_CONFIG_HPP
#define XVEGA_AREA_CONFIG_HPP

#include "./base_config.hpp"
#include "./overlay_mark_def.hpp"

namespace xv
{
    using bool_overlay_mark_def_type = xtl::variant<bool, overlay_mark_def>;
    using bool_overlay_mark_def_string_type = xtl::variant<bool, overlay_mark_def, std::string>;

    struct area_config : public base_config<area_config>
    {
        using base_type = base_config<area_config>;

        XPROPERTY(xtl::xoptional<bool_overlay_mark_def_type>, area_config, line);
        XPROPERTY(xtl::xoptional<bool_overlay_mark_def_string_type>, area_config, point);

        void to_json(nl::json& j) const;
    };
}

#endif
