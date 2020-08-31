// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "../base/xvega-base.hpp"
#include "../utils/custom_datatypes.hpp"
#include <xtl/xvariant.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xjson.hpp>

namespace xv
{
    void populate_selections(const Chart& v)
    {
        int len_selections = v.selections().size();
        auto j = json_template;
        for(int i=0; i<len_selections; i++)
        {
            if(len_selections>1)
            {
                j["layer"][i] = nl::json::object();
                j = j["layer"][i];
            }

            xtl::visit([&](auto&& arg){
                    j["selection"][arg.name().value()]=arg;
                }, v.selections()[i]);

            if(len_selections>1)
            {
                json_template["layer"][i]["selection"] = j["selection"];
            }
        }
        if(len_selections == 1)
        {
            json_template["selection"] = j["selection"];
        }
    }
}