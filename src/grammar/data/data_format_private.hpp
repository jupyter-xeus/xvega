#ifndef DATA_FORMAT_PRIVATE_HPP
#define DATA_FORMAT_PRIVATE_HPP

#include "xvega/grammar/data/data_format.hpp"

namespace xv
{
    template <class D>
    void private_to_json(const data_format<D>& c, nl::json& j)
    {
        serialize(j, c.type(), "type");
        serialize(j, c.parse(), "parse");
    }
}
#endif
