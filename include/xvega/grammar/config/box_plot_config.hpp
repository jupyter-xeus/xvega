// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BOX_PLOT_CONFIG_HPP
#define XVEGA_BOX_PLOT_CONFIG_HPP

#include "./mark_config.hpp"

namespace xv
{
    using bool_mark_config_type = xtl::variant<mark_config, bool>;

    struct box_plot_config : public xp::xobserved<box_plot_config>
    {
        XPROPERTY(xtl::xoptional<bool_mark_config_type>, box_plot_config, box);
        XPROPERTY(xtl::xoptional<string_num_type>, box_plot_config, extent);
        XPROPERTY(xtl::xoptional<bool_mark_config_type>, box_plot_config, median);
        XPROPERTY(xtl::xoptional<bool_mark_config_type>, box_plot_config, outliers);
        XPROPERTY(xtl::xoptional<bool_mark_config_type>, box_plot_config, rule);
        XPROPERTY(xtl::xoptional<double>, box_plot_config, size);
        XPROPERTY(xtl::xoptional<bool_mark_config_type>, box_plot_config, ticks);
    };

    void to_json(nl::json& j, const box_plot_config& data);
}

#endif