// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_AGGREGATE_HPP
#define XVEGA_ENCODING_OPTIONS_AGGREGATE_HPP

#include <optional>
#include <variant>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Aggregate : public xp::xobserved<Aggregate>
    {
        XPROPERTY(std::optional<std::string>, Aggregate, argmax);
        XPROPERTY(std::optional<std::string>, Aggregate, argmin);
    };

    XVEGA_API void to_json(nl::json&, const Aggregate&);

    using agg_type = std::variant<Aggregate, std::string>;
}

#endif
