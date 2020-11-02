// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/base/xvega-base.hpp"
#include "../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const Chart& data)
    {
        j["$schema"] = "https://vega.github.io/schema/vega-lite/v4.json";
        j["data"] = data.data();
        j["mark"] = data.mark();
        serialize(j, data.encoding(), "encoding");

        int len_selections = data.selections().size();
        /*for(int i=0; i<len_selections; i++)
        {
            xtl::visit([&](auto&& arg){
                    j["selection"][arg.name().value()] = arg;
                }, data.selections()[i]);
        }*/

        int len_transformations = data.transformations().size();
        for(int i=0; i<len_transformations; i++)
        {
            xtl::visit([&](auto&& arg){
                    j["transform"][i] = arg;
                }, data.transformations()[i]);
        }

        serialize(j, data.width(), "width");
        serialize(j, data.height(), "height");
        serialize(j, data.config(), "config");
    }
}
