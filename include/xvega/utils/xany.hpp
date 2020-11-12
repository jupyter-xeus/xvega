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
        class xany_impl;
    }

    /***********************
     * xany declaration *
     ***********************/

    template <template <class> class CRTP>
    class xany
    {
    public:

        using implementation_type = detail::xany_impl<CRTP>;

        xany();
        ~xany();
        xany(const xany& rhs);
        xany(xany&& rhs);
        template <class D>
        xany(const CRTP<D>& rhs);
        template <class D>
        xany(CRTP<D>&& rhs);
        xany(implementation_type* any);

        xany& operator=(const xany& rhs);
        xany& operator=(xany&& rhs);

        template <class D>
        xany& operator=(const CRTP<D>& rhs);
        template <class D>
        xany& operator=(CRTP<D>&& rhs);

        void swap(xany& rhs);

        void to_json(nl::json& j) const;
        std::string name() const;

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
    inline void swap(xany<CRTP>& lhs, xany<CRTP>& rhs);

    template <template <class> class CRTP, class D>
    xany<CRTP> make_any(CRTP<D>&& value);

    /***********************
     * to_json declaration *
     ***********************/

    template <template <class> class CRTP>
    void to_json(nl::json& j, const xany<CRTP>& o);

    /**************************
     * any implementations *
     **************************/

    namespace detail
    {
        template <template <class> class CRTP>
        class xany_impl
        {
        public:

            xany_impl() = default;
            xany_impl(xany_impl&&) = delete;
            xany_impl& operator=(const xany_impl&) = delete;
            xany_impl& operator=(xany_impl&&) = delete;
            virtual xany_impl* clone() const = 0;
            virtual ~xany_impl() = default;

            virtual void to_json(nl::json& j) const = 0;
            virtual std::string name() const = 0;

            virtual xtl::any value() & = 0;
            virtual const xtl::any value() const & = 0;

        protected:

            xany_impl(const xany_impl&) = default;
        };

        template <template <class> class CRTP, class D>
        class xany_owning : public xany_impl<CRTP>
        {
        public:

            using base_type = xany_impl<CRTP>;

            xany_owning(const CRTP<D>& value)
                : base_type(),
                  m_value(value.derived_cast())
            {
            }

            xany_owning(CRTP<D>&& value)
                : base_type(),
                  m_value(std::move(value.derived_cast()))
            {
            }

            virtual ~xany_owning()
            {
            }

            virtual base_type* clone() const override
            {
                return new xany_owning(*this);
            }

            virtual void to_json(nl::json& j) const override
            {
                xv::to_json(j, m_value);
            }

            virtual std::string name() const override
            {
                return m_value.name();
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

            xany_owning(const xany_owning&) = default;
            xany_owning(xany_owning&&) = default;
            xany_owning& operator=(const xany_owning&) = default;
            xany_owning& operator=(xany_owning&&) = default;

            D m_value;
        };
    }

    template <template <class> class CRTP, class D>
    xany<CRTP> make_any(CRTP<D>&& value)
    {
        return xany<CRTP>(new detail::xany_owning<CRTP, D>(std::move(value)));
    }

    template <template <class> class CRTP, class D>
    xany<CRTP> make_any(const CRTP<D>& value)
    {
        return xany<CRTP>(new detail::xany_owning<CRTP, D>(value));
    }

    /**************************
     * xany implementation *
     **************************/

    template <template <class> class CRTP>
    xany<CRTP>::xany()
        : p_any(nullptr)
    {
    }

    template <template <class> class CRTP>
    xany<CRTP>::xany(detail::xany_impl<CRTP>* any)
        : p_any(any)
    {
    }

    template <template <class> class CRTP>
    xany<CRTP>::~xany()
    {
        delete p_any;
    }

    template <template <class> class CRTP>
    xany<CRTP>::xany(const xany& rhs)
        : p_any(rhs.p_any ? rhs.p_any->clone() : nullptr)
    {
    }

    template <template <class> class CRTP>
    template <class D>
    xany<CRTP>::xany(const CRTP<D>& rhs)
        : xany(make_any<CRTP>(rhs))
    {
    }

    template <template <class> class CRTP>
    template <class D>
    xany<CRTP>::xany(CRTP<D>&& rhs)
        : xany(make_any(std::move(rhs)))
    {
    }

    template <template <class> class CRTP>
    xany<CRTP>::xany(xany&& rhs)
        : p_any(rhs.p_any)
    {
        rhs.p_any = nullptr;
    }

    template <template <class> class CRTP>
    xany<CRTP>& xany<CRTP>::operator=(const xany& rhs)
    {
        using std::swap;
        xany tmp(rhs);
        swap(*this, tmp);
        return *this;
    }

    template <template <class> class CRTP>
    xany<CRTP>& xany<CRTP>::operator=(xany&& rhs)
    {
        using std::swap;
        xany tmp(std::move(rhs));
        swap(*this, tmp);
        return *this;
    }

    template <template <class> class CRTP>
    template <class D>
    xany<CRTP>& xany<CRTP>::operator=(const CRTP<D>& rhs)
    {
        using std::swap;
        xany<CRTP> tmp(make_any<CRTP>(rhs));
        swap(tmp, *this);
        return *this;
    }

    template <template <class> class CRTP>
    template <class D>
    xany<CRTP>& xany<CRTP>::operator=(CRTP<D>&& rhs)
    {
        using std::swap;
        xany<CRTP> tmp(make_any(std::move(rhs)));
        swap(tmp, *this);
        return *this;
    }

    template <template <class> class CRTP>
    void xany<CRTP>::swap(xany& rhs)
    {
        std::swap(p_any, rhs.p_any);
    }

    template <template <class> class CRTP>
    void xany<CRTP>::to_json(nl::json& j) const
    {
        if (p_any)
        {
            p_any->to_json(j);
        }
    }

    template <template <class> class CRTP>
    std::string xany<CRTP>::name() const
    {
        check_any();
        p_any->name();
    }

    template <template <class> class CRTP>
    xtl::any xany<CRTP>::value() &
    {
        check_any();
        return p_any->value();
    }

    template <template <class> class CRTP>
    const xtl::any xany<CRTP>::value() const &
    {
        check_any();
        return p_any->value();
    }

    template <template <class> class CRTP>
    template <class D>
    D& xany<CRTP>::get() &
    {
        return xtl::any_cast<xtl::closure_wrapper<D&>>(this->value()).get();
    }

    template <template <class> class CRTP>
    template <class D>
    const D& xany<CRTP>::get() const &
    {
        return xtl::any_cast<xtl::closure_wrapper<const D&>>(this->value()).get();
    }

    template <template <class> class CRTP>
    void xany<CRTP>::check_any() const
    {
        if (p_any == nullptr)
        {
            throw std::runtime_error("Empty xany");
        }
    }

    template <template <class> class CRTP>
    inline void swap(xany<CRTP>& lhs, xany<CRTP>& rhs)
    {
        lhs.swap(rhs);
    }

    /****************************************
     * to_json and from_json implementation *
     ****************************************/

    template <template <class> class CRTP>
    inline void to_json(nl::json& j, const xany<CRTP>& o)
    {
         o.to_json(j);
    }
}

#endif
