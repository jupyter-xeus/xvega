// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/bar_config.hpp"

#include "base_config_private.hpp"

namespace xv
{
    void bar_config::to_json(nl::json& j) const
    {
        private_to_json(*this, j);

        serialize(j, binSpacing(), "binSpacing");
        serialize(j, continuousBandSize(), "continuousBandSize");
        serialize(j, cornerRadiusEnd(), "cornerRadiusEnd");
        serialize(j, discreteBandSize(), "discreteBandSize");
    }
}
