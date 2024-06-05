// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SEQUENCE_GENERATOR_HPP
#define XVEGA_SEQUENCE_GENERATOR_HPP

#include <optional>

#include "xproperty/xobserved.hpp"

#include "nlohmann/json.hpp"

#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct sequence_params : public xp::xobserved<sequence_params>
    {
        XPROPERTY(std::optional<double>, sequence_params, start);
        XPROPERTY(std::optional<double>, sequence_params, stop);
        XPROPERTY(std::optional<double>, sequence_params, step);
        XPROPERTY(std::optional<std::string>, sequence_params, as);
    };

    XVEGA_API void to_json(nl::json& j, const sequence_params& data);

    struct sequence_generator : public xp::xobserved<sequence_generator>
    {
        XPROPERTY(std::optional<sequence_params>, sequence_generator, sequence);
        XPROPERTY(std::optional<std::string>, sequence_generator, name);
    };

    XVEGA_API void to_json(nl::json& j, const sequence_generator& data);
}

#endif
