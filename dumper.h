#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

namespace dumper
{
    /**
     * Dumps a memory map to the specified output stream
     *
     * Inputs:
     *
     *   names     - list of item names
     *   addrs     - list of addresses to different items
     *   lengths   - length of each item
     *   count     - number of items being dumped
     *   stream    - output destination
     *
     * Outputs: none
     * Returns: none
     */
    void dumper(char **names, const void **addrs, size_t *lengths, size_t count, FILE *stream)
    {
        size_t i;
        int maxlen = 15;

        for (size_t j = 0; j < count; j++)
        {
            if (strlen(names[j]) > maxlen && strlen(names[j]) < 50)
                maxlen = strlen(names[j]);
        }

        fprintf(stream, "%*s%15s%5s%5s%5s%5s\n", maxlen, "Item", "Address", "00", "01",
                "02", "03");
        fprintf(stream, "%*s%15s%5s%5s%5s%5s\n", maxlen, "----", "-------", "--", "--",
                "--", "--");

        for (i = 0; i < count; i++)
        {
            size_t j;
            char *namefield = names[i];
            unsigned char *p = (unsigned char *)addrs[i];
            for (j = 0; j < lengths[i]; j += 4)
            {
                size_t k;

                fprintf(stream, "%*.*s", maxlen, maxlen, namefield);
                fprintf(stream, "%15p", (void *)p);
                for (k = 0; k < 4; k++)
                {
                    fprintf(stream, "%3s%02x", " ", p[k]);
                }
                fprintf(stream, "    ");
                for (k = 0; k < 4; k++)
                {
                    if (isgraph(p[k]))
                        fprintf(stream, "%c", p[k]);
                    else
                        fprintf(stream, ".");
                }
                fputc('\n', stream);
                namefield = " ";
                p += 4;
            }
            fputc('\n', stream);
        }
    }

    void tests()
    {
        int x = 0;
        double y = 3.14159;
        char foo[] = "This is a test";
        const void *addrs[] = {&x, &y, foo, "This is a test"};
        char *names[] = {"x", "y", "foo", "\"This is a test\""};
        size_t lengths[] = {sizeof x, sizeof y, sizeof foo, sizeof "This is a test"};

        dumper(names, addrs, lengths, 4, stdout);
    }

} // namespace dumper
