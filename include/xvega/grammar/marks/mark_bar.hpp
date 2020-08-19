// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_MARK_BAR
#define XVEGA_MARK_BAR

#include "../marks.hpp"

namespace xv
{
    struct mark_bar : public Marks<mark_bar>
    {
        using base_type = Marks<mark_bar>;

        // Bar Mark Properties
        XPROPERTY(xtl::xoptional<std::string>, mark_bar, orient, xtl::missing<std::string>(), XEITHER_OPTIONAL("horizontal", "vertical"));
        XPROPERTY(xtl::xoptional<std::string>, mark_bar, align, xtl::missing<std::string>(), XEITHER_OPTIONAL("left", "right", "center"));
        XPROPERTY(xtl::xoptional<std::string>, mark_bar, baseline, xtl::missing<std::string>(), XEITHER_OPTIONAL("alphabetic", "top", "middle", "bottom", "line-top", "line-bottom"));
        XPROPERTY(xtl::xoptional<double>, mark_bar, binSpacing);
        XPROPERTY(xtl::xoptional<double>, mark_bar, cornerRadius);
        XPROPERTY(xtl::xoptional<double>, mark_bar, cornerRadiusEnd);
        XPROPERTY(xtl::xoptional<double>, mark_bar, cornerRadiusTopLeft);
        XPROPERTY(xtl::xoptional<double>, mark_bar, cornerRadiusTopRight);
        XPROPERTY(xtl::xoptional<double>, mark_bar, cornerRadiusBottomLeft);
        XPROPERTY(xtl::xoptional<double>, mark_bar, cornerRadiusBottomRight);

        mark_bar()
        {
            type = "bar";
        }

        void to_json(nl::json& j) const
        {
            base_type::to_json(j);
            // Fill in Bar Mark Properties
            if(orient().has_value())
            {
                j["orient"] = orient().value();
            }
            if(align().has_value())
            {
                j["align"] = align().value();
            }
            if(baseline().has_value())
            {
                j["baseline"] = baseline().value();
            }
            if(binSpacing().has_value())
            {
                j["binSpacing"] = binSpacing().value();
            }
            if(cornerRadius().has_value())
            {
                j["cornerRadius"] = cornerRadius().value();
            }
            if(cornerRadiusEnd().has_value())
            {
                j["cornerRadiusEnd"] = cornerRadiusEnd().value();
            }
            if(cornerRadiusTopLeft().has_value())
            {
                j["cornerRadiusTopLeft"] = cornerRadiusTopLeft().value();
            }
            if(cornerRadiusTopRight().has_value())
            {
                j["cornerRadiusTopRight"] = cornerRadiusTopRight().value();
            }
            if(cornerRadiusBottomLeft().has_value())
            {
                j["cornerRadiusBottomLeft"] = cornerRadiusBottomLeft().value();
            }
            if(cornerRadiusBottomRight().has_value())
            {
                j["cornerRadiusBottomRight"] = cornerRadiusBottomRight().value();
            }
        }
    };
}

#endif
