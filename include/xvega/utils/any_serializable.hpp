// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ANY_HPP
#define XVEGA_ANY_HPP

#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

#include "nlohmann/json.hpp"

#include "xtl/xany.hpp"
#include "xtl/xclosure.hpp"

namespace nl = nlohmann;

namespace xv
{
    namespace detail
    {
        template <template <class> class CRTP>
        class xany_vega_impl;
    }

    /***********************
     * xany_vega declaration *
     ***********************/

    template <template <class> class CRTP>
    class xany_vega
    {
    public:

        using implementation_type = detail::xany_vega_impl<CRTP>;

        xany_vega();
        ~xany_vega();
        xany_vega(const xany_vega& rhs);
        xany_vega(xany_vega&& rhs);
        template <class D>
        xany_vega(const CRTP<D>& rhs);
        template <class D>
        xany_vega(CRTP<D>&& rhs);
        xany_vega(implementation_type* any);

        xany_vega& operator=(const xany_vega& rhs);
        xany_vega& operator=(xany_vega&& rhs);

        template <class D>
        xany_vega& operator=(const CRTP<D>& rhs);
        template <class D>
        xany_vega& operator=(CRTP<D>&& rhs);

        void swap(xany_vega& rhs);

        void to_json(nl::json& j) const;

        xtl::any value() &;
        const xtl::any value() const &;

        template <class D>
        D& get() &;
        template <class D>
        const D& get() const &;

    private:

        void check_any() const;

        implementation_type* p_any;
    };

    template <template <class> class CRTP>
    inline void swap(xany_vega<CRTP>& lhs, xany_vega<CRTP>& rhs);

    template <template <class> class CRTP, class D>
    xany_vega<CRTP> make_any(CRTP<D>&& value);

    /***********************
     * to_json declaration *
     ***********************/

    template <template <class> class CRTP>
    void to_json(nl::json& j, const xany_vega<CRTP>& o);

    /**************************
     * any implementations *
     **************************/

    namespace detail
    {
        template <template <class> class CRTP>
        class xany_vega_impl
        {
        public:

            xany_vega_impl() = default;
            xany_vega_impl(xany_vega_impl&&) = delete;
            xany_vega_impl& operator=(const xany_vega_impl&) = delete;
            xany_vega_impl& operator=(xany_vega_impl&&) = delete;
            virtual xany_vega_impl* clone() const = 0;
            virtual ~xany_vega_impl() = default;

            virtual void to_json(nl::json& j) const = 0;

            virtual xtl::any value() & = 0;
            virtual const xtl::any value() const & = 0;

        protected:

            xany_vega_impl(const xany_vega_impl&) = default;
        };

        template <template <class> class CRTP, class D>
        class xany_vega_owning : public xany_vega_impl<CRTP>
        {
        public:

            using base_type = xany_vega_impl<CRTP>;

            xany_vega_owning(const CRTP<D>& value)
                : base_type(),
                  m_value(value.derived_cast())
            {
            }

            xany_vega_owning(CRTP<D>&& value)
                : base_type(),
                  m_value(std::move(value.derived_cast()))
            {
            }

            virtual ~xany_vega_owning()
            {
            }

            virtual base_type* clone() const override
            {
                return new xany_vega_owning(*this);
            }

            virtual void to_json(nl::json& j) const override
            {
                m_value.to_json(j);
            }

            virtual xtl::any value() & override
            {
                return xtl::closure(m_value);
            }

            virtual const xtl::any value() const & override
            {
                return xtl::closure(m_value);
            }

        private:

            xany_vega_owning(const xany_vega_owning&) = default;
            xany_vega_owning(xany_vega_owning&&) = default;
            xany_vega_owning& operator=(const xany_vega_owning&) = default;
            xany_vega_owning& operator=(xany_vega_owning&&) = default;

            D m_value;
        };
    }

    template <template <class> class CRTP, class D>
    xany_vega<CRTP> make_any(CRTP<D>&& value)
    {
        return xany_vega<CRTP>(new detail::xany_vega_owning<CRTP, D>(std::move(value)));
    }

    template <template <class> class CRTP, class D>
    xany_vega<CRTP> make_any(const CRTP<D>& value)
    {
        return xany_vega<CRTP>(new detail::xany_vega_owning<CRTP, D>(value));
    }

    /**************************
     * xany_vega implementation *
     **************************/

    template <template <class> class CRTP>
    xany_vega<CRTP>::xany_vega()
        : p_any(nullptr)
    {
    }

    template <template <class> class CRTP>
    xany_vega<CRTP>::xany_vega(detail::xany_vega_impl<CRTP>* any)
        : p_any(any)
    {
    }

    template <template <class> class CRTP>
    xany_vega<CRTP>::~xany_vega()
    {
        delete p_any;
    }

    template <template <class> class CRTP>
    xany_vega<CRTP>::xany_vega(const xany_vega& rhs)
        : p_any(rhs.p_any ? rhs.p_any->clone() : nullptr)
    {
    }

    template <template <class> class CRTP>
    template <class D>
    xany_vega<CRTP>::xany_vega(const CRTP<D>& rhs)
        : xany_vega(make_any<CRTP>(rhs))
    {
    }

    template <template <class> class CRTP>
    template <class D>
    xany_vega<CRTP>::xany_vega(CRTP<D>&& rhs)
        : xany_vega(make_any(std::move(rhs)))
    {
    }

    template <template <class> class CRTP>
    xany_vega<CRTP>::xany_vega(xany_vega&& rhs)
        : p_any(rhs.p_any)
    {
        rhs.p_any = nullptr;
    }

    template <template <class> class CRTP>
    xany_vega<CRTP>& xany_vega<CRTP>::operator=(const xany_vega& rhs)
    {
        using std::swap;
        xany_vega tmp(rhs);
        swap(*this, tmp);
        return *this;
    }

    template <template <class> class CRTP>
    xany_vega<CRTP>& xany_vega<CRTP>::operator=(xany_vega&& rhs)
    {
        using std::swap;
        xany_vega tmp(std::move(rhs));
        swap(*this, tmp);
        return *this;
    }

    template <template <class> class CRTP>
    template <class D>
    xany_vega<CRTP>& xany_vega<CRTP>::operator=(const CRTP<D>& rhs)
    {
        using std::swap;
        xany_vega<CRTP> tmp(make_any<CRTP>(rhs));
        swap(tmp, *this);
        return *this;
    }

    template <template <class> class CRTP>
    template <class D>
    xany_vega<CRTP>& xany_vega<CRTP>::operator=(CRTP<D>&& rhs)
    {
        using std::swap;
        xany_vega<CRTP> tmp(make_any(std::move(rhs)));
        swap(tmp, *this);
        return *this;
    }

    template <template <class> class CRTP>
    void xany_vega<CRTP>::swap(xany_vega& rhs)
    {
        std::swap(p_any, rhs.p_any);
    }

    template <template <class> class CRTP>
    void xany_vega<CRTP>::to_json(nl::json& j) const
    {
        check_any();
        p_any->to_json(j);
    }

    template <template <class> class CRTP>
    xtl::any xany_vega<CRTP>::value() &
    {
        check_any();
        return p_any->value();
    }

    template <template <class> class CRTP>
    const xtl::any xany_vega<CRTP>::value() const &
    {
        check_any();
        return p_any->value();
    }

    template <template <class> class CRTP>
    template <class D>
    D& xany_vega<CRTP>::get() &
    {
        return xtl::any_cast<xtl::closure_wrapper<D&>>(this->value()).get();
    }

    template <template <class> class CRTP>
    template <class D>
    const D& xany_vega<CRTP>::get() const &
    {
        return xtl::any_cast<xtl::closure_wrapper<const D&>>(this->value()).get();
    }

    template <template <class> class CRTP>
    void xany_vega<CRTP>::check_any() const
    {
        if (p_any == nullptr)
        {
            throw std::runtime_error("Empty");
        }
    }

    template <template <class> class CRTP>
    inline void swap(xany_vega<CRTP>& lhs, xany_vega<CRTP>& rhs)
    {
        lhs.swap(rhs);
    }

    /****************************************
     * to_json and from_json implementation *
     ****************************************/

    template <template <class> class CRTP>
    inline void to_json(nl::json& j, const xany_vega<CRTP>& o)
    {
         o.to_json(j);
    }
}

#endif
