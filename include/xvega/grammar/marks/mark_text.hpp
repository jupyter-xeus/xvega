// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_TEXT_HPP
#define XVEGA_MARK_TEXT_HPP

#include <optional>

#include "../marks.hpp"

namespace xv
{
    struct mark_text : public mark<mark_text>
    {
        // Text Mark Properties
        XPROPERTY(std::optional<double>, mark_text, angle);
        XPROPERTY(std::optional<std::string>, mark_text, align);
        XPROPERTY(std::optional<std::string>, mark_text, baseline);
        XPROPERTY(std::optional<std::string>, mark_text, dir);
        XPROPERTY(std::optional<double>, mark_text, dx);
        XPROPERTY(std::optional<double>, mark_text, dy);
        XPROPERTY(std::optional<std::string>, mark_text, ellipsis);
        XPROPERTY(std::optional<std::string>, mark_text, font);
        XPROPERTY(std::optional<double>, mark_text, fontSize);
        XPROPERTY(std::optional<std::string>, mark_text, fontStyle);
        XPROPERTY(std::optional<string_num_type>, mark_text, fontWeight);
        XPROPERTY(std::optional<double>, mark_text, limit);
        XPROPERTY(std::optional<double>, mark_text, lineHeight);
        XPROPERTY(std::optional<double>, mark_text, radius);
        XPROPERTY(std::optional<std::vector<std::string>>, mark_text, text);
        XPROPERTY(std::optional<double>, mark_text, theta);

        XVEGA_API mark_text();
    };

    XVEGA_API void to_json(nl::json&, const mark_text&);
}

#endif
