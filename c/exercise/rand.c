/*
 * =====================================================================================
 *
 *       Filename:  rand.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年01月19日 14時43分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void my_exit(void)
{
    printf("%s %s\n", __FILE__, "is finished successfully.");
}

void my_exit2(void)
{
    printf("%s\n", __TIME__);
}

int my_rand(void)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        printf("%d ", rand() % 100);
    }
    printf("\n");
    return EXIT_SUCCESS;
}

int main(int argc, const char *argv[])
{
    atexit(my_exit);
    atexit(my_exit2);

    my_rand();
    exit(EXIT_SUCCESS);
}
