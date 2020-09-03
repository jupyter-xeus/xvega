// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/utils/random_string.hpp"

namespace xv
{
    std::string random_string(int len)
    {
        const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, (int)(CHARACTERS.length()-1));

        std::string random_str;

        for(int i=0; i<len; i++)
        {
            random_str += CHARACTERS[distrib(gen)];
        }

        return random_str;
    }
}