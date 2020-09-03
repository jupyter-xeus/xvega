// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/functions/populate_data.hpp"

namespace xv
{
    void populate_data(nl::json& json_template, const Chart& v)
    {
        json_template["data"]["values"] = {{}};
        int i;
        for(auto const& x : v.data())
        {
            std::string column_name = x.first;
            std::vector<xtl::variant<double, int, std::string>> values = x.second;
            i = 0;
            for(auto& k: values)
            {
                xtl::visit([&](auto&& each_value){json_template["data"]["values"][i][x.first]=each_value;}, k);
                i++;
            }
        }
    }   
}
