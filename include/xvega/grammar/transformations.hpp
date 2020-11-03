// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORMATIONS_HPP
#define XVEGA_TRANSFORMATIONS_HPP

#include "xproperty/xobserved.hpp"

#include "../xvega_config.hpp"
#include "../utils/custom_datatypes.hpp"

namespace xv
{
    template<class D>
    struct transformation : public xp::xobserved<D>
    {
    };

    template<class D>
    void to_json(nl::json& j, const transformation<D>& data)
    {
        data.derived_cast().to_json(j);
    }
}

#endif
