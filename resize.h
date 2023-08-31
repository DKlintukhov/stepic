#pragma once

#include <iostream>

namespace resize
{
    char *resize(const char *mem, unsigned size, unsigned new_size)
    {
        char *new_mem = new char[new_size];
        std::copy(mem, mem + std::min(size, new_size), new_mem);
        delete[] mem;
        return new_mem;
    }

    char *getline()
    {
        const int BUF_LEN = 50;

        int len = BUF_LEN;
        int i = 0;

        char *str = (char *)malloc(BUF_LEN * sizeof(char)), c;
        while (std::cin.get(c) && c != '\n')
        {
            if (i == len)
                str = (char *)realloc(str, len += BUF_LEN);
            str[i++] = c;
        }

        char *rez = new char[i + 1];
        for (int j = 0; j < i; ++j)
            rez[j] = str[j];

        rez[i] = 0;

        free(str);
        return rez;
    }
}
