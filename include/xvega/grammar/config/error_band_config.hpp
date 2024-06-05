// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ERROR_BAND_CONFIG_HPP
#define XVEGA_ERROR_BAND_CONFIG_HPP

#include <optional>
#include <variant>

#include "./mark_config.hpp"

namespace xv
{
    using bool_mark_config_type = std::variant<mark_config, bool>;

    struct error_band_config : public xp::xobserved<error_band_config>
    {
        XPROPERTY(std::optional<bool_mark_config_type>, error_band_config, band);
        XPROPERTY(std::optional<bool_mark_config_type>, error_band_config, borders);
        XPROPERTY(std::optional<std::string>, error_band_config, extent);
        XPROPERTY(std::optional<std::string>, error_band_config, interpolate);
        XPROPERTY(std::optional<double>, error_band_config, tension);
    };

    XVEGA_API void to_json(nl::json& j, const error_band_config& data);
}

#endif
