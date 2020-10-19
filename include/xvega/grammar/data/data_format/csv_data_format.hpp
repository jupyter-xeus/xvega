// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_CSV_DATA_FORMAT_HPP
#define XVEGA_CSV_DATA_FORMAT_HPP

#include "../data_format.hpp"

namespace xv
{
    struct csv_data_format : public data_format<csv_data_format>
    {
        using base_type = data_format<csv_data_format>;

        XVEGA_API csv_data_format();

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
