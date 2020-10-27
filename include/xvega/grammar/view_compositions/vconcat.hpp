// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/base/xvega-base.hpp"
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
    struct vconcat : public xp::xobserved<vconcat>
    {
        XPROPERTY(std::vector<Chart>, vconcat, charts);
    };

    XVEGA_API void to_json(nl::json& j, const vconcat& data);
}