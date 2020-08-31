// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_LEGEND_STREAM_BINDING_HPP
#define XVEGA_LEGEND_STREAM_BINDING_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <nlohmann/json.hpp>

#include "../../../utils/serialize.hpp"
#include "../streams/event_stream.hpp"
#include "../streams/derived_stream.hpp"
#include "../streams/merged_stream.hpp"

namespace nl = nlohmann;

namespace xv
{
    using stream_type = xtl::variant<event_stream, derived_stream, merged_stream>;
    using stream_legend_type = xtl::variant<std::string, stream_type>;

    struct legend_stream_binding : public xp::xobserved<legend_stream_binding>
    {
        // Legend Stream Binding Properties
        XPROPERTY(xtl::xoptional<stream_legend_type>, legend_stream_binding, legend);
    };

    void to_json(nl::json& j, const legend_stream_binding& data)
    {
        serialize(j, data.legend(), "legend");
    }
}

#endif
