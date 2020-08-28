// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BIND_CHECKBOX_HPP
#define XVEGA_BIND_CHECKBOX_HPP

#include "xproperty/xobserved.hpp"
#include "xtl/xoptional.hpp"
#include "nlohmann/json.hpp"
#include "../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct bind_checkbox : public xp::xobserved<bind_checkbox>
    {
        // Bind Checkbox Properties
        XPROPERTY(xtl::xoptional<std::string>, bind_checkbox, input);
        XPROPERTY(xtl::xoptional<double>, bind_checkbox, debounce);
        XPROPERTY(xtl::xoptional<std::string>, bind_checkbox, element);
        XPROPERTY(xtl::xoptional<std::string>, bind_checkbox, name);
        XPROPERTY(xtl::xoptional<std::string>, bind_checkbox, type);
    };

    void to_json(nl::json& j, const bind_checkbox& data)
    {
        serialize(j, data.input(), "input");
        serialize(j, data.debounce(), "debounce");
        serialize(j, data.element(), "element");
        serialize(j, data.name(), "name");
        serialize(j, data.type(), "type");
    }
}

#endif
