#pragma once

#include <cassert>

namespace gcd
{
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    void tests() {
        assert(gcd(2, 10) == 2);
        assert(gcd(0, 0) == 0);
    }
}
