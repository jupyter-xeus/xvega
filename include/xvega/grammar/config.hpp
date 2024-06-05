// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_CONFIGURATIONS_HPP
#define XVEGA_CONFIGURATIONS_HPP

#include <optional>
#include <variant>

#include "xproperty/xobserved.hpp"

#include "../xvega_config.hpp"
#include "../utils/custom_datatypes.hpp"

#include "./config/area_config.hpp"
#include "./config/auto_size_params.hpp"
#include "./config/axis_config.hpp"
#include "./config/bar_config.hpp"
#include "./config/box_plot_config.hpp"
#include "./config/mark_config.hpp"
#include "./config/composition_config.hpp"
#include "./config/error_band_config.hpp"
#include "./config/error_bar_config.hpp"
#include "./config/header_config.hpp"
#include "./config/rect_config.hpp"
#include "./config/legend_config.hpp"
#include "./config/line_config.hpp"
#include "./config/projection_config.hpp"
#include "./config/range_config.hpp"
#include "./config/scale_config.hpp"
#include "./config/selection_config.hpp"
#include "./config/style_config_index.hpp"
#include "./config/tick_config.hpp"
#include "./config/title_config.hpp"
#include "./config/view_config.hpp"
#include "../utils/custom_datatypes.hpp"

namespace xv
{
    using autosize_type = std::variant<std::string, auto_size_params>;

    struct Config : public xp::xobserved<Config>
    {
        XPROPERTY(std::optional<area_config>, Config, area);
        XPROPERTY(std::optional<autosize_type>, Config, autosize);
        XPROPERTY(std::optional<axis_config>, Config, axis);
        XPROPERTY(std::optional<axis_config>, Config, axisBand);
        XPROPERTY(std::optional<axis_config>, Config, axisBottom);
        XPROPERTY(std::optional<axis_config>, Config, axisDiscrete);
        XPROPERTY(std::optional<axis_config>, Config, axisLeft);
        XPROPERTY(std::optional<axis_config>, Config, axisPoint);
        XPROPERTY(std::optional<axis_config>, Config, axisQuantitative);
        XPROPERTY(std::optional<axis_config>, Config, axisRight);
        XPROPERTY(std::optional<axis_config>, Config, axisTemporal);
        XPROPERTY(std::optional<axis_config>, Config, axisTop);
        XPROPERTY(std::optional<axis_config>, Config, axisX);
        XPROPERTY(std::optional<axis_config>, Config, axisXBand);
        XPROPERTY(std::optional<axis_config>, Config, axisXDiscrete);
        XPROPERTY(std::optional<axis_config>, Config, axisXPoint);
        XPROPERTY(std::optional<axis_config>, Config, axisXQuantitative);
        XPROPERTY(std::optional<axis_config>, Config, axisXTemporal);
        XPROPERTY(std::optional<axis_config>, Config, axisY);
        XPROPERTY(std::optional<axis_config>, Config, axisYBand);
        XPROPERTY(std::optional<axis_config>, Config, axisYDiscrete);
        XPROPERTY(std::optional<axis_config>, Config, axisYPoint);
        XPROPERTY(std::optional<axis_config>, Config, axisYQuantitative);
        XPROPERTY(std::optional<axis_config>, Config, axisYTemporal);
        XPROPERTY(std::optional<std::string>, Config, background);
        XPROPERTY(std::optional<bar_config>, Config, bar);
        XPROPERTY(std::optional<box_plot_config>, Config, boxplot);
        XPROPERTY(std::optional<mark_config>, Config, circle);
        XPROPERTY(std::optional<composition_config>, Config, concat);
        XPROPERTY(std::optional<std::string>, Config, countTitle);
        XPROPERTY(std::optional<error_band_config>, Config, errorband);
        XPROPERTY(std::optional<error_bar_config>, Config, errorbar);
        XPROPERTY(std::optional<composition_config>, Config, facet);
        XPROPERTY(std::optional<std::string>, Config, fieldTitle);
        XPROPERTY(std::optional<std::string>, Config, font);
        XPROPERTY(std::optional<mark_config>, Config, geoshape);
        XPROPERTY(std::optional<header_config>, Config, header);
        XPROPERTY(std::optional<header_config>, Config, headerColumn);
        XPROPERTY(std::optional<header_config>, Config, headerFacet);
        XPROPERTY(std::optional<header_config>, Config, headerRow);
        XPROPERTY(std::optional<rect_config>, Config, image);
        XPROPERTY(std::optional<legend_config>, Config, legend);
        XPROPERTY(std::optional<line_config>, Config, line);
        XPROPERTY(std::optional<std::string>, Config, lineBreak);
        XPROPERTY(std::optional<mark_config>, Config, mark);
        XPROPERTY(std::optional<std::string>, Config, numberFormat);
        XPROPERTY(std::optional<num_object_type>, Config, padding);
        XPROPERTY(std::optional<mark_config>, Config, point);
        XPROPERTY(std::optional<projection_config>, Config, projection);
        XPROPERTY(std::optional<range_config>, Config, range);
        XPROPERTY(std::optional<rect_config>, Config, rect);
        XPROPERTY(std::optional<mark_config>, Config, rule);
        XPROPERTY(std::optional<scale_config>, Config, scale);
        XPROPERTY(std::optional<selection_config>, Config, selection);
        XPROPERTY(std::optional<mark_config>, Config, square);
        XPROPERTY(std::optional<style_config_index>, Config, style);
        XPROPERTY(std::optional<mark_config>, Config, text);
        XPROPERTY(std::optional<tick_config>, Config, tick);
        XPROPERTY(std::optional<std::string>, Config, timeFormat);
        XPROPERTY(std::optional<title_config>, Config, title);
        XPROPERTY(std::optional<line_config>, Config, trail);
        XPROPERTY(std::optional<view_config>, Config, view);
    };

    XVEGA_API void to_json(nl::json& j, const Config& data);
}

#endif
