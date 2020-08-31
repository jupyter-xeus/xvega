// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BIND_RANGE_HPP
#define XVEGA_BIND_RANGE_HPP

#include "xproperty/xobserved.hpp"
#include "xtl/xoptional.hpp"
#include "nlohmann/json.hpp"
#include "../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct bind_range : public xp::xobserved<bind_range>
    {
        // Bind Range Properties
        XPROPERTY(xtl::xoptional<std::string>, bind_range, input);
        XPROPERTY(xtl::xoptional<double>, bind_range, debounce);
        XPROPERTY(xtl::xoptional<std::string>, bind_range, element);
        XPROPERTY(xtl::xoptional<double>, bind_range, max);
        XPROPERTY(xtl::xoptional<double>, bind_range, min);
        XPROPERTY(xtl::xoptional<std::string>, bind_range, name);
        XPROPERTY(xtl::xoptional<double>, bind_range, step);
        XPROPERTY(xtl::xoptional<std::string>, bind_range, type);
    };

    void to_json(nl::json& j, const bind_range& data)
    {
        serialize(j, data.input(), "input");
        serialize(j, data.debounce(), "debounce");
        serialize(j, data.element(), "element");
        serialize(j, data.max(), "max");
        serialize(j, data.min(), "min");
        serialize(j, data.name(), "name");
        serialize(j, data.step(), "step");
        serialize(j, data.type(), "type");
    }
}

#endif
