// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/functions/populate_marks.hpp"

namespace xv
{
    void populate_marks(nl::json& json_template, const Chart& v)
    {
        int len_marks = v.marks().size();
        if(len_marks==0)
        {
            std::cerr << "Make sure to include 'mark' in the specification!" << std::endl;
        }
        auto j = json_template;
        for(int i=0; i<len_marks; i++)
        {
            if(len_marks>1)
            {
                j["layer"][i] = nl::json::object();
                j = j["layer"][i];
            }
            
            j["mark"] = v.marks()[i];

            if(len_marks>1)
            {
                json_template["layer"][i]["mark"] = j["mark"];
            }
        }
        if(len_marks == 1)
        {
            json_template["mark"] = j["mark"];
        }
    }
}