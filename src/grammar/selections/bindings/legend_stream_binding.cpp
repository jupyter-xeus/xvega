// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/selections/bindings/legend_stream_binding.hpp"
#include "../../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const legend_stream_binding& data)
    {
        if(data.legend().has_value())
        {
            std::visit([&](auto&& arg){j["legend"]=arg;}, data.legend().value());
        }
    }
}
