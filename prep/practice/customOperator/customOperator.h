#pragma once
#include <string>

#define contains == CustomOperator_contains() ==

class CustomOperator_contains
{
public:
    CustomOperator_contains() {}
    std::string m_sLeft;
};
inline CustomOperator_contains &operator==(const std::string &&l,  CustomOperator_contains &&mid)
{
    mid.m_sLeft = l;
    return mid;
}
inline bool operator==(CustomOperator_contains &mid, const std::string &&r)
{
    return mid.m_sLeft.find(r) != std::string::npos;
}