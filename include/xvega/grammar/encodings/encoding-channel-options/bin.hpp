// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_BIN_HPP
#define XVEGA_ENCODING_OPTIONS_BIN_HPP

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
    struct Bin : public xp::xobserved<Bin>
    {
        XPROPERTY(xtl::xoptional<double>, Bin, anchor);
        XPROPERTY(xtl::xoptional<double>, Bin, base);
        XPROPERTY(xtl::xoptional<bool>, Bin, binned);
        XPROPERTY(xtl::xoptional<std::vector<double>>, Bin, divide);
        XPROPERTY(xtl::xoptional<std::vector<double>>, Bin, extent); // Need to confirm if it's a list of 2-element arrays OR just a 2 element tuple
        XPROPERTY(xtl::xoptional<double>, Bin, maxbins);
        XPROPERTY(xtl::xoptional<double>, Bin, minstep);
        XPROPERTY(xtl::xoptional<bool>, Bin, nice);
        XPROPERTY(xtl::xoptional<double>, Bin, step);
        XPROPERTY(xtl::xoptional<std::vector<double>>, Bin, steps);
    };

    void to_json(nl::json& j, const Bin& data);

    using bin_type = xtl::variant<bool, Bin, std::string, std::nullptr_t>;
}

#endif