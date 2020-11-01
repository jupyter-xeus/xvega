// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/selections/bindings/bind_radio_select.hpp"
#include "../../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const bind_radio_select& data)
    {
        serialize(j, data.input(), "input");
        if(data.options().has_value())
        {
            j["options"] = {{}};
            int i = 0;
            for(auto& k: data.options().value())
            {
                xtl::visit([&](auto&& arg){j["options"][i]=arg;}, k);
                i++;
            }
        }
        serialize(j, data.debounce(), "debounce");
        serialize(j, data.element(), "element");
        serialize(j, data.labels(), "labels");
        serialize(j, data.name(), "name");
        serialize(j, data.type(), "type");
    }
}