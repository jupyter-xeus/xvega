#include "../base/xvega-base.hpp"

namespace xv
{
    void populate_encodings(const Chart& v)
    {
        int len_encodings = v.encodings().size();
        auto j = json_template;
        for(int i=0; i<len_encodings; i++)
        {
            if(len_encodings>1)
            {
                j["layer"][i] = nl::json::object();
                j = j["layer"][i];
            }

            j["encoding"] = v.encodings()[i];

            if(len_encodings>1)
            {
                json_template["layer"][i]["encoding"] = j["encoding"];
            }
        }
        if(len_encodings == 1)
        {
            json_template["encoding"] = j["encoding"];
        }
    }
}