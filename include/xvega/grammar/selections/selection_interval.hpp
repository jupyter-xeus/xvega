// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SELECTION_INTERVAL_HPP
#define XVEGA_SELECTION_INTERVAL_HPP

#include <optional>

#include "../selections.hpp"
#include "./selection_mark.hpp"
#include "../../utils/random_string.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    struct selection_interval : public selection<selection_interval>
    {
        // Interval Selection Properties
        XPROPERTY(std::optional<std::string>, selection_interval, bind);
        XPROPERTY(std::optional<nl::json>, selection_interval, init);
        XPROPERTY(std::optional<selection_mark>, selection_interval, mark);
        XPROPERTY(std::optional<bool_string_type>, selection_interval, translate);
        XPROPERTY(std::optional<bool_string_type>, selection_interval, zoom);

        XVEGA_API selection_interval();
    };

    XVEGA_API void to_json(nl::json&, const selection_interval&);
}

#endif
