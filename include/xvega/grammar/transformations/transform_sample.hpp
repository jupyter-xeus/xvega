// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_SAMPLE_HPP
#define XVEGA_TRANSFORM_SAMPLE_HPP

#include <xproperty/xobserved.hpp>

#include <xtl/xoptional.hpp>
#include <xtl/xjson.hpp>

#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../transformations.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct transform_sample : public transformation<transform_sample>
    {
        XPROPERTY(xtl::xoptional<double>, transform_sample, sample);
    };

    XVEGA_API void to_json(nl::json& j, const transform_sample& data);
}

#endif