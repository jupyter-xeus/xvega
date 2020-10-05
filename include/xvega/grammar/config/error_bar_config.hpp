// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ERROR_BAR_CONFIG_HPP
#define XVEGA_ERROR_BAR_CONFIG_HPP

#include "./mark_config.hpp"

namespace xv
{
    using bool_mark_config_type = xtl::variant<mark_config, bool>;

    struct error_bar_config : public xp::xobserved<error_bar_config>
    {
        XPROPERTY(xtl::xoptional<std::string>, error_bar_config, extent);
        XPROPERTY(xtl::xoptional<bool_mark_config_type>, error_bar_config, rule);
        XPROPERTY(xtl::xoptional<bool_mark_config_type>, error_bar_config, ticks);
    };

    void to_json(nl::json& j, const error_bar_config& data);
}

#endif