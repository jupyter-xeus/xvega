// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/selections/bindings/bind_checkbox.hpp"

namespace xv
{
    void to_json(nl::json& j, const bind_checkbox& data)
    {
        serialize(j, data.input(), "input");
        serialize(j, data.debounce(), "debounce");
        serialize(j, data.element(), "element");
        serialize(j, data.name(), "name");
        serialize(j, data.type(), "type");
    }
}