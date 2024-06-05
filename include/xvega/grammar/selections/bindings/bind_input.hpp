// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BIND_INPUT_HPP
#define XVEGA_BIND_INPUT_HPP

#include <optional>

#include "xproperty/xobserved.hpp"
#include "nlohmann/json.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct bind_input : public xp::xobserved<bind_input>
    {
        // Bind Input Properties
        XPROPERTY(std::optional<std::string>, bind_input, autocomplete);
        XPROPERTY(std::optional<std::string>, bind_input, input);
        XPROPERTY(std::optional<double>, bind_input, debounce);
        XPROPERTY(std::optional<std::string>, bind_input, element);
        XPROPERTY(std::optional<std::string>, bind_input, name);
        XPROPERTY(std::optional<std::string>, bind_input, placeholder);
        XPROPERTY(std::optional<std::string>, bind_input, type);
    };

    XVEGA_API void to_json(nl::json& j, const bind_input& data);
}

#endif
