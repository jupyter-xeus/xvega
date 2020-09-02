// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_TRANSFORM_WINDOW_HPP
#define XVEGA_TRANSFORM_WINDOW_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../xvega_config.hpp"
#include "../../utils/serialize.hpp"
#include "./transform_stack.hpp"

namespace nl = nlohmann;

namespace xv
{
    using num_none_type = xtl::variant<std::nullptr_t, double, int>;

    struct window_field_def : public xp::xobserved<window_field_def>
    {
        XPROPERTY(xtl::xoptional<std::string>, window_field_def, op);
        XPROPERTY(xtl::xoptional<std::string>, window_field_def, field);
        XPROPERTY(xtl::xoptional<double>, window_field_def, param);
        XPROPERTY(xtl::xoptional<std::string>, window_field_def, as);
    };

    void to_json(nl::json& j, const window_field_def& data);

    struct transform_window : public xp::xobserved<transform_window>
    {
        XPROPERTY(xtl::xoptional<std::vector<window_field_def>>, transform_window, window);
        XPROPERTY(xtl::xoptional<std::vector<num_none_type>>, transform_window, frame);
        XPROPERTY(xtl::xoptional<bool>, transform_window, ignorePeers);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, transform_window, groupby);
        XPROPERTY(xtl::xoptional<std::vector<sort_field_def>>, transform_window, sort);
    };

    void to_json(nl::json& j, const transform_window& data);
}

#endif