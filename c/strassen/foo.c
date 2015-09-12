#include <stdio.h>
#include <stdlib.h>

extern void test(int n);

int main(int argc, const char *argv[])
{
    printf("%s\n", "== start ==");
    test(atoi(argv[1]));
    return 0;
}
