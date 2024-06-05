// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SELECTION_SINGLE_HPP
#define XVEGA_SELECTION_SINGLE_HPP

#include <optional>
#include <variant>

#include "../selections.hpp"
#include "./bindings/legend_stream_binding.hpp"
#include "./bindings/bind_checkbox.hpp"
#include "./bindings/bind_input.hpp"
#include "./bindings/bind_radio_select.hpp"
#include "./bindings/bind_range.hpp"
#include "../../utils/random_string.hpp"

namespace xv
{
    using legend_binding_type = std::variant<std::string, legend_stream_binding>;
    using binding_type = std::variant<bind_checkbox, bind_radio_select, bind_range, bind_input>;
    using selection_bind_type = std::variant<binding_type, nl::json, legend_binding_type>;

    struct selection_single : public selection<selection_single>
    {
        // Single Selection Properties
        XPROPERTY(std::optional<nl::json>, selection_single, init);
        XPROPERTY(std::optional<nl::json>, selection_single, bind);
        XPROPERTY(std::optional<bool>, selection_single, nearest);

        XVEGA_API selection_single();

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
