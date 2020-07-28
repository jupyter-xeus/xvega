#include "xproperty/xobserved.hpp"

struct X : public xp::xobserved<X>
{
    XPROPERTY(std::string, X, field);
    XPROPERTY(std::string, X, type);
};

struct Y : public xp::xobserved<Y>
{
    XPROPERTY(std::string, Y, field);
    XPROPERTY(std::string, Y, type);
};

struct Color : public xp::xobserved<Color>
{
    XPROPERTY(std::string, Color, field);
    XPROPERTY(std::string, Color, type);
};

struct Encodings : public xp::xobserved<Encodings>
{
    XPROPERTY(X, Encodings, x);
    XPROPERTY(Y, Encodings, y);
    XPROPERTY(Color, Encodings, color);
};