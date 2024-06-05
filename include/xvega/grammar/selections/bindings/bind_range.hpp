// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BIND_RANGE_HPP
#define XVEGA_BIND_RANGE_HPP

#include <optional>

#include "xproperty/xobserved.hpp"
#include "nlohmann/json.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct bind_range : public xp::xobserved<bind_range>
    {
        // Bind Range Properties
        XPROPERTY(std::optional<std::string>, bind_range, input);
        XPROPERTY(std::optional<double>, bind_range, debounce);
        XPROPERTY(std::optional<std::string>, bind_range, element);
        XPROPERTY(std::optional<double>, bind_range, max);
        XPROPERTY(std::optional<double>, bind_range, min);
        XPROPERTY(std::optional<std::string>, bind_range, name);
        XPROPERTY(std::optional<double>, bind_range, step);
        XPROPERTY(std::optional<std::string>, bind_range, type);
    };

    XVEGA_API void to_json(nl::json& j, const bind_range& data);
}

#endif
