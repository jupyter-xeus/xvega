// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_STYLE_CONFIG_INDEX_HPP
#define XVEGA_STYLE_CONFIG_INDEX_HPP

#include "../../xvega_config.hpp"
#include "xproperty/xobserved.hpp"
#include "../../utils/xeither.hpp"
#include "../../utils/custom_datatypes.hpp"
#include "../../utils/serialize.hpp"

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
        XPROPERTY(xtl::xoptional<area_config>, style_config_index, area);
        XPROPERTY(xtl::xoptional<bar_config>, style_config_index, bar);
        XPROPERTY(xtl::xoptional<mark_config>, style_config_index, circle);
        XPROPERTY(xtl::xoptional<mark_config>, style_config_index, geoshape);
        XPROPERTY(xtl::xoptional<rect_config>, style_config_index, image);
        XPROPERTY(xtl::xoptional<line_config>, style_config_index, line);
        XPROPERTY(xtl::xoptional<mark_config>, style_config_index, mark);
        XPROPERTY(xtl::xoptional<mark_config>, style_config_index, point);
        XPROPERTY(xtl::xoptional<rect_config>, style_config_index, rect);
        XPROPERTY(xtl::xoptional<mark_config>, style_config_index, rule);
        XPROPERTY(xtl::xoptional<mark_config>, style_config_index, square);
        XPROPERTY(xtl::xoptional<mark_config>, style_config_index, text);
        XPROPERTY(xtl::xoptional<tick_config>, style_config_index, tick);
        XPROPERTY(xtl::xoptional<line_config>, style_config_index, trail);
        XPROPERTY(xtl::xoptional<mark_config>, style_config_index, group_subtitle); // actual name is group-subtitle
        XPROPERTY(xtl::xoptional<mark_config>, style_config_index, group_title); // actual name is group-title
        XPROPERTY(xtl::xoptional<mark_config>, style_config_index, guide_label); // actual name is guide-label
        XPROPERTY(xtl::xoptional<mark_config>, style_config_index, guide_title); // actual name is guide-title
    };

    XVEGA_API void to_json(nl::json& j, const style_config_index& data);
}

#endif
