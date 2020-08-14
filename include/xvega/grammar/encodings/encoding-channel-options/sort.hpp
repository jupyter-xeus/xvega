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

namespace nl = nlohmann;

namespace xv
{
    using stringNoneType = xtl::variant<std::nullptr_t, std::string>;
    using anyArrayType = xtl::variant<std::vector<std::string>, std::vector<double>, std::vector<int>, std::vector<bool>, std::vector<DateTime>>;

    struct FieldSort : public xp::xobserved<FieldSort>
    {
        XPROPERTY(xtl::xoptional<fieldType>, FieldSort, field);
        XPROPERTY(xtl::xoptional<std::string>, FieldSort, op);
        XPROPERTY(xtl::xoptional<stringNoneType>, FieldSort, order);
    };

    void to_json(nl::json& j, const FieldSort& data) {
        if(data.field().has_value())
        {
            j["field"] = data.field().value();
        }
        if(data.op().has_value())
        {
            j["op"] = data.op().value();
        }
        if(data.order().has_value())
        {
            j["order"] = data.order().value();
        }
    }

    struct EncodingSort : public xp::xobserved<EncodingSort>
    {
        XPROPERTY(xtl::xoptional<std::string>, EncodingSort, encoding);
        XPROPERTY(xtl::xoptional<stringNoneType>, EncodingSort, order);
    };

    void to_json(nl::json& j, const EncodingSort& data) {
        if(data.encoding().has_value())
        {
            j["encoding"] = data.encoding().value();
        }
        if(data.order().has_value())
        {
            j["order"] = data.order().value();
        }
    }

    using sortType = xtl::variant<anyArrayType, std::string, std::nullptr_t, FieldSort, EncodingSort>;
}

#endif