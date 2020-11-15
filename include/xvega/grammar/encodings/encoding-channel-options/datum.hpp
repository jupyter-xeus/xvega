// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_DATUM_HPP
#define XVEGA_ENCODING_OPTIONS_DATUM_HPP

#include <xproperty/xobserved.hpp>

#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>

#include <nlohmann/json.hpp>

#include "./datetime.hpp"
#include "./repeatRef.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    using datum_type = xtl::variant<double, int, std::string, DateTime, RepeatRef>;
}

#endif