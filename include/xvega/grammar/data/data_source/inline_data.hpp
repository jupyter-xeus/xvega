// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_INLINE_DATA_HPP
#define XVEGA_INLINE_DATA_HPP

#include "../data_format/csv_data_format.hpp"
#include "../data_format/tsv_data_format.hpp"
#include "../data_format/dsv_data_format.hpp"
#include "../data_format/json_data_format.hpp"
#include "../data_format/topo_data_format.hpp"

namespace xv
{
    using data_format_type = xtl::variant<
                                  csv_data_format, 
                                  tsv_data_format, 
                                  dsv_data_format, 
                                  json_data_format, 
                                  topo_data_format
                                  >;

    using inline_data_type = xtl::variant<
                                  std::vector<std::string>,
                                  std::vector<int>, 
                                  std::vector<double>,
                                  std::vector<bool>,
                                  std::vector<nl::json>,
                                  std::string,
                                  nl::json
                                  >;

    struct inline_data : public xp::xobserved<inline_data>
    {
        XPROPERTY(inline_data_type, inline_data, values);
        XPROPERTY(xtl::xoptional<std::string>, inline_data, name);
        XPROPERTY(xtl::xoptional<data_format_type>, inline_data, format);
    };

    XVEGA_API void to_json(nl::json&, const inline_data&);
}

#endif
