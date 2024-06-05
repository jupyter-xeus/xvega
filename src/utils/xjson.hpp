// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_JSON_HPP
#define XVEGA_JSON_HPP

#include <optional>
#include <variant>

#include <nlohmann/json.hpp>

namespace nlohmann
{
    template <class T>
    struct adl_serializer<std::optional<T>>
    {
        static void to_json(json& j, const std::optional<T>& o)
        {
            if (o.has_value())
            {
                j = o.value();
            }
            else
            {
                j = nullptr;
            }
        }
    };

    template <class... T>
    struct adl_serializer<std::variant<T...>>
    {
        static void to_json(json& j, const std::variant<T...>& v)
        {
            std::visit([&j](const auto& arg) { j = arg; }, v);
        }
    };
}

#endif
