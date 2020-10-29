// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_AUTO_SIZE_PARAMS_HPP
#define XVEGA_AUTO_SIZE_PARAMS_HPP

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    struct auto_size_params : public xp::xobserved<auto_size_params>
    {
        XPROPERTY(xtl::xoptional<std::string>, auto_size_params, contains);
        XPROPERTY(xtl::xoptional<bool>, auto_size_params, resize);
        XPROPERTY(xtl::xoptional<std::string>, auto_size_params, type);
    };

    XVEGA_API void to_json(nl::json& j, const auto_size_params& data);
}

#endif
