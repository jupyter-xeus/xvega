// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_SCALE_HPP
#define XVEGA_ENCODING_OPTIONS_SCALE_HPP

#include <optional>
#include <variant>

#include <xproperty/xobserved.hpp>
#include <nlohmann/json.hpp>

#include "./datetime.hpp"
#include "../../../xvega_config.hpp"
#include "../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    using num_datetime_type = std::variant<double, int, DateTime>;
    using scale_range_type = std::variant<
                                  std::string, 
                                  std::vector<double>, 
                                  std::vector<int>, 
                                  std::vector<std::string>, 
                                  nl::json
                                  >;

    struct DomainUnionWith : public xp::xobserved<DomainUnionWith>
    {
        XPROPERTY(std::optional<any_array_type>, DomainUnionWith, unionWith);
    };

    XVEGA_API void to_json(nl::json& j, const DomainUnionWith& data);

    using scale_domain_type = std::variant<
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
        XPROPERTY(std::optional<double>, ScaleBin, start);
        XPROPERTY(std::optional<double>, ScaleBin, stop);
        XPROPERTY(std::optional<double>, ScaleBin, step);
    };

    XVEGA_API void to_json(nl::json& j, const ScaleBin& data);

    using scale_bin_type = std::variant<std::vector<double>, std::vector<int>, ScaleBin>;

    struct Scheme : public xp::xobserved<Scheme>
    {
        XPROPERTY(std::optional<std::string>, Scheme, name);
        XPROPERTY(std::optional<std::vector<double>>, Scheme, extent);
        XPROPERTY(std::optional<double>, Scheme, count);
    };

    XVEGA_API void to_json(nl::json& j, const Scheme& data);

    using scale_scheme_type = std::variant<std::string, Scheme>;

    struct ScaleInterpolate : public xp::xobserved<ScaleInterpolate>
    {
        XPROPERTY(std::optional<std::string>, ScaleInterpolate, type);
        XPROPERTY(std::optional<double>, ScaleInterpolate, gamma);
    };

    XVEGA_API void to_json(nl::json& j, const ScaleInterpolate& data);

    using scale_interpolate_type = std::variant<std::string, ScaleInterpolate>;

    struct TimeIntervalStep : public xp::xobserved<TimeIntervalStep>
    {
        XPROPERTY(std::optional<std::string>, TimeIntervalStep, interval);
        XPROPERTY(std::optional<double>, TimeIntervalStep, step);
    };

    XVEGA_API void to_json(nl::json& j, const TimeIntervalStep& data);

    using nice_type = std::variant<double, int, std::string, bool, TimeIntervalStep>;

    struct Scale : public xp::xobserved<Scale>
    {
        XPROPERTY(std::optional<std::string>, Scale, type);
        XPROPERTY(std::optional<scale_domain_type>, Scale, domain);
        XPROPERTY(std::optional<num_datetime_type>, Scale, domainMax);
        XPROPERTY(std::optional<num_datetime_type>, Scale, domainMin);
        XPROPERTY(std::optional<double>, Scale, domainMid);
        XPROPERTY(std::optional<scale_range_type>, Scale, range);
        XPROPERTY(std::optional<string_num_type>, Scale, rangeMin);
        XPROPERTY(std::optional<string_num_type>, Scale, rangeMax);
        XPROPERTY(std::optional<scale_scheme_type>, Scale, scheme);
        XPROPERTY(std::optional<bool>, Scale, reverse);
        XPROPERTY(std::optional<bool>, Scale, round);
        XPROPERTY(std::optional<bool>, Scale, clamp);
        XPROPERTY(std::optional<scale_interpolate_type>, Scale, interpolate);
        XPROPERTY(std::optional<nice_type>, Scale, nice);
        XPROPERTY(std::optional<double>, Scale, padding);
        XPROPERTY(std::optional<bool>, Scale, zero);
        XPROPERTY(std::optional<double>, Scale, exponent);
        XPROPERTY(std::optional<double>, Scale, base);
        XPROPERTY(std::optional<double>, Scale, constant);
        XPROPERTY(std::optional<double>, Scale, align);
        XPROPERTY(std::optional<double>, Scale, paddingInner);
        XPROPERTY(std::optional<double>, Scale, paddingOuter);
        XPROPERTY(std::optional<scale_bin_type>, Scale, bins);
    };

    XVEGA_API void to_json(nl::json& j, const Scale& data);

    using scale_type = std::variant<Scale, std::nullptr_t>;
}

#endif
