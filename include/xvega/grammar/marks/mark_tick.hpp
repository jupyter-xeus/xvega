// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_TICK
#define XVEGA_MARK_TICK

#include "../marks.hpp"

namespace xv
{
    struct mark_tick : public Marks<mark_tick>
    {
        using base_type = Marks<mark_tick>;

        // Tick Mark Properties
        XPROPERTY(xtl::xoptional<double>, mark_tick, cornerRadius);
        XPROPERTY(xtl::xoptional<std::string>, mark_tick, orient, xtl::missing<std::string>(), XEITHER_OPTIONAL("horizontal", "vertical"));

        mark_tick()
        {
            type = "tick";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            // Fill in Tick Mark Properties
            if(cornerRadius().has_value())
            {
                j["cornerRadius"] = cornerRadius().value();
            }
            if(orient().has_value())
            {
                j["orient"] = orient().value();
            }
        }
    };
}

#endif
