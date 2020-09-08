// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/base/xvega-base.hpp"

namespace xv
{
    const nl::json& base_vegalite_json()
    {
        static const nl::json json_template = {
            { "$schema", "https://vega.github.io/schema/vega-lite/v4.json" },
        };
        return json_template;
    };
}