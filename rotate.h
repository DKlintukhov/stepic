#pragma once

#include <vector>
#include <cassert>
#include <iostream>

namespace rotate
{
    void rotate(int *a, unsigned size, int shift)
    {
        for (int i = 0; i < shift; i++)
        {
            for (int j = 1; j < size; j++)
            {
                std::swap(a[j], a[j - 1]);
            }
        }
    }

    void tests()
    {
        int a[] = {1, 2, 3, 4, 5};
        rotate(a, 5, 2);
        assert(a[0] == 3);
        assert(a[1] == 4);
        assert(a[2] == 5);
        assert(a[3] == 1);
        assert(a[4] == 2);
    }
}
