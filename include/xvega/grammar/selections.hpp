// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SELECTIONS_HPP
#define XVEGA_SELECTIONS_HPP

#include "xproperty/xobserved.hpp"

#include "../xvega_config.hpp"
#include "../utils/custom_datatypes.hpp"

#include "./selections/streams/event_stream.hpp"
#include "./selections/streams/derived_stream.hpp"
#include "./selections/streams/merged_stream.hpp"

namespace xv
{
    using stream_type = xtl::variant<event_stream, derived_stream, merged_stream>;
    using clear_type = xtl::variant<stream_type, std::string, bool>;
    using on_type = xtl::variant<stream_type, std::string>;

    template<class D>
    struct selection : public xp::xobserved<D>
    {
        XPROPERTY(std::string, D, name);
        XPROPERTY(xtl::xoptional<std::string>, D, type);
        XPROPERTY(xtl::xoptional<clear_type>, D, clear);
        XPROPERTY(xtl::xoptional<std::string>, D, empty);
        XPROPERTY(xtl::xoptional<on_type>, D, on);
        XPROPERTY(xtl::xoptional<std::string>, D, resolve);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, D, encodings);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, D, fields);
    };
}

#endif
