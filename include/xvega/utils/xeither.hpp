#ifndef XVEGA_EITHER_HPP
#define XVEGA_EITHER_HPP

#include <stdexcept>
#include <string>
#include <unordered_set>

#include "xtl/xoptional.hpp"

#define XEITHER(...)                                                         \
    [](const auto& proposal) {                                               \
        static const std::unordered_set<std::string> options({__VA_ARGS__}); \
        auto position = options.find(proposal);                              \
        if (position == options.end())                                       \
        {                                                                    \
            throw std::runtime_error("Invalid proposal for string enum");    \
        }                                                                    \
    }

#define XEITHER_OPTIONAL(...)                                                          \
    [](const auto& proposal) {                                                         \
        if (xtl::has_value(proposal))                                                  \
        {                                                                              \
            static const std::unordered_set<std::string> options({__VA_ARGS__});       \
            auto position = options.find(xtl::value(proposal));                        \
            if (position == options.end())                                             \
            {                                                                          \
                throw std::runtime_error("Invalid proposal for optional string enum"); \
            }                                                                          \
        }                                                                              \
    }

#endif