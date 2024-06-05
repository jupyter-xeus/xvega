// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_FIELD_HPP
#define XVEGA_ENCODING_OPTIONS_FIELD_HPP

#include <variant>

#include <xproperty/xobserved.hpp>

#include <nlohmann/json.hpp>

#include "./repeatRef.hpp"
#include "../../../xvega_config.hpp"

namespace xv
{
    using field_type = std::variant<std::string, RepeatRef>;
}

#endif
