// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BIND_CHECKBOX_HPP
#define XVEGA_BIND_CHECKBOX_HPP

#include <optional>

#include "xproperty/xobserved.hpp"
#include "nlohmann/json.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct bind_checkbox : public xp::xobserved<bind_checkbox>
    {
        // Bind Checkbox Properties
        XPROPERTY(std::optional<std::string>, bind_checkbox, input);
        XPROPERTY(std::optional<double>, bind_checkbox, debounce);
        XPROPERTY(std::optional<std::string>, bind_checkbox, element);
        XPROPERTY(std::optional<std::string>, bind_checkbox, name);
        XPROPERTY(std::optional<std::string>, bind_checkbox, type);
    };

    XVEGA_API void to_json(nl::json& j, const bind_checkbox& data);
}

#endif
