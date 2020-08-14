#ifndef XVEGA_ENCODING_OPTIONS_FIELD_HPP
#define XVEGA_ENCODING_OPTIONS_FIELD_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "./repeatRef.hpp"

namespace xv
{
    using fieldType = xtl::variant<std::string, RepeatRef>;
}

#endif