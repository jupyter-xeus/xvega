// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_LOESS_HPP
#define XVEGA_TRANSFORM_LOESS_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_loess : public xp::xobserved<transform_loess>
    {
        XPROPERTY(xtl::xoptional<std::string>, transform_loess, loess);
        XPROPERTY(xtl::xoptional<std::string>, transform_loess, on);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_loess, groupby);
        XPROPERTY(xtl::xoptional<double>, transform_loess, bandwidth);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_loess, as);
    };

    void to_json(nl::json& j, const transform_loess& data);
}

#endif