#pragma once

#include <iostream>
#include <vector>

template <typename T>
void flatten(const std::vector<T> &array, std::ostream &out)
{
    size_t i = 0;
    while (i < array.size())
    {
        out << array[i] << " ";
        ++i;
    }
}

template <typename T>
void flatten(const std::vector<std::vector<T>> &array, std::ostream &out)
{
    size_t i = 0;
    while (i < array.size())
    {
        flatten(array[i], out);
        ++i;
    }
}
