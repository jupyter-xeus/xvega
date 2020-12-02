// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/data/data_format/dsv_data_format.hpp"
#include "../data_format_private.hpp"

namespace xv
{
    dsv_data_format::dsv_data_format()
    {
        type = "dsv";
    }

    void to_json(nl::json& j, const dsv_data_format& c)
    {
        private_to_json(c, j);
        serialize(j, c.delimiter(), "delimiter");
    }
}
