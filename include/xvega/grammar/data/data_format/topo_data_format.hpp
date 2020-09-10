// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TOPO_DATA_FORMAT_HPP
#define XVEGA_TOPO_DATA_FORMAT_HPP

#include "../data_format.hpp"

namespace xv
{
    struct topo_data_format : public data_format<topo_data_format>
    {
        using base_type = data_format<topo_data_format>;

        XPROPERTY(xtl::xoptional<std::string>, topo_data_format, feature);
        XPROPERTY(xtl::xoptional<std::string>, topo_data_format, mesh);

        topo_data_format();

        void to_json(nl::json& j) const;
    };
}

#endif
