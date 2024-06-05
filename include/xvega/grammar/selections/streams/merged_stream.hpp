// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MERGED_STREAM_HPP
#define XVEGA_MERGED_STREAM_HPP

#include <optional>

#include "xproperty/xobserved.hpp"
#include "nlohmann/json.hpp"
#include "./event_stream.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct merged_stream : public xp::xobserved<merged_stream>
    {
        // Merged Stream Properties
        XPROPERTY(std::optional<std::vector<event_stream>>, merged_stream, merge);
        XPROPERTY(std::optional<std::vector<event_stream>>, merged_stream, between);
        XPROPERTY(std::optional<bool>, merged_stream, consume);
        XPROPERTY(std::optional<std::vector<std::string>>, merged_stream, filter);
        XPROPERTY(std::optional<double>, merged_stream, debounce);
        XPROPERTY(std::optional<std::string>, merged_stream, markname);
        XPROPERTY(std::optional<std::string>, merged_stream, marktype);
        XPROPERTY(std::optional<double>, merged_stream, throttle);
    };

    XVEGA_API void to_json(nl::json& j, const merged_stream& data);
}

#endif
