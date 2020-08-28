// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_RANDOM_STRING_HPP
#define XVEGA_RANDOM_STRING_HPP

#include <random>

namespace xv
{
    std::string random_string(int len)
    {
        const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(0, (int)(CHARACTERS.length()-1));

        std::string random_str;

        for(int i=0; i<len; i++)
        {
            random_str += CHARACTERS[distrib(gen)];
        }

        return random_str;
    }
}

#endif