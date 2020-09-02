// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/functions/populate_transformations.hpp"

namespace xv
{
    void populate_transformations(nl::json& json_template, const Chart& v)
    {
        int len_transformations = v.transformations().size();

        for(int i=0; i<len_transformations; i++)
        {
            xtl::visit([&](auto&& arg){
                    json_template["transform"][i]=arg;
                }, v.transformations()[i]);
        }
    }
}