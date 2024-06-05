// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_IMPUTE_HPP
#define XVEGA_ENCODING_OPTIONS_IMPUTE_HPP

#include <optional>
#include <variant>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../../xvega_config.hpp"
#include "../../../utils/custom_datatypes.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct ImputeSequence : public xp::xobserved<ImputeSequence>
    {
        XPROPERTY(std::optional<double>, ImputeSequence, start);
        XPROPERTY(std::optional<double>, ImputeSequence, stop);
        XPROPERTY(std::optional<double>, ImputeSequence, step);
    };

    XVEGA_API void to_json(nl::json& j, const ImputeSequence& data);

    using impute_key_vals_type = std::variant<std::vector<any_type>, ImputeSequence>;

    struct Impute : public xp::xobserved<Impute>
    {
        XPROPERTY(std::optional<std::vector<num_none_type>>, Impute, frame);
        XPROPERTY(std::optional<impute_key_vals_type>, Impute, keyvals);
        XPROPERTY(std::optional<std::string>, Impute, method);
        XPROPERTY(std::optional<any_type>, Impute, value);
    };

    XVEGA_API void to_json(nl::json& j, const Impute& data);

    using impute_type = std::variant<Impute, std::nullptr_t>;
}

#endif
