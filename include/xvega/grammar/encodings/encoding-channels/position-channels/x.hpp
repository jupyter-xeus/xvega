// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_X_HPP
#define XVEGA_ENCODING_X_HPP

#include <optional>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../encoding-channel-options/aggregate.hpp"
#include "../../encoding-channel-options/axis.hpp"
#include "../../encoding-channel-options/bin.hpp"
#include "../../encoding-channel-options/field.hpp"
#include "../../encoding-channel-options/impute.hpp"
#include "../../encoding-channel-options/scale.hpp"
#include "../../encoding-channel-options/sort.hpp"
#include "../../encoding-channel-options/stack.hpp"
#include "../../encoding-channel-options/timeunit.hpp"
#include "../../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct X : public xp::xobserved<X>
    {
        XPROPERTY(std::optional<agg_type>, X, aggregate);
        XPROPERTY(std::optional<axis_type>, X, axis);
        XPROPERTY(std::optional<double>, X, band);
        XPROPERTY(std::optional<bin_type>, X, bin);
        XPROPERTY(std::optional<field_type>, X, field);
        XPROPERTY(std::optional<impute_type>, X, impute);
        XPROPERTY(std::optional<scale_type>, X, scale);
        XPROPERTY(std::optional<sort_type>, X, sort);
        XPROPERTY(std::optional<stack_type>, X, stack);
        XPROPERTY(std::optional<time_unit_type>, X, timeUnit);
        XPROPERTY(std::optional<string_vec_none_type>, X, title);
        XPROPERTY(std::optional<std::string>, X, type);
    };

    XVEGA_API void to_json(nl::json& j, const X& data);
}

#endif
