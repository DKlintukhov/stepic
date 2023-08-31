#include "gcd.h"
#include "rotate.h"
#include "strlen.h"
#include "dumper.h"
#include "string.h"

int main(int argc, char const *argv[])
{
    gcd::tests();
    rotate::tests();
    mystrlen::tests();
    my_string::String s("Hello");
    s.append("World");
    dumper::tests();

    return 0;
}
