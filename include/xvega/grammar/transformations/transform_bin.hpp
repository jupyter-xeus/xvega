// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_BIN_HPP
#define XVEGA_TRANSFORM_BIN_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../../utils/serialize.hpp"
#include "../encodings/encoding-channel-options/bin.hpp"

namespace nl = nlohmann;

namespace xv
{
    using bin_transform_type = xtl::variant<bool, Bin>;

    struct transform_bin : public xp::xobserved<transform_bin>
    {
        XPROPERTY(xtl::xoptional<bin_transform_type>, transform_bin, bin);
        XPROPERTY(xtl::xoptional<std::string>, transform_bin, field);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_bin, as);
    };

    XVEGA_API void to_json(nl::json& j, const transform_bin& data);
}

#endif