// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/data/data_format/csv_data_format.hpp"

namespace xv
{
    csv_data_format::csv_data_format()
    {
        type = "csv";
    }

    void csv_data_format::to_json(nl::json& j) const
    {
        base_type::to_json(j);
    }
}