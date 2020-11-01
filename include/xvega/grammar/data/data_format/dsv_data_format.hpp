// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_DSV_DATA_FORMAT_HPP
#define XVEGA_DSV_DATA_FORMAT_HPP

#include "../data_format.hpp"

namespace xv
{
    struct dsv_data_format : public data_format<dsv_data_format>
    {
        XPROPERTY(xtl::xoptional<std::string>, dsv_data_format, delimiter);

        dsv_data_format();

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
