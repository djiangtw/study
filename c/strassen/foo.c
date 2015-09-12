#include <stdio.h>
#include <stdlib.h>

extern void test(int n);

/**
 * @brief main
 *
 * @param argc
 * @param argv[]
 *
 * @return int
 */
int main(int argc, const char *argv[])
{
    printf("%s\n", "== start ==");
    test(atoi(argv[1]));
    /*
     *test(1000);
     */
    return 0;
}
