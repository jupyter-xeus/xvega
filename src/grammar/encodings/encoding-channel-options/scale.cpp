// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/encodings/encoding-channel-options/scale.hpp"
#include "../../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const DomainUnionWith& data)
    {
        serialize(j, data.unionWith(), "unionWith");
    }

    void to_json(nl::json& j, const ScaleBin& data)
    {
        serialize(j, data.start(), "start");
        serialize(j, data.stop(), "stop");
        serialize(j, data.step(), "step");
    }

    void to_json(nl::json& j, const Scheme& data)
    {
        serialize(j, data.name(), "name");
        serialize(j, data.extent(), "extent");
        serialize(j, data.count(), "count");
    }

    void to_json(nl::json& j, const ScaleInterpolate& data)
    {
        serialize(j, data.type(), "type");
        serialize(j, data.gamma(), "gamma");
    }

    void to_json(nl::json& j, const TimeIntervalStep& data)
    {
        serialize(j, data.interval(), "interval");
        serialize(j, data.step(), "step");
    }

    void to_json(nl::json& j, const Scale& data)
    {
        serialize(j, data.type(), "type");
        serialize(j, data.domain(), "domain");
        serialize(j, data.domainMax(), "domainMax");
        serialize(j, data.domainMin(), "domainMin");
        serialize(j, data.domainMid(), "domainMid");
        serialize(j, data.range(), "range");
        serialize(j, data.rangeMin(), "rangeMin");
        serialize(j, data.rangeMax(), "rangeMax");
        serialize(j, data.scheme(), "scheme");
        serialize(j, data.reverse(), "reverse");
        serialize(j, data.round(), "round");
        serialize(j, data.clamp(), "clamp");
        serialize(j, data.interpolate(), "interpolate");
        serialize(j, data.nice(), "nice");
        serialize(j, data.padding(), "padding");
        serialize(j, data.zero(), "zero");
        serialize(j, data.exponent(), "exponent");
        serialize(j, data.base(), "base");
        serialize(j, data.constant(), "constant");
        serialize(j, data.align(), "align");
        serialize(j, data.paddingInner(), "paddingInner");
        serialize(j, data.paddingOuter(), "paddingOuter");
        serialize(j, data.bins(), "bins");
    }
}