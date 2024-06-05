// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SERIALIZE_HPP
#define XVEGA_SERIALIZE_HPP

#include "xvega/xvega_config.hpp"

#include "nlohmann/json.hpp"

#include "xjson.hpp"

namespace nl = nlohmann;

namespace xv
{
// Workaround for Windows as adl_serialize for variant
// is not found.
#ifdef _WIN32
    template <class... T>
    void serialize(nl::json& j, const std::optional<std::variant<T...>>& p, const std::string& name)
    {
        if (p.has_value())
        {
            std::visit([&](const auto& arg) { j[name] = arg; }, p.value());
        }
    }
#endif

    template <class T>
    void serialize(nl::json& j, const std::optional<T>& p, const std::string& name)
    {
        if(p.has_value())
        {
            j[name] = p.value();
        }
    }

    template <class P>
    void serialize(nl::json& j, const P& p, const std::string& name)
    {
        j[name] = p.value();
    }
}

#endif
