// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MERGED_STREAM_HPP
#define XVEGA_MERGED_STREAM_HPP

#include "xproperty/xobserved.hpp"
#include "xtl/xoptional.hpp"
#include "nlohmann/json.hpp"
#include "./event_stream.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct merged_stream : public xp::xobserved<merged_stream>
    {
        // Merged Stream Properties
        XPROPERTY(xtl::xoptional<std::vector<event_stream>>, merged_stream, merge);
        XPROPERTY(xtl::xoptional<std::vector<event_stream>>, merged_stream, between);
        XPROPERTY(xtl::xoptional<bool>, merged_stream, consume);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, merged_stream, filter);
        XPROPERTY(xtl::xoptional<double>, merged_stream, debounce);
        XPROPERTY(xtl::xoptional<std::string>, merged_stream, markname);
        XPROPERTY(xtl::xoptional<std::string>, merged_stream, marktype);
        XPROPERTY(xtl::xoptional<double>, merged_stream, throttle);
    };

    XVEGA_API void to_json(nl::json& j, const merged_stream& data);
}

#endif
