#include "../base/xvega-base.hpp"

namespace xv
{
    void populate_encodings(const Chart& v)
    {
        int len_encodings = v.encodings().size();
        if(len_encodings==1)
        {
            if(!v.encodings()[0].x().field().empty())
            {
                json_template["encoding"]["x"]["field"] = v.encodings()[0].x().field();
                json_template["encoding"]["x"]["type"] = v.encodings()[0].x().type();
            }

            if(!v.encodings()[0].y().field().empty())
            {
                json_template["encoding"]["y"]["field"] = v.encodings()[0].y().field();
                json_template["encoding"]["y"]["type"] = v.encodings()[0].y().type();
            }
        }
        else
        {
            for(int k=0; k<len_encodings; k++)
            {
                if(!v.encodings()[k].x().field().empty())
                {
                    json_template["layer"][k]["encoding"]["x"]["field"] = v.encodings()[k].x().field();
                    json_template["layer"][k]["encoding"]["x"]["type"] = v.encodings()[k].x().type();
                }

                if(!v.encodings()[k].y().field().empty())
                {
                    json_template["layer"][k]["encoding"]["y"]["field"] = v.encodings()[k].y().field();
                    json_template["layer"][k]["encoding"]["y"]["type"] = v.encodings()[k].y().type();
                }
            }
        }
    }
}