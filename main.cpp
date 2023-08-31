#include "gcd.h"
#include "rotate.h"
#include "strlen.h"
#include "dumper.h"

int main(int argc, char const *argv[])
{
    gcd::tests();
    rotate::tests();
    mystrlen::tests();
    dumper::tests();

    return 0;
}
