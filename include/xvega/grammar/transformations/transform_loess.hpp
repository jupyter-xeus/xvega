// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_LOESS_HPP
#define XVEGA_TRANSFORM_LOESS_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../transformations.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_loess : public transformation<transform_loess>
    {
        XPROPERTY(std::optional<std::string>, transform_loess, loess);
        XPROPERTY(std::optional<std::string>, transform_loess, on);
        XPROPERTY(std::optional<std::vector<std::string>>, transform_loess, groupby);
        XPROPERTY(std::optional<double>, transform_loess, bandwidth);
        XPROPERTY(std::optional<std::vector<std::string>>, transform_loess, as);
    };

    XVEGA_API void to_json(nl::json& j, const transform_loess& data);
}

#endif
