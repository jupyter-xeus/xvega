#ifndef XVEGA_HPP
#define XVEGA_HPP

#include "nlohmann/json.hpp"
#include "functions/populate_data.hpp"
#include "functions/populate_marks.hpp"
#include "functions/populate_encodings.hpp"

namespace nl = nlohmann;

namespace xv
{
    nl::json mime_bundle_repr(const Chart& v)
    {
        populate_data(v);

        if(xtl::has_value(v.width()))
        {
            json_template["width"] = xtl::value(v.width());
        }

        if(xtl::has_value(v.height()))
        {
            json_template["height"] = xtl::value(v.height());
        }

        int len_marks = v.marks().size();
        if(len_marks > 1)
        {
            json_template["layer"] = {{}};
        }
        populate_marks(v);
        populate_encodings(v);

        auto bundle = nl::json::object();
        bundle["application/vnd.vegalite.v3+json"] = json_template;
        return bundle;
    }
}

#endif