// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_IMPUTE_HPP
#define XVEGA_ENCODING_OPTIONS_IMPUTE_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../../utils/serialize.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{

    using num_none_type = xtl::variant<std::nullptr_t, double, int>;
    using any_type = xtl::variant<std::string, bool, double, int, std::nullptr_t>;

    struct ImputeSequence : public xp::xobserved<ImputeSequence>
    {
        XPROPERTY(xtl::xoptional<double>, ImputeSequence, start);
        XPROPERTY(xtl::xoptional<double>, ImputeSequence, stop);
        XPROPERTY(xtl::xoptional<double>, ImputeSequence, step);
    };

    void to_json(nl::json& j, const ImputeSequence& data);

    using impute_key_vals_type = xtl::variant<std::vector<any_type>, ImputeSequence>;

    struct Impute : public xp::xobserved<Impute>
    {
        XPROPERTY(xtl::xoptional<std::vector<num_none_type>>, Impute, frame);
        XPROPERTY(xtl::xoptional<impute_key_vals_type>, Impute, keyvals);
        XPROPERTY(xtl::xoptional<std::string>, Impute, method);
        XPROPERTY(xtl::xoptional<any_type>, Impute, value);
    };

    void to_json(nl::json& j, const Impute& data);

    using impute_type = xtl::variant<Impute, std::nullptr_t>;
}

#endif