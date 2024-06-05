// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SELECTION_MARK_HPP
#define XVEGA_SELECTION_MARK_HPP

#include <optional>

#include "../../xvega_config.hpp"
#include "xproperty/xobserved.hpp"
#include "nlohmann/json.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct selection_mark : public xp::xobserved<selection_mark>
    {
        // Mark Selection Properties
        XPROPERTY(std::optional<std::string>, selection_mark, cursor);
        XPROPERTY(std::optional<std::string>, selection_mark, fill);
        XPROPERTY(std::optional<double>, selection_mark, fillOpacity);
        XPROPERTY(std::optional<std::string>, selection_mark, stroke);
        XPROPERTY(std::optional<double>, selection_mark, strokeOpacity);
        XPROPERTY(std::optional<double>, selection_mark, strokeWidth);
        XPROPERTY(std::optional<std::vector<double>>, selection_mark, strokeDash);
        XPROPERTY(std::optional<double>, selection_mark, strokeDashOffset);
    };

    XVEGA_API void to_json(nl::json& j, const selection_mark& data);
}

#endif
