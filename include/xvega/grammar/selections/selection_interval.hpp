// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SELECTION_INTERVAL_HPP
#define XVEGA_SELECTION_INTERVAL_HPP

#include "../selections.hpp"
#include "./selection_mark.hpp"
#include "../../utils/random_string.hpp"

namespace xv
{
    using bool_string_type = xtl::variant<std::string, bool>;

    struct selection_interval : public selection<selection_interval>
    {
        using base_type = selection<selection_interval>;

        // Interval Selection Properties
        XPROPERTY(xtl::xoptional<std::string>, selection_interval, bind);
        XPROPERTY(xtl::xoptional<nl::json>, selection_interval, init);
        XPROPERTY(xtl::xoptional<selection_mark>, selection_interval, mark);
        XPROPERTY(xtl::xoptional<bool_string_type>, selection_interval, translate);
        XPROPERTY(xtl::xoptional<bool_string_type>, selection_interval, zoom);

        selection_interval()
        {
            if(!name().has_value())
            {
                name = "selector_interval_" + random_string(5);
            }
            type = "interval";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            serialize(j, bind(), "bind");
            serialize(j, init(), "init");
            serialize(j, mark(), "mark");
            serialize(j, translate(), "translate");
            serialize(j, zoom(), "zoom");
        }
    };
}

#endif
