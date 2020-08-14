#ifndef XVEGA_ENCODING_OPTIONS_DATUM_HPP
#define XVEGA_ENCODING_OPTIONS_DATUM_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "./datetime.hpp"
#include "./repeatRef.hpp"

namespace nl = nlohmann;

namespace xv
{
    using datumType = xtl::variant<double, int, std::string, DateTime, RepeatRef>;
}

#endif