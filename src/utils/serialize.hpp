// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_SERIALIZE_HPP
#define XVEGA_SERIALIZE_HPP

#include "xvega/xvega_config.hpp"

#include "nlohmann/json.hpp"

#include "xtl/xoptional.hpp"

namespace nl = nlohmann;

namespace xv
{
    template <class CT, class CB>
    void serialize(nl::json& j, const xtl::xoptional<CT, CB>& p, const std::string& name)
    {
        if(p.has_value())
        {
            j[name] = p.value();
        }
    }
    
    template <class P>
    void serialize(nl::json& j, const P& p, const std::string& name)
    {
        j[name] = p.value();
    }
}

#endif
