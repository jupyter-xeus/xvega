// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_TRAIL
#define XVEGA_MARK_TRAIL

#include "../marks.hpp"

namespace xv
{
    struct mark_trail : public Marks<mark_trail>
    {
        using base_type = Marks<mark_trail>;

        // Trail Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, mark_trail, orient, xtl::missing<std::string>(), XEITHER_OPTIONAL("horizontal", "vertical"));

        mark_trail()
        {
            type = "trail";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            // Fill in Trail Mark Properties
            if(orient().has_value())
            {
                j["orient"] = orient().value();
            }
        }
    };
}

#endif
