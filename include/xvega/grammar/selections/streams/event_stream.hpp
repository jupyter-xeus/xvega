// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_EVENT_STREAM_HPP
#define XVEGA_EVENT_STREAM_HPP

#include "xproperty/xobserved.hpp"
#include "xtl/xoptional.hpp"
#include "nlohmann/json.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct event_stream : public xp::xobserved<event_stream>
    {
        // Event Stream Properties
        XPROPERTY(xtl::xoptional<std::string>, event_stream, source);
        XPROPERTY(xtl::xoptional<std::string>, event_stream, type);
    };

    XVEGA_API void to_json(nl::json& j, const event_stream& data);
}

#endif
