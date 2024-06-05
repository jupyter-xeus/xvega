// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SELECTION_CONFIG_HPP
#define XVEGA_SELECTION_CONFIG_HPP

#include <optional>
#include <variant>

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

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
    using stream_type = std::variant<event_stream, derived_stream, merged_stream>;
    using clear_type = std::variant<stream_type, std::string, bool>;
    using on_type = std::variant<stream_type, std::string>;

    struct interval_selection_config : public xp::xobserved<interval_selection_config>
    {
        XPROPERTY(std::optional<std::string>, interval_selection_config, bind);
        XPROPERTY(std::optional<clear_type>, interval_selection_config, clear);
        XPROPERTY(std::optional<std::string>, interval_selection_config, empty);
        XPROPERTY(std::optional<std::vector<std::string>>, interval_selection_config, encodings);
        XPROPERTY(std::optional<std::vector<std::string>>, interval_selection_config, fields);
        XPROPERTY(std::optional<nl::json>, interval_selection_config, init);
        XPROPERTY(std::optional<selection_mark>, interval_selection_config, mark);
        XPROPERTY(std::optional<on_type>, interval_selection_config, on);
        XPROPERTY(std::optional<std::string>, interval_selection_config, resolve);
        XPROPERTY(std::optional<bool_string_type>, interval_selection_config, translate);
        XPROPERTY(std::optional<bool_string_type>, interval_selection_config, zoom);
    };

    XVEGA_API void to_json(nl::json& j, const interval_selection_config& data);

    using legend_binding_type = std::variant<std::string, legend_stream_binding>;

    struct multi_selection_config : public xp::xobserved<multi_selection_config>
    {
        XPROPERTY(std::optional<legend_binding_type>, multi_selection_config, bind);
        XPROPERTY(std::optional<clear_type>, multi_selection_config, clear);
        XPROPERTY(std::optional<std::string>, multi_selection_config, empty);
        XPROPERTY(std::optional<std::vector<std::string>>, multi_selection_config, encodings);
        XPROPERTY(std::optional<std::vector<std::string>>, multi_selection_config, fields);
        XPROPERTY(std::optional<std::vector<nl::json>>, multi_selection_config, init);
        XPROPERTY(std::optional<bool>, multi_selection_config, nearest);
        XPROPERTY(std::optional<on_type>, multi_selection_config, on);
        XPROPERTY(std::optional<std::string>, multi_selection_config, resolve);
        XPROPERTY(std::optional<bool_string_type>, multi_selection_config, toggle);
    };

    XVEGA_API void to_json(nl::json& j, const multi_selection_config& data);

    using binding_type = std::variant<bind_checkbox, bind_radio_select, bind_range, bind_input>;
    using selection_bind_type = std::variant<binding_type, nl::json, legend_binding_type>;

    struct single_selection_config : public xp::xobserved<single_selection_config>
    {
        XPROPERTY(std::optional<selection_bind_type>, single_selection_config, bind);
        XPROPERTY(std::optional<clear_type>, single_selection_config, clear);
        XPROPERTY(std::optional<std::string>, single_selection_config, empty);
        XPROPERTY(std::optional<std::vector<std::string>>, single_selection_config, encodings);
        XPROPERTY(std::optional<std::vector<std::string>>, single_selection_config, fields);
        XPROPERTY(std::optional<nl::json>, single_selection_config, init);
        XPROPERTY(std::optional<bool>, single_selection_config, nearest);
        XPROPERTY(std::optional<on_type>, single_selection_config, on);
        XPROPERTY(std::optional<std::string>, single_selection_config, resolve);
    };

    XVEGA_API void to_json(nl::json& j, const single_selection_config& data);

    struct selection_config : public xp::xobserved<selection_config>
    {
        XPROPERTY(std::optional<interval_selection_config>, selection_config, interval);
        XPROPERTY(std::optional<multi_selection_config>, selection_config, multi);
        XPROPERTY(std::optional<single_selection_config>, selection_config, single);
    };

    XVEGA_API void to_json(nl::json& j, const selection_config& data);
}

#endif
