// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SPHERE_GENERATOR_HPP
#define XVEGA_SPHERE_GENERATOR_HPP

#include "xproperty/xobserved.hpp"

#include "xtl/xoptional.hpp"
#include "xtl/xjson.hpp"

#include "nlohmann/json.hpp"

#include "../../../xvega_config.hpp"
#include "../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct sphere_generator : public xp::xobserved<sphere_generator>
    {
        XPROPERTY(xtl::xoptional<bool_object_type>, sphere_generator, sphere);
        XPROPERTY(xtl::xoptional<std::string>, sphere_generator, name);
    };

    XVEGA_API void to_json(nl::json& j, const sphere_generator& data);
}

#endif
