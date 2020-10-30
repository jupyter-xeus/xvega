// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/transformations/transform_lookup.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const lookup_data& data)
    {
        serialize(j, data.data(), "data");
        serialize(j, data.key(), "key");
        serialize(j, data.fields(), "fields");
    }

    void to_json(nl::json& j, const lookup_selection& data)
    {
        if(data.selection().has_value())
        {
            xtl::visit([&](auto&& arg){
                    j["selection"]=arg.name().value();
                }, data.selection().value());
        }
        serialize(j, data.key(), "key");
        serialize(j, data.fields(), "fields");
    }

    void to_json(nl::json& j, const transform_lookup& data)
    {
        serialize(j, data.lookup(), "lookup");
        serialize(j, data.from(), "from");
        serialize(j, data.as(), "as");
        serialize(j, data.default_val(), "default");
    }
}