// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_IMPUTE_HPP
#define XVEGA_ENCODING_OPTIONS_IMPUTE_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

namespace nl = nlohmann;

namespace xv
{

    using numNoneType = xtl::variant<std::nullptr_t, double, int>;
    using anyType = xtl::variant<std::string, bool, double, int, std::nullptr_t>;

    struct ImputeSequence : public xp::xobserved<ImputeSequence>
    {
        XPROPERTY(xtl::xoptional<double>, ImputeSequence, start);
        XPROPERTY(xtl::xoptional<double>, ImputeSequence, stop);
        XPROPERTY(xtl::xoptional<double>, ImputeSequence, step);
    };

    void to_json(nl::json& j, const ImputeSequence& data)
    {
        if(data.start().has_value())
        {
            j["start"] = data.start().value();
        }
        if(data.stop().has_value())
        {
            j["stop"] = data.stop().value();
        }
        if(data.step().has_value())
        {
            j["step"] = data.step().value();
        }
    }

    using  imputeKeyValsType = xtl::variant<std::vector<anyType>, ImputeSequence>;

    struct Impute : public xp::xobserved<Impute>
    {
        XPROPERTY(xtl::xoptional<std::vector<numNoneType>>, Impute, frame);
        XPROPERTY(xtl::xoptional<imputeKeyValsType>, Impute, keyvals);
        XPROPERTY(xtl::xoptional<std::string>, Impute, method);
        XPROPERTY(xtl::xoptional<anyType>, Impute, value);
    };

    void to_json(nl::json& j, const Impute& data)
    {
        if(data.frame().has_value())
        {
            j["frame"] = data.frame().value();
        }
        if(data.keyvals().has_value())
        {
            j["keyvals"] = data.keyvals().value();
        }
        if(data.method().has_value())
        {
            j["method"] = data.method().value();
        }
        if(data.value().has_value())
        {
            j["value"] = data.value().value();
        }
    }

    using imputeType = xtl::variant<Impute, std::nullptr_t>;
}

#endif