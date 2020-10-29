// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_DATA_FORMAT_HPP
#define XVEGA_DATA_FORMAT_HPP

#include "xproperty/xobserved.hpp"

#include "../../xvega_config.hpp"
#include "../../utils/custom_datatypes.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    using object_none_type = xtl::variant<std::nullptr_t, nl::json>;

    template<class D>
    struct data_format : public xp::xobserved<D>
    {
        XPROPERTY(xtl::xoptional<std::string>, D, type);
        XPROPERTY(xtl::xoptional<object_none_type>, D, parse);

        void to_json(nl::json& j) const
        {
            serialize(j, type(), "type");
            serialize(j, parse(), "parse");
        }

    protected:

        data_format() = default;
        ~data_format() = default;

        data_format(const data_format&) = default;
        data_format& operator=(const data_format&) = default;

        data_format(data_format&&) = default;
        data_format& operator=(data_format&&) = default;
    };

    template<class D>
    void to_json(nl::json& j, const data_format<D>& data)
    {
        data.derived_cast().to_json(j);
    }
}

#endif
