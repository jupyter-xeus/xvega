// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ENCODING_OPTIONS_HEADER_HPP
#define XVEGA_ENCODING_OPTIONS_HEADER_HPP

#include <xproperty/xobserved.hpp>
#include <xtl/xoptional.hpp>
#include <xtl/xvariant.hpp>
#include <xtl/xjson.hpp>
#include <nlohmann/json.hpp>

#include "../../../utils/serialize.hpp"
#include "../../../xvega_config.hpp"

namespace nl = nlohmann;

namespace xv
{
    using string_vec_none_type = xtl::variant<std::vector<std::string>, std::nullptr_t>;
    using string_object_type = xtl::variant<nl::json, std::string>;
    using string_none_type = xtl::variant<std::nullptr_t, std::string>;
    using string_num_type = xtl::variant<double, int, std::string>;

    struct Header : public xp::xobserved<Header>
    {
        XPROPERTY(xtl::xoptional<string_vec_none_type>, Header, title);

        XPROPERTY(xtl::xoptional<string_object_type>, Header, format);
        XPROPERTY(xtl::xoptional<std::string>, Header, formatType);

        XPROPERTY(xtl::xoptional<std::string>, Header, labelAlign);
        XPROPERTY(xtl::xoptional<string_none_type>, Header, labelAnchor);
        XPROPERTY(xtl::xoptional<double>, Header, labelAngle);
        XPROPERTY(xtl::xoptional<std::string>, Header, labelBaseline);
        XPROPERTY(xtl::xoptional<string_none_type>, Header, labelColor);
        XPROPERTY(xtl::xoptional<std::string>, Header, labelExpr);
        XPROPERTY(xtl::xoptional<std::string>, Header, labelFont);
        XPROPERTY(xtl::xoptional<double>, Header, labelFontSize);
        XPROPERTY(xtl::xoptional<std::string>, Header, labelFontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, Header, labelFontWeight);
        XPROPERTY(xtl::xoptional<double>, Header, labelLimit);
        XPROPERTY(xtl::xoptional<double>, Header, labelLineHeight);
        XPROPERTY(xtl::xoptional<std::string>, Header, labelOrient);
        XPROPERTY(xtl::xoptional<double>, Header, labelPadding);

        XPROPERTY(xtl::xoptional<bool>, Header, labels);
        XPROPERTY(xtl::xoptional<std::string>, Header, orient);

        XPROPERTY(xtl::xoptional<std::string>, Header, titleAlign);
        XPROPERTY(xtl::xoptional<string_none_type>, Header, titleAnchor);
        XPROPERTY(xtl::xoptional<double>, Header, titleAngle);
        XPROPERTY(xtl::xoptional<std::string>, Header, titleBaseline);
        XPROPERTY(xtl::xoptional<string_none_type>, Header, titleColor);
        XPROPERTY(xtl::xoptional<std::string>, Header, titleFont);
        XPROPERTY(xtl::xoptional<double>, Header, titleFontSize);
        XPROPERTY(xtl::xoptional<std::string>, Header, titleFontStyle);
        XPROPERTY(xtl::xoptional<string_num_type>, Header, titleFontWeight);
        XPROPERTY(xtl::xoptional<double>, Header, titleLimit);
        XPROPERTY(xtl::xoptional<double>, Header, titleLineHeight);
        XPROPERTY(xtl::xoptional<std::string>, Header, titleOrient);
        XPROPERTY(xtl::xoptional<double>, Header, titlePadding);
    };

    void to_json(nl::json& j, const Header& data);
}

#endif