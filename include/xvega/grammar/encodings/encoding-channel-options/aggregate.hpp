// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_AGGREGATE_HPP
#define XVEGA_ENCODING_OPTIONS_AGGREGATE_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../../xvega_config.hpp"
#include "../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Aggregate : public xp::xobserved<Aggregate>
    {
        XPROPERTY(xtl::xoptional<std::string>, Aggregate, argmax);
        XPROPERTY(xtl::xoptional<std::string>, Aggregate, argmin);
    };

    void to_json(nl::json& j, const Aggregate& data);

    using agg_type = xtl::variant<Aggregate, std::string>;
}

#endif