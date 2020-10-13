// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_CONFIG_HPP
#define XVEGA_MARK_CONFIG_HPP

#include "./base_config.hpp"

namespace xv
{
    struct mark_config : public base_config<mark_config>
    {
        using base_type = base_config<mark_config>;

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
