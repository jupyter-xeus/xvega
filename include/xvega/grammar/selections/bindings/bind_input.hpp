// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BIND_INPUT_HPP
#define XVEGA_BIND_INPUT_HPP

#include "xproperty/xobserved.hpp"
#include "xtl/xoptional.hpp"
#include "nlohmann/json.hpp"
#include "../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct bind_input : public xp::xobserved<bind_input>
    {
        // Bind Input Properties
        XPROPERTY(xtl::xoptional<std::string>, bind_input, autocomplete);
        XPROPERTY(xtl::xoptional<std::string>, bind_input, input);
        XPROPERTY(xtl::xoptional<double>, bind_input, debounce);
        XPROPERTY(xtl::xoptional<std::string>, bind_input, element);
        XPROPERTY(xtl::xoptional<std::string>, bind_input, name);
        XPROPERTY(xtl::xoptional<std::string>, bind_input, placeholder);
        XPROPERTY(xtl::xoptional<std::string>, bind_input, type);
    };

    void to_json(nl::json& j, const bind_input& data)
    {
        serialize(j, data.autocomplete(), "autocomplete");
        serialize(j, data.input(), "input");
        serialize(j, data.debounce(), "debounce");
        serialize(j, data.element(), "element");
        serialize(j, data.name(), "name");
        serialize(j, data.placeholder(), "placeholder");
        serialize(j, data.type(), "type");
    }
}

#endif
