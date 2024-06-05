// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_RECT_CONFIG_HPP
#define XVEGA_RECT_CONFIG_HPP

#include <optional>

#include "./base_config.hpp"

namespace xv
{
    struct rect_config : public base_config<rect_config>
    {
        XPROPERTY(std::optional<double>, rect_config, binSpacing);
        XPROPERTY(std::optional<double>, rect_config, continuousBandSize);
        XPROPERTY(std::optional<double>, rect_config, discreteBandSize);
    };

    XVEGA_API void to_json(nl::json&, const rect_config&);
}

#endif
