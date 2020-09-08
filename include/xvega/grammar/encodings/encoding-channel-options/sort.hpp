// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_SORT_HPP
#define XVEGA_ENCODING_OPTIONS_SORT_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "./datetime.hpp"
#include "./field.hpp"
#include "../../../utils/serialize.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_none_type = xtl::variant<std::nullptr_t, std::string>;
    using any_array_type = xtl::variant<
                                std::vector<std::string>, 
                                std::vector<double>, 
                                std::vector<int>, 
                                std::vector<bool>, 
                                std::vector<DateTime>
                                >;

    struct FieldSort : public xp::xobserved<FieldSort>
    {
        XPROPERTY(xtl::xoptional<field_type>, FieldSort, field);
        XPROPERTY(xtl::xoptional<std::string>, FieldSort, op);
        XPROPERTY(xtl::xoptional<string_none_type>, FieldSort, order);
    };

    void to_json(nl::json& j, const FieldSort& data);

    struct EncodingSort : public xp::xobserved<EncodingSort>
    {
        XPROPERTY(xtl::xoptional<std::string>, EncodingSort, encoding);
        XPROPERTY(xtl::xoptional<string_none_type>, EncodingSort, order);
    };

    void to_json(nl::json& j, const EncodingSort& data);

    using sort_type = xtl::variant<any_array_type, std::string, std::nullptr_t, FieldSort, EncodingSort>;
}

#endif