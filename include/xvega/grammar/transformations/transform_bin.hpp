// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_BIN_HPP
#define XVEGA_TRANSFORM_BIN_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../transformations.hpp"
#include "../encodings/encoding-channel-options/bin.hpp"

namespace nl = nlohmann;

namespace xv
{
    // using bin_transform_type = std::variant<bool, Bin>;
    using bin_transform_type = nl::json;

    struct transform_bin : public transformation<transform_bin>
    {
        XPROPERTY(std::optional<bin_transform_type>, transform_bin, bin);
        XPROPERTY(std::optional<std::string>, transform_bin, field);
        XPROPERTY(std::optional<std::vector<std::string>>, transform_bin, as);
    };

    XVEGA_API void to_json(nl::json& j, const transform_bin& data);
}

#endif
