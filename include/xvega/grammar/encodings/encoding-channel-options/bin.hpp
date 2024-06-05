// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_BIN_HPP
#define XVEGA_ENCODING_OPTIONS_BIN_HPP

#include <optional>
#include <variant>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    struct Bin : public xp::xobserved<Bin>
    {
        XPROPERTY(std::optional<double>, Bin, anchor);
        XPROPERTY(std::optional<double>, Bin, base);
        XPROPERTY(std::optional<bool>, Bin, binned);
        XPROPERTY(std::optional<std::vector<double>>, Bin, divide);
        XPROPERTY(std::optional<std::vector<double>>, Bin, extent); // Need to confirm if it's a list of 2-element arrays OR just a 2 element tuple
        XPROPERTY(std::optional<double>, Bin, maxbins);
        XPROPERTY(std::optional<double>, Bin, minstep);
        XPROPERTY(std::optional<bool>, Bin, nice);
        XPROPERTY(std::optional<double>, Bin, step);
        XPROPERTY(std::optional<std::vector<double>>, Bin, steps);
    };

    XVEGA_API void to_json(nl::json& j, const Bin& data);

    using bin_type = std::variant<bool, Bin, std::string, std::nullptr_t>;
}

#endif
