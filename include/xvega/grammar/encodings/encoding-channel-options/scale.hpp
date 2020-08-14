// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_SCALE_HPP
#define XVEGA_ENCODING_OPTIONS_SCALE_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "./datetime.hpp"

namespace nl = nlohmann;

namespace xv
{

    using anyArrayType = xtl::variant<std::vector<std::string>, std::vector<double>, std::vector<int>, std::vector<bool>, std::vector<DateTime>>;
    using numDatetimeType = xtl::variant<double, int, DateTime>;
    using stringNumType = xtl::variant<double, int, std::string>;
    using scaleRangeType = xtl::variant<std::string, std::vector<double>, std::vector<int>, std::vector<std::string>, nl::json>;

    struct DomainUnionWith : public xp::xobserved<DomainUnionWith>
    {
        XPROPERTY(xtl::xoptional<anyArrayType>, DomainUnionWith, unionWith);
    };

    void to_json(nl::json& j, const DomainUnionWith& data)
    {
        if(data.unionWith().has_value())
        {
            j["unionWith"] = data.unionWith().value();
        }
    };

    using scaleDomainType = xtl::variant<anyArrayType, std::string, nl::json, DomainUnionWith>;

    struct ScaleBin : public xp::xobserved<ScaleBin>
    {
        XPROPERTY(xtl::xoptional<double>, ScaleBin, start);
        XPROPERTY(xtl::xoptional<double>, ScaleBin, stop);
        XPROPERTY(xtl::xoptional<double>, ScaleBin, step);
    };

    void to_json(nl::json& j, const ScaleBin& data)
    {
        if(data.start().has_value())
        {
            j["start"] = data.start().value();
        }
        if(data.stop().has_value())
        {
            j["stop"] = data.stop().value();
        }
        if(data.step().has_value())
        {
            j["step"] = data.step().value();
        }
    }

    using scaleBinType = xtl::variant<std::vector<double>, std::vector<int>, ScaleBin>;

    struct Scheme : public xp::xobserved<Scheme>
    {
        XPROPERTY(xtl::xoptional<std::string>, Scheme, name);
        XPROPERTY(xtl::xoptional<std::vector<double>>, Scheme, extent);
        XPROPERTY(xtl::xoptional<double>, Scheme, count);
    };

    void to_json(nl::json& j, const Scheme& data)
    {
        if(data.name().has_value())
        {
            j["name"] = data.name().value();
        }
        if(data.extent().has_value())
        {
            j["extent"] = data.extent().value();
        }
        if(data.count().has_value())
        {
            j["count"] = data.count().value();
        }
    }

    using scaleSchemeType = xtl::variant<std::string, Scheme>;

    struct ScaleInterpolate : public xp::xobserved<ScaleInterpolate>
    {
        XPROPERTY(xtl::xoptional<std::string>, ScaleInterpolate, type);
        XPROPERTY(xtl::xoptional<double>, ScaleInterpolate, gamma);
    };

    void to_json(nl::json& j, const ScaleInterpolate& data)
    {
        if(data.type().has_value())
        {
            j["type"] = data.type().value();
        }
        if(data.gamma().has_value())
        {
            j["gamma"] = data.gamma().value();
        }
    }

    using scaleInterpolateType = xtl::variant<std::string, ScaleInterpolate>;

    struct TimeIntervalStep : public xp::xobserved<TimeIntervalStep>
    {
        XPROPERTY(xtl::xoptional<std::string>, TimeIntervalStep, interval);
        XPROPERTY(xtl::xoptional<double>, TimeIntervalStep, step);
    };

    void to_json(nl::json& j, const TimeIntervalStep& data)
    {
        if(data.interval().has_value())
        {
            j["interval"] = data.interval().value();
        }
        if(data.step().has_value())
        {
            j["step"] = data.step().value();
        }
    }

    using niceType = xtl::variant<double, int, std::string, bool, TimeIntervalStep>;

    struct Scale : public xp::xobserved<Scale>
    {
        XPROPERTY(xtl::xoptional<std::string>, Scale, type);
        XPROPERTY(xtl::xoptional<scaleDomainType>, Scale, domain);
        XPROPERTY(xtl::xoptional<numDatetimeType>, Scale, domainMax);
        XPROPERTY(xtl::xoptional<numDatetimeType>, Scale, domainMin);
        XPROPERTY(xtl::xoptional<double>, Scale, domainMid);
        XPROPERTY(xtl::xoptional<scaleRangeType>, Scale, range);
        XPROPERTY(xtl::xoptional<stringNumType>, Scale, rangeMin);
        XPROPERTY(xtl::xoptional<stringNumType>, Scale, rangeMax);
        XPROPERTY(xtl::xoptional<scaleSchemeType>, Scale, scheme);
        XPROPERTY(xtl::xoptional<bool>, Scale, reverse);
        XPROPERTY(xtl::xoptional<bool>, Scale, round);
        XPROPERTY(xtl::xoptional<bool>, Scale, clamp);
        XPROPERTY(xtl::xoptional<scaleInterpolateType>, Scale, interpolate);
        XPROPERTY(xtl::xoptional<niceType>, Scale, nice);
        XPROPERTY(xtl::xoptional<double>, Scale, padding);
        XPROPERTY(xtl::xoptional<bool>, Scale, zero);
        XPROPERTY(xtl::xoptional<double>, Scale, exponent);
        XPROPERTY(xtl::xoptional<double>, Scale, base);
        XPROPERTY(xtl::xoptional<double>, Scale, constant);
        XPROPERTY(xtl::xoptional<double>, Scale, align);
        XPROPERTY(xtl::xoptional<double>, Scale, paddingInner);
        XPROPERTY(xtl::xoptional<double>, Scale, paddingOuter);
        XPROPERTY(xtl::xoptional<scaleBinType>, Scale, bins);
    };

    void to_json(nl::json& j, const Scale& data)
    {
        if(data.type().has_value())
        {
            j["type"] = data.type().value();
        }
        if(data.domain().has_value())
        {
            j["domain"] = data.domain().value();
        }
        if(data.domainMax().has_value())
        {
            j["domainMax"] = data.domainMax().value();
        }
        if(data.domainMin().has_value())
        {
            j["domainMin"] = data.domainMin().value();
        }
        if(data.domainMid().has_value())
        {
            j["domainMid"] = data.domainMid().value();
        }
        if(data.range().has_value())
        {
            j["range"] = data.range().value();
        }
        if(data.rangeMin().has_value())
        {
            j["rangeMin"] = data.rangeMin().value();
        }
        if(data.rangeMax().has_value())
        {
            j["rangeMax"] = data.rangeMax().value();
        }
        if(data.scheme().has_value())
        {
            j["scheme"] = data.scheme().value();
        }
        if(data.reverse().has_value())
        {
            j["reverse"] = data.reverse().value();
        }
        if(data.round().has_value())
        {
            j["round"] = data.round().value();
        }
        if(data.clamp().has_value())
        {
            j["clamp"] = data.clamp().value();
        }
        if(data.interpolate().has_value())
        {
            j["interpolate"] = data.interpolate().value();
        }
        if(data.nice().has_value())
        {
            j["nice"] = data.nice().value();
        }
        if(data.padding().has_value())
        {
            j["padding"] = data.padding().value();
        }
        if(data.zero().has_value())
        {
            j["zero"] = data.zero().value();
        }
        if(data.exponent().has_value())
        {
            j["exponent"] = data.exponent().value();
        }
        if(data.base().has_value())
        {
            j["base"] = data.base().value();
        }
        if(data.constant().has_value())
        {
            j["constant"] = data.constant().value();
        }
        if(data.align().has_value())
        {
            j["align"] = data.align().value();
        }
        if(data.paddingInner().has_value())
        {
            j["paddingInner"] = data.paddingInner().value();
        }
        if(data.paddingOuter().has_value())
        {
            j["paddingOuter"] = data.paddingOuter().value();
        }
        if(data.bins().has_value())
        {
            j["bins"] = data.bins().value();
        }
    }

    using scaleType = xtl::variant<Scale, std::nullptr_t>;
}

#endif