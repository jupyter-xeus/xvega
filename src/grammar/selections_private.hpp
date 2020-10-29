#ifndef SELECTIONS_PRIVATE_HPP
#define SELECTIONS_PRIVATE_HPP

#include "xvega/grammar/selections.hpp"

namespace xv
{
    template <class D>
    void private_to_json(const selection<D>& c, nl::json& j)
    {
        // Fill in General Selection Properties
        serialize(j, c.type(), "type");
        serialize(j, c.clear(), "clear");
        serialize(j, c.empty(), "empty");
        serialize(j, c.on(), "on");
        serialize(j, c.resolve(), "resolve");
        serialize(j, c.encodings(), "encodings");
        serialize(j, c.fields(), "fields");
    }
}
#endif
