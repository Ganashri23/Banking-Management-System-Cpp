#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

using namespace std;

namespace Utility
{
    template <typename T>
    void print(T value)
    {
        cout << value << endl;
    }
}

#endif