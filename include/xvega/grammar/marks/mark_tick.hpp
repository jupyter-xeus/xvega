// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_TICK_HPP
#define XVEGA_MARK_TICK_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_tick : public mark<mark_tick>
    {
        using base_type = mark<mark_tick>;

        // Tick Mark Properties
        XPROPERTY(xtl::xoptional<double>, mark_tick, cornerRadius);
        XPROPERTY(xtl::xoptional<std::string>, mark_tick, orient);

        XVEGA_API mark_tick();

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
