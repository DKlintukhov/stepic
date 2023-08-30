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

    int mystrstr(const char *text, const char *pattern)
    {
        if (*pattern == '\0')
            return 0;
        if (mystrlen(text) < mystrlen(pattern))
            return -1;

        int position = 0;

        while (*text != '\0')
        {
            if (*text == *pattern)
            {
                int textStep = 0;
                int patternStep = 0;
                while (*(text + textStep) == *(pattern + patternStep))
                {
                    textStep++;
                    patternStep++;
                    if (*(pattern + patternStep) == '\0')
                        return position;
                }
            };
            text++;
            position++;
        }

        return -1;
    }

    void tests()
    {
        assert(mystrlen("Hello") == 5);
    }
}