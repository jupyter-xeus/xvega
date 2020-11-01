// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BAR_CONFIG_HPP
#define XVEGA_BAR_CONFIG_HPP

#include "./base_config.hpp"

namespace xv
{
    struct bar_config : public base_config<bar_config>
    {
        XPROPERTY(xtl::xoptional<double>, bar_config, binSpacing);
        XPROPERTY(xtl::xoptional<double>, bar_config, continuousBandSize);
        XPROPERTY(xtl::xoptional<double>, bar_config, cornerRadiusEnd);
        XPROPERTY(xtl::xoptional<double>, bar_config, discreteBandSize);

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
