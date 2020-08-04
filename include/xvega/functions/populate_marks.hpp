#include "../base/xvega-base.hpp"
#include "../utils/custom_datatypes.hpp"
#include <xtl/xvariant.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xjson.hpp>

namespace xv
{
    void populate_marks(const Chart& v)
    {
        int len_marks = v.marks().size();
        if(len_marks==0)
        {
            std::cerr << "Make sure to include 'mark' in the specification!" << std::endl;
        }
        auto j = json_template;
        for(int i=0; i<len_marks; i++)
        {
            if(len_marks>1)
            {
                j["layer"][i] = nl::json::object();
                j = j["layer"][i];
            }
            
            j["mark"] = v.marks()[i];

            if(len_marks>1)
            {
                json_template["layer"][i]["mark"] = j["mark"];
            }
        }
        if(len_marks == 1)
        {
            json_template["mark"] = j["mark"];
        }
    }
}