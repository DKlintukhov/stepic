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

        for (int j = 0; j < size; j++)
        {
            std::cout << a[j] << std::endl;
        }
    }

    void tests()
    {
        int a[] = {1, 2, 3};
        rotate(a, 3, 2);
        assert(a[0] == 2);
        assert(a[1] == 3);
        assert(a[2] == 1);
    }
}
