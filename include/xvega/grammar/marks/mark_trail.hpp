// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_TRAIL_HPP
#define XVEGA_MARK_TRAIL_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_trail : public mark<mark_trail>
    {
        using base_type = mark<mark_trail>;

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
            serialize(j, orient(), "orient");
        }
    };
}

#endif
