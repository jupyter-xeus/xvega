// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SELECTION_SINGLE_HPP
#define XVEGA_SELECTION_SINGLE_HPP

#include "../selections.hpp"
#include "./bindings/legend_stream_binding.hpp"
#include "./bindings/bind_checkbox.hpp"
#include "./bindings/bind_input.hpp"
#include "./bindings/bind_radio_select.hpp"
#include "./bindings/bind_range.hpp"
#include "../../utils/random_string.hpp"

namespace xv
{
    using legend_binding_type = xtl::variant<std::string, legend_stream_binding>;
    using binding_type = xtl::variant<bind_checkbox, bind_radio_select, bind_range, bind_input>;
    using selection_bind_type = xtl::variant<binding_type, nl::json, legend_binding_type>;

    struct selection_single : public selection<selection_single>
    {
        using base_type = selection<selection_single>;

        // Single Selection Properties
        XPROPERTY(xtl::xoptional<nl::json>, selection_single, init);
        XPROPERTY(xtl::xoptional<selection_bind_type>, selection_single, bind);
        XPROPERTY(xtl::xoptional<bool>, selection_single, nearest);

        selection_single()
        {
            if(!name().has_value())
            {
                name = "selector_single_" + random_string(5);
            }
            type = "single";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            serialize(j, init(), "init");
            serialize(j, bind(), "bind");
            serialize(j, nearest(), "nearest");
        }
    };
}

#endif
