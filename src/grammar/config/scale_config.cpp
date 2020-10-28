// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/scale_config.hpp"

namespace xv
{
    void to_json(nl::json& j, const scale_config& data)
    {
        serialize(j, data.bandPaddingInner(), "bandPaddingInner");
        serialize(j, data.bandPaddingOuter(), "bandPaddingOuter");
        serialize(j, data.barBandPaddingInner(), "barBandPaddingInner");
        serialize(j, data.clamp(), "clamp");
        serialize(j, data.continuousPadding(), "continuousPadding");
        serialize(j, data.maxBandSize(), "maxBandSize");
        serialize(j, data.maxFontSize(), "maxFontSize");
        serialize(j, data.maxOpacity(), "maxOpacity");
        serialize(j, data.maxSize(), "maxSize");
        serialize(j, data.maxStrokeWidth(), "maxStrokeWidth");
        serialize(j, data.minBandSize(), "minBandSize");
        serialize(j, data.minFontSize(), "minFontSize");
        serialize(j, data.maxOpacity(), "maxOpacity");
        serialize(j, data.minSize(), "minSize");
        serialize(j, data.minStrokeWidth(), "minStrokeWidth");
        serialize(j, data.pointPadding(), "pointPadding");
        serialize(j, data.quantileCount(), "quantileCount");
        serialize(j, data.quantizeCount(), "quantizeCount");
        serialize(j, data.rectBandPaddingInner(), "rectBandPaddingInner");
        serialize(j, data.round(), "round");
        serialize(j, data.useUnaggregatedDomain(), "useUnaggregatedDomain");
        serialize(j, data.xReverse(), "xReverse");
    }
}
