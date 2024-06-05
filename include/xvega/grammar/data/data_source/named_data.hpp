// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_NAMED_DATA_HPP
#define XVEGA_NAMED_DATA_HPP

#include <optional>
#include <variant>

#include "../data_format/csv_data_format.hpp"
#include "../data_format/tsv_data_format.hpp"
#include "../data_format/dsv_data_format.hpp"
#include "../data_format/json_data_format.hpp"
#include "../data_format/topo_data_format.hpp"

namespace xv
{
    using data_format_type = std::variant<
                                  csv_data_format, 
                                  tsv_data_format, 
                                  dsv_data_format, 
                                  json_data_format, 
                                  topo_data_format
                                  >;

    struct named_data : public xp::xobserved<named_data>
    {
        XPROPERTY(std::optional<std::string>, named_data, name);
        XPROPERTY(std::optional<data_format_type>, named_data, format);
    };

    XVEGA_API void to_json(nl::json&, const named_data&);
}

#endif
