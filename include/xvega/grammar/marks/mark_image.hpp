// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_IMAGE_HPP
#define XVEGA_MARK_IMAGE_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_image : public mark<mark_image>
    {
        using base_type = mark<mark_image>;

        // Image Mark Properties
        XPROPERTY(xtl::xoptional<any_type>, mark_image, url);
        XPROPERTY(xtl::xoptional<bool>, mark_image, aspect);
        XPROPERTY(xtl::xoptional<std::string>, mark_image, align, xtl::missing<std::string>(), XEITHER_OPTIONAL("left", "right", "center"));
        XPROPERTY(xtl::xoptional<std::string>, mark_image, baseline, xtl::missing<std::string>(), XEITHER_OPTIONAL("alphabetic", "top", "middle", "bottom", "line-top", "line-bottom"));

        mark_image()
        {
            type = "image";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            // Fill in Image Mark Properties
            serialize(j, url(), "url");
            serialize(j, aspect(), "aspect");
            serialize(j, align(), "align");
            serialize(j, baseline(), "baseline");
        }
    };
}

#endif
