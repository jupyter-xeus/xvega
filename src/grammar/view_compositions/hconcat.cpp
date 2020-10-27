// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/view_compositions/hconcat.hpp"

namespace xv
{
    void to_json(nl::json& j, const hconcat& data)
    {
        j["$schema"] = "https://vega.github.io/schema/vega-lite/v4.json";
        int len_charts = data.charts().size();
        
        for(int i=0; i<len_charts; i++)
        {
            j["hconcat"][i]["mark"] = data.charts()[i].mark();
            serialize(j["hconcat"][i], data.charts()[i].encoding(), "encoding");
            serialize(j["hconcat"][i], data.charts()[i].width(), "width");
            serialize(j["hconcat"][i], data.charts()[i].height(), "height");
            int len_selections = data.charts()[i].selections().size();
            int len_transformations = data.charts()[i].transformations().size();
            for(int k=0; k<len_selections; k++)
            {
                xtl::visit([&](auto&& arg){
                        j["hconcat"][i]["selection"][arg.name().value()]=arg;
                    }, data.charts()[i].selections()[k]);
            }
            for(int k=0; k<len_transformations; k++)
            {
                xtl::visit([&](auto&& arg){
                        j["hconcat"][i]["transform"][k]=arg;
                    }, data.charts()[i].transformations()[k]);
            }
        }
        j["data"] = data.charts()[0].data();
    }
}