#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "strassen.h"

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
    switch(argc)
    {
        case 1:
            test(10, 2);
            break;
        case 2:
            test(atoi(argv[1]), 2);
            break;
        case 3:
            test(atoi(argv[1]), atoi(argv[2]));
            break;
        case 4:
            g_break = atoi(argv[3]);
            test(atoi(argv[1]), atoi(argv[2]));
            break;
        default:
            test(10, 2);
            break;
    }
    return 0;
}
