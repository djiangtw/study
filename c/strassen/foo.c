#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "strassen.h"

/**
 * @brief main      the entry of this project.
 *
 * @param argc      the number of string parameters.
 * @param argv[]    the content of input string parameters.
 *  argv[0]         the command name
 *  argv[1]         the dimension of the test square matrices.
 *  argv[2]         the operations of the test.
 *  argv[3]         the number of g_break used in strassen algorithm.
 *  others          reserved.
 *
 * @return int      0 as program finished well.
 */
int main(int argc, const char *argv[])
{
    /* validate the input parameters and apply a valid parameters
     * to the test.
     */
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
