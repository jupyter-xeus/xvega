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
#include "../utils/serialize.hpp"

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
        XPROPERTY(xtl::xoptional<std::string>, D, name);
        XPROPERTY(xtl::xoptional<std::string>, D, type);
        XPROPERTY(xtl::xoptional<clear_type>, D, clear);
        XPROPERTY(xtl::xoptional<std::string>, D, empty);
        XPROPERTY(xtl::xoptional<on_type>, D, on);
        XPROPERTY(xtl::xoptional<std::string>, D, resolve);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, D, encodings);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, D, fields);
    
        void to_json(nl::json& j) const
        {
            // Fill in General Selection Properties
            serialize(j, type(), "type");
            serialize(j, clear(), "clear");
            serialize(j, empty(), "empty");
            serialize(j, on(), "on");
            serialize(j, resolve(), "resolve");
            serialize(j, encodings(), "encodings");
            serialize(j, fields(), "fields");
        }

    protected:

        selection() = default;
        ~selection() = default;

        selection(const selection&) = default;
        selection& operator=(const selection&) = default;

        selection(selection&&) = default;
        selection& operator=(selection&&) = default;
    };

    template<class D>
    void to_json(nl::json& j, const selection<D>& data)
    {
        data.derived_cast().to_json(j);
    }
}

#endif
