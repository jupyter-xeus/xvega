// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SELECTION_CONFIG_HPP
#define XVEGA_SELECTION_CONFIG_HPP

#include "../../xvega_config.hpp"
#include "xproperty/xobserved.hpp"
#include "../../utils/xeither.hpp"
#include "../../utils/custom_datatypes.hpp"
#include "../../utils/serialize.hpp"

#include "../selections/streams/event_stream.hpp"
#include "../selections/streams/derived_stream.hpp"
#include "../selections/streams/merged_stream.hpp"
#include "../selections/selection_mark.hpp"

#include "../selections/bindings/legend_stream_binding.hpp"

#include "../selections/bindings/bind_checkbox.hpp"
#include "../selections/bindings/bind_input.hpp"
#include "../selections/bindings/bind_radio_select.hpp"
#include "../selections/bindings/bind_range.hpp"

namespace xv
{
    using stream_type = xtl::variant<event_stream, derived_stream, merged_stream>;
    using clear_type = xtl::variant<stream_type, std::string, bool>;
    using on_type = xtl::variant<stream_type, std::string>;
    using bool_string_type = xtl::variant<std::string, bool>;

    struct interval_selection_config : public xp::xobserved<interval_selection_config>
    {
        XPROPERTY(xtl::xoptional<std::string>, interval_selection_config, bind);
        XPROPERTY(xtl::xoptional<clear_type>, interval_selection_config, clear);
        XPROPERTY(xtl::xoptional<std::string>, interval_selection_config, empty);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, interval_selection_config, encodings);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, interval_selection_config, fields);
        XPROPERTY(xtl::xoptional<nl::json>, interval_selection_config, init);
        XPROPERTY(xtl::xoptional<selection_mark>, interval_selection_config, mark);
        XPROPERTY(xtl::xoptional<on_type>, interval_selection_config, on);
        XPROPERTY(xtl::xoptional<std::string>, interval_selection_config, resolve);
        XPROPERTY(xtl::xoptional<bool_string_type>, interval_selection_config, translate);
        XPROPERTY(xtl::xoptional<bool_string_type>, interval_selection_config, zoom);
    };

    void to_json(nl::json& j, const interval_selection_config& data);

    using legend_binding_type = xtl::variant<std::string, legend_stream_binding>;

    struct multi_selection_config : public xp::xobserved<multi_selection_config>
    {
        XPROPERTY(xtl::xoptional<legend_binding_type>, multi_selection_config, bind);
        XPROPERTY(xtl::xoptional<clear_type>, multi_selection_config, clear);
        XPROPERTY(xtl::xoptional<std::string>, multi_selection_config, empty);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, multi_selection_config, encodings);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, multi_selection_config, fields);
        XPROPERTY(xtl::xoptional<std::vector<nl::json>>, multi_selection_config, init);
        XPROPERTY(xtl::xoptional<bool>, multi_selection_config, nearest);
        XPROPERTY(xtl::xoptional<on_type>, multi_selection_config, on);
        XPROPERTY(xtl::xoptional<std::string>, multi_selection_config, resolve);
        XPROPERTY(xtl::xoptional<bool_string_type>, multi_selection_config, toggle);
    };

    void to_json(nl::json& j, const multi_selection_config& data);

    using binding_type = xtl::variant<bind_checkbox, bind_radio_select, bind_range, bind_input>;
    using selection_bind_type = xtl::variant<binding_type, nl::json, legend_binding_type>;

    struct single_selection_config : public xp::xobserved<single_selection_config>
    {
        XPROPERTY(xtl::xoptional<selection_bind_type>, single_selection_config, bind);
        XPROPERTY(xtl::xoptional<clear_type>, single_selection_config, clear);
        XPROPERTY(xtl::xoptional<std::string>, single_selection_config, empty);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, single_selection_config, encodings);
        XPROPERTY(xtl::xoptional<std::vector<std::string>>, single_selection_config, fields);
        XPROPERTY(xtl::xoptional<nl::json>, single_selection_config, init);
        XPROPERTY(xtl::xoptional<bool>, single_selection_config, nearest);
        XPROPERTY(xtl::xoptional<on_type>, single_selection_config, on);
        XPROPERTY(xtl::xoptional<std::string>, single_selection_config, resolve);
    };

    void to_json(nl::json& j, const single_selection_config& data);

    struct selection_config : public xp::xobserved<selection_config>
    {
        XPROPERTY(xtl::xoptional<interval_selection_config>, selection_config, interval);
        XPROPERTY(xtl::xoptional<multi_selection_config>, selection_config, multi);
        XPROPERTY(xtl::xoptional<single_selection_config>, selection_config, single);
    };

    void to_json(nl::json& j, const selection_config& data);
}

#endif
