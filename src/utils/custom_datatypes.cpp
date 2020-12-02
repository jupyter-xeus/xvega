// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/utils/custom_datatypes.hpp"

#include "./serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const data_frame& data)
    {
        j["values"] = {{}};
        int i;
        for(auto const& x : data.values().value())
        {
            std::string column_name = x.first;
            std::vector<xtl::variant<double, int, std::string, std::nullptr_t>> values = x.second;
            i = 0;
            for(auto& k: values)
            {
                xtl::visit([&](auto&& each_value){j["values"][i][x.first]=each_value;}, k);
                i++;
            }
        }
    }

    void to_json(nl::json& j, const GradientStop& data)
    {
        serialize(j, data.color(), "color");
        serialize(j, data.offset(), "offset");
    }

    void to_json(nl::json& j, const LinearGradient& data) {
        j["gradient"] = data.gradient();
        serialize(j, data.x1(), "x1");
        serialize(j, data.x2(), "x2");
        serialize(j, data.y1(), "y1");
        serialize(j, data.y2(), "y2");
        j["stops"] = data.stops();
    }

    void to_json(nl::json& j, const RadialGradient& data)
    {
        j["gradient"] = data.gradient();
        serialize(j, data.x1(), "x1");
        serialize(j, data.x2(), "x2");
        serialize(j, data.y1(), "y1");
        serialize(j, data.y2(), "y2");
        serialize(j, data.r1(), "r1");
        serialize(j, data.r2(), "r2");
        j["stops"] = data.stops();
    }

    void to_json(nl::json& j, const TooltipContent& data) {
        serialize(j, data.content(), "content");
    }
}
