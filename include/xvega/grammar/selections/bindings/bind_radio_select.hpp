// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_BIND_RADIO_SELECT_HPP
#define XVEGA_BIND_RADIO_SELECT_HPP

#include "xproperty/xobserved.hpp"
#include "xtl/xoptional.hpp"
#include "xtl/xvariant.hpp"
#include "nlohmann/json.hpp"
#include "../../../xvega_config.hpp"
#include "../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    using any_vector_type = std::vector<xtl::variant<std::string, double, int, bool, std::nullptr_t>>;

    struct bind_radio_select : public xp::xobserved<bind_radio_select>
    {
        // Bind Radio Select Properties
        XPROPERTY(xtl::xoptional<std::string>, bind_radio_select, input);
        XPROPERTY(xtl::xoptional<any_vector_type>, bind_radio_select, options);
        XPROPERTY(xtl::xoptional<double>, bind_radio_select, debounce);
        XPROPERTY(xtl::xoptional<std::string>, bind_radio_select, element);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, bind_radio_select, labels);
        XPROPERTY(xtl::xoptional<std::string>, bind_radio_select, name);
        XPROPERTY(xtl::xoptional<std::string>, bind_radio_select, type);
    };

    void to_json(nl::json& j, const bind_radio_select& data);
}

#endif
