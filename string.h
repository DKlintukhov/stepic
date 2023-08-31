#include <cstddef>
#include <cstring>

namespace my_string
{
    struct String
    {
        String(size_t n, char c)
        {
            this->size = n;
            this->str = new char[this->size + 1];
            this->init_str(this->size, this->str, c);
        }

        String(const char *str = "")
        {
            this->size = std::strlen(str);
            this->str = new char[this->size + 1];
            std::strcpy(this->str, str);
        }

        ~String()
        {
            delete[] this->str;
        }

        void append(const String &other)
        {
            size += other.size;
            char *m = new char[size + 1];
            std::strcpy(m, str);
            std::strcat(m, other.str);
            delete[] str;
            str = m;
        }

    private:
        void init_str(size_t index, char *str, char c)
        {
            for (size_t i = 0; i != index; i++)
            {
                str[i] = c;
            }

            str[index + 1] = '\0';
        }

        size_t size;
        char *str;
    };
}
