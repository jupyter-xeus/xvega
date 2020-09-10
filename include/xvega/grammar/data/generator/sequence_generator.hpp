// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SEQUENCE_GENERATOR_HPP
#define XVEGA_SEQUENCE_GENERATOR_HPP

#include "xproperty/xobserved.hpp"
#include "xtl/xvariant.hpp"
#include "xtl/xoptional.hpp"
#include "nlohmann/json.hpp"
#include "xtl/xjson.hpp"

#include "../../../xvega_config.hpp"
#include "../../../utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct sequence_params : public xp::xobserved<sequence_params>
    {
        XPROPERTY(xtl::xoptional<double>, sequence_params, start);
        XPROPERTY(xtl::xoptional<double>, sequence_params, stop);
        XPROPERTY(xtl::xoptional<double>, sequence_params, step);
        XPROPERTY(xtl::xoptional<std::string>, sequence_params, as);
    };

    void to_json(nl::json& j, const sequence_params& data);

    struct sequence_generator : public xp::xobserved<sequence_generator>
    {
        XPROPERTY(xtl::xoptional<sequence_params>, sequence_generator, sequence);
        XPROPERTY(xtl::xoptional<std::string>, sequence_generator, name);
    };

    void to_json(nl::json& j, const sequence_generator& data);
}

#endif
