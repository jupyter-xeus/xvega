// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_BAR_HPP
#define XVEGA_MARK_BAR_HPP

#include <optional>

#include "../marks.hpp"

namespace xv
{
    struct mark_bar : public mark<mark_bar>
    {
        // Bar Mark Properties
        XPROPERTY(std::optional<std::string>, mark_bar, orient);
        XPROPERTY(std::optional<std::string>, mark_bar, align);
        XPROPERTY(std::optional<std::string>, mark_bar, baseline);
        XPROPERTY(std::optional<double>, mark_bar, binSpacing);
        XPROPERTY(std::optional<double>, mark_bar, cornerRadius);
        XPROPERTY(std::optional<double>, mark_bar, cornerRadiusEnd);
        XPROPERTY(std::optional<double>, mark_bar, cornerRadiusTopLeft);
        XPROPERTY(std::optional<double>, mark_bar, cornerRadiusTopRight);
        XPROPERTY(std::optional<double>, mark_bar, cornerRadiusBottomLeft);
        XPROPERTY(std::optional<double>, mark_bar, cornerRadiusBottomRight);

        XVEGA_API mark_bar();
    };

    XVEGA_API void to_json(nl::json&, const mark_bar&);
}

#endif
