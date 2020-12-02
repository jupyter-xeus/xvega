// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_CONFIG_HPP
#define XVEGA_CONFIG_HPP

#ifdef _WIN32
    #ifdef XVEGA_STATIC_LIB
        #define XVEGA_API
    #else
        #ifdef XVEGA_EXPORTS
            #define XVEGA_API __declspec(dllexport)
        #else
            #define XVEGA_API __declspec(dllimport)
        #endif
    #endif
#else
    #define XVEGA_API
#endif

#define XVEGA_VERSION_MAJOR 0
#define XVEGA_VERSION_MINOR 0
#define XVEGA_VERSION_PATCH 6

#ifdef __CLING__
#include "xvega_config_cling.hpp"
#endif

#endif
