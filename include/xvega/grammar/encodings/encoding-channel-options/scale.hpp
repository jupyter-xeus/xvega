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
#include "../../../utils/serialize.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{

    using any_array_type = xtl::variant<
                                std::vector<std::string>, 
                                std::vector<double>, 
                                std::vector<int>, 
                                std::vector<bool>, 
                                std::vector<DateTime>
                                >;
    using num_datetime_type = xtl::variant<double, int, DateTime>;
    using string_num_type = xtl::variant<double, int, std::string>;
    using scale_range_type = xtl::variant<
                                  std::string, 
                                  std::vector<double>, 
                                  std::vector<int>, 
                                  std::vector<std::string>, 
                                  nl::json
                                  >;

    struct DomainUnionWith : public xp::xobserved<DomainUnionWith>
    {
        XPROPERTY(xtl::xoptional<any_array_type>, DomainUnionWith, unionWith);
    };

    void to_json(nl::json& j, const DomainUnionWith& data);

    using scale_domain_type = xtl::variant<
                                   std::vector<std::string>, 
                                   std::vector<double>, 
                                   std::vector<int>, 
                                   std::vector<bool>, 
                                   std::vector<DateTime>,
                                   std::string, 
                                   nl::json, 
                                   DomainUnionWith
                                   >;

    struct ScaleBin : public xp::xobserved<ScaleBin>
    {
        XPROPERTY(xtl::xoptional<double>, ScaleBin, start);
        XPROPERTY(xtl::xoptional<double>, ScaleBin, stop);
        XPROPERTY(xtl::xoptional<double>, ScaleBin, step);
    };

    void to_json(nl::json& j, const ScaleBin& data);

    using scale_bin_type = xtl::variant<std::vector<double>, std::vector<int>, ScaleBin>;

    struct Scheme : public xp::xobserved<Scheme>
    {
        XPROPERTY(xtl::xoptional<std::string>, Scheme, name);
        XPROPERTY(xtl::xoptional<std::vector<double>>, Scheme, extent);
        XPROPERTY(xtl::xoptional<double>, Scheme, count);
    };

    void to_json(nl::json& j, const Scheme& data);

    using scale_scheme_type = xtl::variant<std::string, Scheme>;

    struct ScaleInterpolate : public xp::xobserved<ScaleInterpolate>
    {
        XPROPERTY(xtl::xoptional<std::string>, ScaleInterpolate, type);
        XPROPERTY(xtl::xoptional<double>, ScaleInterpolate, gamma);
    };

    void to_json(nl::json& j, const ScaleInterpolate& data);

    using scale_interpolate_type = xtl::variant<std::string, ScaleInterpolate>;

    struct TimeIntervalStep : public xp::xobserved<TimeIntervalStep>
    {
        XPROPERTY(xtl::xoptional<std::string>, TimeIntervalStep, interval);
        XPROPERTY(xtl::xoptional<double>, TimeIntervalStep, step);
    };

    void to_json(nl::json& j, const TimeIntervalStep& data);

    using nice_type = xtl::variant<double, int, std::string, bool, TimeIntervalStep>;

    struct Scale : public xp::xobserved<Scale>
    {
        XPROPERTY(xtl::xoptional<std::string>, Scale, type);
        XPROPERTY(xtl::xoptional<scale_domain_type>, Scale, domain);
        XPROPERTY(xtl::xoptional<num_datetime_type>, Scale, domainMax);
        XPROPERTY(xtl::xoptional<num_datetime_type>, Scale, domainMin);
        XPROPERTY(xtl::xoptional<double>, Scale, domainMid);
        XPROPERTY(xtl::xoptional<scale_range_type>, Scale, range);
        XPROPERTY(xtl::xoptional<string_num_type>, Scale, rangeMin);
        XPROPERTY(xtl::xoptional<string_num_type>, Scale, rangeMax);
        XPROPERTY(xtl::xoptional<scale_scheme_type>, Scale, scheme);
        XPROPERTY(xtl::xoptional<bool>, Scale, reverse);
        XPROPERTY(xtl::xoptional<bool>, Scale, round);
        XPROPERTY(xtl::xoptional<bool>, Scale, clamp);
        XPROPERTY(xtl::xoptional<scale_interpolate_type>, Scale, interpolate);
        XPROPERTY(xtl::xoptional<nice_type>, Scale, nice);
        XPROPERTY(xtl::xoptional<double>, Scale, padding);
        XPROPERTY(xtl::xoptional<bool>, Scale, zero);
        XPROPERTY(xtl::xoptional<double>, Scale, exponent);
        XPROPERTY(xtl::xoptional<double>, Scale, base);
        XPROPERTY(xtl::xoptional<double>, Scale, constant);
        XPROPERTY(xtl::xoptional<double>, Scale, align);
        XPROPERTY(xtl::xoptional<double>, Scale, paddingInner);
        XPROPERTY(xtl::xoptional<double>, Scale, paddingOuter);
        XPROPERTY(xtl::xoptional<scale_bin_type>, Scale, bins);
    };

    void to_json(nl::json& j, const Scale& data);

    using scale_type = xtl::variant<Scale, std::nullptr_t>;
}

#endif