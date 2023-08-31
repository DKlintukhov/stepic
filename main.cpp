#include "gcd.h"
#include "rotate.h"
#include "strlen.h"
#include "dumper.h"
#include "string.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    gcd::tests();
    rotate::tests();
    mystrlen::tests();
    dumper::tests();

    return 0;
}
