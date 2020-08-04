#include "../base/xvega-base.hpp"

namespace xv
{
    void populate_data(const Chart& v)
    {
        json_template["data"]["values"] = {{}};
        int i;
        for(auto const& x : v.data())
        {
            std::string column_name = x.first;
            std::vector<xtl::variant<double, int, std::string>> values = x.second;
            i = 0;
            for(auto& k: values)
            {
                xtl::visit([&](auto&& each_value){json_template["data"]["values"][i][x.first]=each_value;}, k);
                i++;
            }
        }
    }   
}
