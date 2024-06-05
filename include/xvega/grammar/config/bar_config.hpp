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
        XPROPERTY(std::optional<double>, bar_config, binSpacing);
        XPROPERTY(std::optional<double>, bar_config, continuousBandSize);
        XPROPERTY(std::optional<double>, bar_config, cornerRadiusEnd);
        XPROPERTY(std::optional<double>, bar_config, discreteBandSize);
    };

    XVEGA_API void to_json(nl::json&, const bar_config&);
}

#endif
