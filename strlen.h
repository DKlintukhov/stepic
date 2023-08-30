#pragma once

#include <cassert>

namespace mystrlen
{
    unsigned mystrlen(const char *str)
    {
        unsigned len = 0;
        while (*str != '\0')
        {
            str++;
            len++;
        }

        return len;
    }

    void tests() {
        assert(mystrlen("Hello") == 5);
    }
}