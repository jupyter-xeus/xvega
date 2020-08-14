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

namespace nl = nlohmann;

namespace xv
{
    using stringVecNoneType = xtl::variant<std::vector<std::string>, std::nullptr_t>;
    using stringObjectType = xtl::variant<nl::json, std::string>;
    using stringNoneType = xtl::variant<std::nullptr_t, std::string>;
    using stringNumType = xtl::variant<double, int, std::string>;

    struct Header : public xp::xobserved<Header>
    {
        XPROPERTY(xtl::xoptional<stringVecNoneType>, Header, title);

        XPROPERTY(xtl::xoptional<stringObjectType>, Header, format);
        XPROPERTY(xtl::xoptional<std::string>, Header, formatType);

        XPROPERTY(xtl::xoptional<std::string>, Header, labelAlign);
        XPROPERTY(xtl::xoptional<stringNoneType>, Header, labelAnchor);
        XPROPERTY(xtl::xoptional<double>, Header, labelAngle);
        XPROPERTY(xtl::xoptional<std::string>, Header, labelBaseline);
        XPROPERTY(xtl::xoptional<stringNoneType>, Header, labelColor);
        XPROPERTY(xtl::xoptional<std::string>, Header, labelExpr);
        XPROPERTY(xtl::xoptional<std::string>, Header, labelFont);
        XPROPERTY(xtl::xoptional<double>, Header, labelFontSize);
        XPROPERTY(xtl::xoptional<std::string>, Header, labelFontStyle);
        XPROPERTY(xtl::xoptional<stringNumType>, Header, labelFontWeight);
        XPROPERTY(xtl::xoptional<double>, Header, labelLimit);
        XPROPERTY(xtl::xoptional<double>, Header, labelLineHeight);
        XPROPERTY(xtl::xoptional<std::string>, Header, labelOrient);
        XPROPERTY(xtl::xoptional<double>, Header, labelPadding);

        XPROPERTY(xtl::xoptional<bool>, Header, labels);
        XPROPERTY(xtl::xoptional<std::string>, Header, orient);

        XPROPERTY(xtl::xoptional<std::string>, Header, titleAlign);
        XPROPERTY(xtl::xoptional<stringNoneType>, Header, titleAnchor);
        XPROPERTY(xtl::xoptional<double>, Header, titleAngle);
        XPROPERTY(xtl::xoptional<std::string>, Header, titleBaseline);
        XPROPERTY(xtl::xoptional<stringNoneType>, Header, titleColor);
        XPROPERTY(xtl::xoptional<std::string>, Header, titleFont);
        XPROPERTY(xtl::xoptional<double>, Header, titleFontSize);
        XPROPERTY(xtl::xoptional<std::string>, Header, titleFontStyle);
        XPROPERTY(xtl::xoptional<stringNumType>, Header, titleFontWeight);
        XPROPERTY(xtl::xoptional<double>, Header, titleLimit);
        XPROPERTY(xtl::xoptional<double>, Header, titleLineHeight);
        XPROPERTY(xtl::xoptional<std::string>, Header, titleOrient);
        XPROPERTY(xtl::xoptional<double>, Header, titlePadding);
    };

    void to_json(nl::json& j, const Header& data)
    {
        if(data.title().has_value())
        {
            j["title"] = data.title().value();
        }
        if(data.format().has_value())
        {
            j["format"] = data.format().value();
        }
        if(data.formatType().has_value())
        {
            j["formatType"] = data.formatType().value();
        }
        if(data.labels().has_value())
        {
            j["labels"] = data.labels().value();
        }
        if(data.orient().has_value())
        {
            j["orient"] = data.orient().value();
        }
        if(data.labelAlign().has_value())
        {
            j["labelAlign"] = data.labelAlign().value();
        }
        if(data.labelAnchor().has_value())
        {
            j["labelAnchor"] = data.labelAnchor().value();
        }
        if(data.labelAngle().has_value())
        {
            j["labelAngle"] = data.labelAngle().value();
        }
        if(data.labelBaseline().has_value())
        {
            j["labelBaseline"] = data.labelBaseline().value();
        }
        if(data.labelColor().has_value())
        {
            j["labelColor"] = data.labelColor().value();
        }
        if(data.labelExpr().has_value())
        {
            j["labelExpr"] = data.labelExpr().value();
        }
        if(data.labelFont().has_value())
        {
            j["labelFont"] = data.labelFont().value();
        }
        if(data.labelFontSize().has_value())
        {
            j["labelFontSize"] = data.labelFontSize().value();
        }
        if(data.labelFontStyle().has_value())
        {
            j["labelFontStyle"] = data.labelFontStyle().value();
        }
        if(data.labelFontWeight().has_value())
        {
            j["labelFontWeight"] = data.labelFontWeight().value();
        }
        if(data.labelLimit().has_value())
        {
            j["labelLimit"] = data.labelLimit().value();
        }
        if(data.labelLineHeight().has_value())
        {
            j["labelLineHeight"] = data.labelLineHeight().value();
        }
        if(data.labelOrient().has_value())
        {
            j["labelOrient"] = data.labelOrient().value();
        }
        if(data.labelPadding().has_value())
        {
            j["labelPadding"] = data.labelPadding().value();
        }
        if(data.titleAlign().has_value())
        {
            j["titleAlign"] = data.titleAlign().value();
        }
        if(data.titleAnchor().has_value())
        {
            j["titleAnchor"] = data.titleAnchor().value();
        }
        if(data.titleAngle().has_value())
        {
            j["titleAngle"] = data.titleAngle().value();
        }
        if(data.titleBaseline().has_value())
        {
            j["titleBaseline"] = data.titleBaseline().value();
        }
        if(data.titleColor().has_value())
        {
            j["titleColor"] = data.titleColor().value();
        }
        if(data.titleFont().has_value())
        {
            j["titleFont"] = data.titleFont().value();
        }
        if(data.titleFontSize().has_value())
        {
            j["titleFontSize"] = data.titleFontSize().value();
        }
        if(data.titleFontStyle().has_value())
        {
            j["titleFontStyle"] = data.titleFontStyle().value();
        }
        if(data.titleFontWeight().has_value())
        {
            j["titleFontWeight"] = data.titleFontWeight().value();
        }
        if(data.titleLimit().has_value())
        {
            j["titleLimit"] = data.titleLimit().value();
        }
        if(data.titleLineHeight().has_value())
        {
            j["titleLineHeight"] = data.titleLineHeight().value();
        }
        if(data.titleOrient().has_value())
        {
            j["titleOrient"] = data.titleOrient().value();
        }
        if(data.titlePadding().has_value())
        {
            j["titlePadding"] = data.titlePadding().value();
        }
    }
}

#endif