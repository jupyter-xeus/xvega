// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_JSON_DATA_FORMAT_HPP
#define XVEGA_JSON_DATA_FORMAT_HPP

#include <optional>

#include "../data_format.hpp"

namespace xv
{
    struct json_data_format : public data_format<json_data_format>
    {
        XPROPERTY(std::optional<std::string>, json_data_format, property);

        json_data_format();
    };

    XVEGA_API void to_json(nl::json&, const json_data_format&);
}

#endif
