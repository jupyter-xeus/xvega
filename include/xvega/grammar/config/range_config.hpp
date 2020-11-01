// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_RANGE_CONFIG_HPP
#define XVEGA_RANGE_CONFIG_HPP

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    using range_scheme_string_type = xtl::variant<std::string, std::vector<std::string>, nl::json, std::vector<any_type>>;

    struct range_config : public xp::xobserved<range_config>
    {
        XPROPERTY(xtl::xoptional<range_scheme_string_type>, range_config, category);
        XPROPERTY(xtl::xoptional<range_scheme_string_type>, range_config, diverging);
        XPROPERTY(xtl::xoptional<range_scheme_string_type>, range_config, heatmap);
        XPROPERTY(xtl::xoptional<range_scheme_string_type>, range_config, ordinal);
        XPROPERTY(xtl::xoptional<range_scheme_string_type>, range_config, ramp);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, range_config, symbol);
    };

    XVEGA_API void to_json(nl::json& j, const range_config& data);
}

#endif
