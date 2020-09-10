// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_GRATICULE_GENERATOR_HPP
#define XVEGA_GRATICULE_GENERATOR_HPP

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
    struct graticule_params : public xp::xobserved<graticule_params>
    {
        XPROPERTY(xtl::xoptional<std::vector<double>>, graticule_params, extent);
        XPROPERTY(xtl::xoptional<std::vector<double>>, graticule_params, extentMajor);
        XPROPERTY(xtl::xoptional<std::vector<double>>, graticule_params, extentMinor);
        XPROPERTY(xtl::xoptional<double>, graticule_params, precision);
        XPROPERTY(xtl::xoptional<std::vector<double>>, graticule_params, step);
        XPROPERTY(xtl::xoptional<std::vector<double>>, graticule_params, stepMajor);
        XPROPERTY(xtl::xoptional<std::vector<double>>, graticule_params, stepMinor);
    };

    void to_json(nl::json& j, const graticule_params& data);

    using graticule_type = xtl::variant<bool, graticule_params>;

    struct graticule_generator : public xp::xobserved<graticule_generator>
    {
        XPROPERTY(xtl::xoptional<graticule_type>, graticule_generator, graticule);
        XPROPERTY(xtl::xoptional<std::string>, graticule_generator, name);
    };

    void to_json(nl::json& j, const graticule_generator& data);
}

#endif
