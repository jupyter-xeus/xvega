// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_IMPUTE_HPP
#define XVEGA_ENCODING_OPTIONS_IMPUTE_HPP

#include <xproperty/xobserved.hpp>

#include <xtl/xoptional.hpp>
#include <xtl/xjson.hpp>

#include <nlohmann/json.hpp>

#include "../../../xvega_config.hpp"
#include "../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct ImputeSequence : public xp::xobserved<ImputeSequence>
    {
        XPROPERTY(xtl::xoptional<double>, ImputeSequence, start);
        XPROPERTY(xtl::xoptional<double>, ImputeSequence, stop);
        XPROPERTY(xtl::xoptional<double>, ImputeSequence, step);
    };

    XVEGA_API void to_json(nl::json& j, const ImputeSequence& data);

    using impute_key_vals_type = xtl::variant<std::vector<any_type>, ImputeSequence>;

    struct Impute : public xp::xobserved<Impute>
    {
        XPROPERTY(xtl::xoptional<std::vector<num_none_type>>, Impute, frame);
        XPROPERTY(xtl::xoptional<impute_key_vals_type>, Impute, keyvals);
        XPROPERTY(xtl::xoptional<std::string>, Impute, method);
        XPROPERTY(xtl::xoptional<any_type>, Impute, value);
    };

    XVEGA_API void to_json(nl::json& j, const Impute& data);

    using impute_type = xtl::variant<Impute, std::nullptr_t>;
}

#endif
