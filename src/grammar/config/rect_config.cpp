// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/rect_config.hpp"
#include "base_config_private.hpp"

namespace xv
{
    void to_json(nl::json& j, const rect_config& c)
    {
        private_to_json(c, j);

        serialize(j, c.binSpacing(), "binSpacing");
        serialize(j, c.continuousBandSize(), "continuousBandSize");
        serialize(j, c.discreteBandSize(), "discreteBandSize");
    }
}
