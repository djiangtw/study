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

int my_rand()
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
    printf("%s\n", "rand program");

    my_rand();
    return 0;
}
