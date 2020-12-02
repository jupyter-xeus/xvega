// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_COMPOSITIONS_HPP
#define XVEGA_COMPOSITIONS_HPP

#include <xproperty/xobserved.hpp>
#include <xproperty/xproperty.hpp>

#include <nlohmann/json.hpp>

#include "../xvega_config.hpp"

#include "chart.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct hconcat : public xp::xobserved<hconcat>
    {
        XPROPERTY(std::vector<Chart>, hconcat, charts);
    };

    struct vconcat : public xp::xobserved<vconcat>
    {
        XPROPERTY(std::vector<Chart>, vconcat, charts);
    };

    struct layer : public xp::xobserved<layer>
    {
        XPROPERTY(std::vector<Chart>, layer, charts);
    };

    nl::json XVEGA_API mime_bundle_repr(const hconcat& v);

    nl::json XVEGA_API mime_bundle_repr(const layer& v);

    nl::json XVEGA_API mime_bundle_repr(const vconcat& v);
}

#endif
