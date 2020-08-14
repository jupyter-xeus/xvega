#ifndef XVEGA_ENCODING_OPTIONS_STACK_HPP
#define XVEGA_ENCODING_OPTIONS_STACK_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

namespace nl = nlohmann;

namespace xv
{
    using stackType = xtl::variant<std::string, std::nullptr_t, bool>;
}

#endif