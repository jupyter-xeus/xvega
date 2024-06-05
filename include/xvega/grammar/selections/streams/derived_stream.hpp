// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_DERIVED_STREAM_HPP
#define XVEGA_DERIVED_STREAM_HPP

#include <optional>

#include "xproperty/xobserved.hpp"
#include "nlohmann/json.hpp"
#include "./event_stream.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct derived_stream : public xp::xobserved<derived_stream>
    {
        // Derived Stream Properties
        XPROPERTY(std::optional<event_stream>, derived_stream, stream);
        XPROPERTY(std::optional<std::vector<event_stream>>, derived_stream, between);
        XPROPERTY(std::optional<bool>, derived_stream, consume);
        XPROPERTY(std::optional<std::vector<std::string>>, derived_stream, filter);
        XPROPERTY(std::optional<double>, derived_stream, debounce);
        XPROPERTY(std::optional<std::string>, derived_stream, markname);
        XPROPERTY(std::optional<std::string>, derived_stream, marktype);
        XPROPERTY(std::optional<double>, derived_stream, throttle);
    };

    XVEGA_API void to_json(nl::json& j, const derived_stream& data);
}

#endif
