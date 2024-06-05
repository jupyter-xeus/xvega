// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SCALE_CONFIG_HPP
#define XVEGA_SCALE_CONFIG_HPP

#include <optional>

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"

namespace xv
{
    struct scale_config : public xp::xobserved<scale_config>
    {
        XPROPERTY(std::optional<double>, scale_config, bandPaddingInner);
        XPROPERTY(std::optional<double>, scale_config, bandPaddingOuter);
        XPROPERTY(std::optional<double>, scale_config, barBandPaddingInner);
        XPROPERTY(std::optional<bool>, scale_config, clamp);
        XPROPERTY(std::optional<double>, scale_config, continuousPadding);
        XPROPERTY(std::optional<double>, scale_config, maxBandSize);
        XPROPERTY(std::optional<double>, scale_config, maxFontSize);
        XPROPERTY(std::optional<double>, scale_config, maxOpacity);
        XPROPERTY(std::optional<double>, scale_config, maxSize);
        XPROPERTY(std::optional<double>, scale_config, maxStrokeWidth);
        XPROPERTY(std::optional<double>, scale_config, minBandSize);
        XPROPERTY(std::optional<double>, scale_config, minFontSize);
        XPROPERTY(std::optional<double>, scale_config, minOpacity);
        XPROPERTY(std::optional<double>, scale_config, minSize);
        XPROPERTY(std::optional<double>, scale_config, minStrokeWidth);
        XPROPERTY(std::optional<double>, scale_config, pointPadding);
        XPROPERTY(std::optional<double>, scale_config, quantileCount);
        XPROPERTY(std::optional<double>, scale_config, quantizeCount);
        XPROPERTY(std::optional<double>, scale_config, rectBandPaddingInner);
        XPROPERTY(std::optional<bool>, scale_config, round);
        XPROPERTY(std::optional<bool>, scale_config, useUnaggregatedDomain);
        XPROPERTY(std::optional<bool>, scale_config, xReverse);
    };

    XVEGA_API void to_json(nl::json& j, const scale_config& data);
}

#endif
