// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TICK_CONFIG_HPP
#define XVEGA_TICK_CONFIG_HPP

#include <optional>

#include "./base_config.hpp"

namespace xv
{
    struct tick_config : public base_config<tick_config>
    {
        XPROPERTY(std::optional<double>, tick_config, bandSize);
        XPROPERTY(std::optional<double>, tick_config, thickness);
    };

    XVEGA_API void to_json(nl::json&, const tick_config&);
}

#endif
