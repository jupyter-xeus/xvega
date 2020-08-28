// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_HPP
#define XVEGA_HPP

#include "nlohmann/json.hpp"
#include "functions/populate_data.hpp"
#include "functions/populate_marks.hpp"
#include "functions/populate_encodings.hpp"
#include "functions/populate_selections.hpp"
#include "./utils/serialize.hpp"

namespace nl = nlohmann;

namespace xv
{
    nl::json mime_bundle_repr(const Chart& v)
    {
        populate_data(v);

        serialize(json_template, v.width(), "width");
        serialize(json_template, v.height(), "height");

        int len_marks = v.marks().size();
        if(len_marks > 1)
        {
            json_template["layer"] = {{}};
        }
        
        populate_marks(v);
        populate_encodings(v);
        populate_selections(v);

        auto bundle = nl::json::object();
        bundle["application/vnd.vegalite.v3+json"] = json_template;
        return bundle;
    }
}

#endif