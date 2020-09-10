// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_BAR_HPP
#define XVEGA_MARK_BAR_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_bar : public mark<mark_bar>
    {
        using base_type = mark<mark_bar>;

        // Bar Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, mark_bar, orient);
        XPROPERTY(xtl::xoptional<std::string>, mark_bar, align);
        XPROPERTY(xtl::xoptional<std::string>, mark_bar, baseline);
        XPROPERTY(xtl::xoptional<double>, mark_bar, binSpacing);
        XPROPERTY(xtl::xoptional<double>, mark_bar, cornerRadius);
        XPROPERTY(xtl::xoptional<double>, mark_bar, cornerRadiusEnd);
        XPROPERTY(xtl::xoptional<double>, mark_bar, cornerRadiusTopLeft);
        XPROPERTY(xtl::xoptional<double>, mark_bar, cornerRadiusTopRight);
        XPROPERTY(xtl::xoptional<double>, mark_bar, cornerRadiusBottomLeft);
        XPROPERTY(xtl::xoptional<double>, mark_bar, cornerRadiusBottomRight);

        mark_bar();

        void to_json(nl::json& j) const;
    };
}

#endif
