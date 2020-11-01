// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_RULE_HPP
#define XVEGA_MARK_RULE_HPP

#include "../marks.hpp"

namespace xv
{
    struct mark_rule : public mark<mark_rule>
    {
        XVEGA_API mark_rule();

        XVEGA_API void to_json(nl::json& j) const;
    };
}

#endif
