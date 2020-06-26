#pragma once
#include <bits/stdc++.h>

template <class T>
class Utils
{
    /**
     * @brief Private constructor to avoid instantiation
     * 
     */
    Utils() {}

public:
    /**
     * @brief Utility to compute square
     * 
     * @param x 
     * @return T 
     */
    static T square(T x)
    {
        return x * x;
    }
};