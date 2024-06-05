// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SELECTION_MULTI_HPP
#define XVEGA_SELECTION_MULTI_HPP

#include <optional>
#include <variant>

#include "../selections.hpp"
#include "./bindings/legend_stream_binding.hpp"
#include "../../utils/random_string.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    using legend_binding_type = std::variant<std::string, legend_stream_binding>;

    struct selection_multi : public selection<selection_multi>
    {
        // Multi Selection Properties
        XPROPERTY(std::optional<std::vector<nl::json>>, selection_multi, init);
        XPROPERTY(std::optional<legend_binding_type>, selection_multi, bind);
        XPROPERTY(std::optional<bool>, selection_multi, nearest);
        XPROPERTY(std::optional<bool_string_type>, selection_multi, toggle);

        XVEGA_API  selection_multi();

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
