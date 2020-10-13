// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SCALE_CONFIG_HPP
#define XVEGA_SCALE_CONFIG_HPP

#include "../../xvega_config.hpp"
#include "xproperty/xobserved.hpp"
#include "../../utils/xeither.hpp"
#include "../../utils/custom_datatypes.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    struct scale_config : public xp::xobserved<scale_config>
    {
        XPROPERTY(xtl::xoptional<double>, scale_config, bandPaddingInner);
        XPROPERTY(xtl::xoptional<double>, scale_config, bandPaddingOuter);
        XPROPERTY(xtl::xoptional<double>, scale_config, barBandPaddingInner);
        XPROPERTY(xtl::xoptional<bool>, scale_config, clamp);
        XPROPERTY(xtl::xoptional<double>, scale_config, continuousPadding);
        XPROPERTY(xtl::xoptional<double>, scale_config, maxBandSize);
        XPROPERTY(xtl::xoptional<double>, scale_config, maxFontSize);
        XPROPERTY(xtl::xoptional<double>, scale_config, maxOpacity);
        XPROPERTY(xtl::xoptional<double>, scale_config, maxSize);
        XPROPERTY(xtl::xoptional<double>, scale_config, maxStrokeWidth);
        XPROPERTY(xtl::xoptional<double>, scale_config, minBandSize);
        XPROPERTY(xtl::xoptional<double>, scale_config, minFontSize);
        XPROPERTY(xtl::xoptional<double>, scale_config, minOpacity);
        XPROPERTY(xtl::xoptional<double>, scale_config, minSize);
        XPROPERTY(xtl::xoptional<double>, scale_config, minStrokeWidth);
        XPROPERTY(xtl::xoptional<double>, scale_config, pointPadding);
        XPROPERTY(xtl::xoptional<double>, scale_config, quantileCount);
        XPROPERTY(xtl::xoptional<double>, scale_config, quantizeCount);
        XPROPERTY(xtl::xoptional<double>, scale_config, rectBandPaddingInner);
        XPROPERTY(xtl::xoptional<bool>, scale_config, round);
        XPROPERTY(xtl::xoptional<bool>, scale_config, useUnaggregatedDomain);
        XPROPERTY(xtl::xoptional<bool>, scale_config, xReverse);
    };

    XVEGA_API void to_json(nl::json& j, const scale_config& data);
}

#endif
