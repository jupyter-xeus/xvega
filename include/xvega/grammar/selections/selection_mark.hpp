// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SELECTION_MARK_HPP
#define XVEGA_SELECTION_MARK_HPP

#include "../../xvega_config.hpp"
#include "xproperty/xobserved.hpp"
#include "xtl/xoptional.hpp"
#include "nlohmann/json.hpp"
#include "../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct selection_mark : public xp::xobserved<selection_mark>
    {
        // Mark Selection Properties
        XPROPERTY(xtl::xoptional<std::string>, selection_mark, cursor);
        XPROPERTY(xtl::xoptional<std::string>, selection_mark, fill);
        XPROPERTY(xtl::xoptional<double>, selection_mark, fillOpacity);
        XPROPERTY(xtl::xoptional<std::string>, selection_mark, stroke);
        XPROPERTY(xtl::xoptional<double>, selection_mark, strokeOpacity);
        XPROPERTY(xtl::xoptional<double>, selection_mark, strokeWidth);
        XPROPERTY(xtl::xoptional<std::vector<double>>, selection_mark, strokeDash);
        XPROPERTY(xtl::xoptional<double>, selection_mark, strokeDashOffset);
    };

    void to_json(nl::json& j, const selection_mark& data);
}

#endif
