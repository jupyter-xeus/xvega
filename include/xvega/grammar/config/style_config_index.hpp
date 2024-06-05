// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_STYLE_CONFIG_INDEX_HPP
#define XVEGA_STYLE_CONFIG_INDEX_HPP

#include <optional>

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

#include "./area_config.hpp"
#include "./bar_config.hpp"
#include "./mark_config.hpp"
#include "./rect_config.hpp"
#include "./line_config.hpp"
#include "./tick_config.hpp"

namespace xv
{
    struct style_config_index : public xp::xobserved<style_config_index>
    {
        XPROPERTY(std::optional<area_config>, style_config_index, area);
        XPROPERTY(std::optional<bar_config>, style_config_index, bar);
        XPROPERTY(std::optional<mark_config>, style_config_index, circle);
        XPROPERTY(std::optional<mark_config>, style_config_index, geoshape);
        XPROPERTY(std::optional<rect_config>, style_config_index, image);
        XPROPERTY(std::optional<line_config>, style_config_index, line);
        XPROPERTY(std::optional<mark_config>, style_config_index, mark);
        XPROPERTY(std::optional<mark_config>, style_config_index, point);
        XPROPERTY(std::optional<rect_config>, style_config_index, rect);
        XPROPERTY(std::optional<mark_config>, style_config_index, rule);
        XPROPERTY(std::optional<mark_config>, style_config_index, square);
        XPROPERTY(std::optional<mark_config>, style_config_index, text);
        XPROPERTY(std::optional<tick_config>, style_config_index, tick);
        XPROPERTY(std::optional<line_config>, style_config_index, trail);
        XPROPERTY(std::optional<mark_config>, style_config_index, group_subtitle); // actual name is group-subtitle
        XPROPERTY(std::optional<mark_config>, style_config_index, group_title); // actual name is group-title
        XPROPERTY(std::optional<mark_config>, style_config_index, guide_label); // actual name is guide-label
        XPROPERTY(std::optional<mark_config>, style_config_index, guide_title); // actual name is guide-title
    };

    XVEGA_API void to_json(nl::json& j, const style_config_index& data);
}

#endif
