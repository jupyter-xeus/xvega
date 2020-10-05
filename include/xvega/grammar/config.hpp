// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_CONFIGURATIONS_HPP
#define XVEGA_CONFIGURATIONS_HPP

#include "../xvega_config.hpp"
#include "xproperty/xobserved.hpp"
#include "../utils/xeither.hpp"
#include "../utils/custom_datatypes.hpp"
#include "../utils/serialize.hpp"

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

namespace xv
{
    using autosize_type = xtl::variant<std::string, auto_size_params>;
    using num_object_type = xtl::variant<double, int, nl::json>;

    struct Config : public xp::xobserved<Config>
    {
        XPROPERTY(xtl::xoptional<area_config>, Config, area);
        XPROPERTY(xtl::xoptional<autosize_type>, Config, autosize);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axis);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisBand);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisBottom);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisDiscrete);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisLeft);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisPoint);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisQuantitative);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisRight);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisTemporal);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisTop);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisX);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisXBand);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisXDiscrete);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisXPoint);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisXQuantitative);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisXTemporal);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisY);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisYBand);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisYDiscrete);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisYPoint);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisYQuantitative);
        XPROPERTY(xtl::xoptional<axis_config>, Config, axisYTemporal);
        XPROPERTY(xtl::xoptional<std::string>, Config, background);
        XPROPERTY(xtl::xoptional<bar_config>, Config, bar);
        XPROPERTY(xtl::xoptional<box_plot_config>, Config, boxplot);
        XPROPERTY(xtl::xoptional<mark_config>, Config, circle);
        XPROPERTY(xtl::xoptional<composition_config>, Config, concat);
        XPROPERTY(xtl::xoptional<std::string>, Config, countTitle);
        XPROPERTY(xtl::xoptional<error_band_config>, Config, errorband);
        XPROPERTY(xtl::xoptional<error_bar_config>, Config, errorbar);
        XPROPERTY(xtl::xoptional<composition_config>, Config, facet);
        XPROPERTY(xtl::xoptional<std::string>, Config, fieldTitle);
        XPROPERTY(xtl::xoptional<std::string>, Config, font);
        XPROPERTY(xtl::xoptional<mark_config>, Config, geoshape);
        XPROPERTY(xtl::xoptional<header_config>, Config, header);
        XPROPERTY(xtl::xoptional<header_config>, Config, headerColumn);
        XPROPERTY(xtl::xoptional<header_config>, Config, headerFacet);
        XPROPERTY(xtl::xoptional<header_config>, Config, headerRow);
        XPROPERTY(xtl::xoptional<rect_config>, Config, image);
        XPROPERTY(xtl::xoptional<legend_config>, Config, legend);
        XPROPERTY(xtl::xoptional<line_config>, Config, line);
        XPROPERTY(xtl::xoptional<std::string>, Config, lineBreak);
        XPROPERTY(xtl::xoptional<mark_config>, Config, mark);
        XPROPERTY(xtl::xoptional<std::string>, Config, numberFormat);
        XPROPERTY(xtl::xoptional<num_object_type>, Config, padding);
        XPROPERTY(xtl::xoptional<mark_config>, Config, point);
        XPROPERTY(xtl::xoptional<projection_config>, Config, projection);
        XPROPERTY(xtl::xoptional<range_config>, Config, range);
        XPROPERTY(xtl::xoptional<rect_config>, Config, rect);
        XPROPERTY(xtl::xoptional<mark_config>, Config, rule);
        XPROPERTY(xtl::xoptional<scale_config>, Config, scale);
        XPROPERTY(xtl::xoptional<selection_config>, Config, selection);
        XPROPERTY(xtl::xoptional<mark_config>, Config, square);
        XPROPERTY(xtl::xoptional<style_config_index>, Config, style);
        XPROPERTY(xtl::xoptional<mark_config>, Config, text);
        XPROPERTY(xtl::xoptional<tick_config>, Config, tick);
        XPROPERTY(xtl::xoptional<std::string>, Config, timeFormat);
        XPROPERTY(xtl::xoptional<title_config>, Config, title);
        XPROPERTY(xtl::xoptional<line_config>, Config, trail);
        XPROPERTY(xtl::xoptional<view_config>, Config, view);
    };

    void to_json(nl::json& j, const Config& data);
}

#endif
