#ifndef XVEGA_JSON_HPP
#define XVEGA_JSON_HPP

#include "nlohmann/json.hpp"
#include <xtl/xoptional.hpp>
#include <iostream>

template <class D, class B>
class xoptional;

template <class T>
xoptional<T, bool> missing() noexcept;

namespace xtl
{
    // to_json and from_json ADL overload
    template <class D, class B>
    void to_json(nlohmann::json& j, const xoptional<D, B>& o)
    {
        if (o.has_value())
        {
            j = o.value();
        }
    }

    template <class D, class B>
    void from_json(const nlohmann::json& j, xoptional<D, B>& o)
    {
        if (!j.is_null())
        {
            o = j.get<D>();
        }
    }
}

#endif