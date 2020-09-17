// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/functions/populate_selections.hpp"

namespace xv
{
    void populate_selections(nl::json& json_template, const Chart& v)
    {
        int len_selections = v.selections().size();
        
        for(int i=0; i<len_selections; i++)
        {
            xtl::visit([&](auto&& arg){
                    json_template["selection"][arg.name().value()]=arg;
                }, v.selections()[i]);
        }
    }
}