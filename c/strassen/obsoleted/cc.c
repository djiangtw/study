/*
 * =====================================================================================
 *
 *       Filename:  cc.c
 *
 *    Description:  test
 *
 *        Version:  1.0
 *        Created:  09/14/2015 02:26:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Danny Jiang (), xinyi904314@yahoo.com.tw
 *   Organization:  Freelancer
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    clock_t start, end;
    double cpu_time_used;
    unsigned int i = 10000000;

    start = clock();

    while(i--)
    {

    };
    end = clock();
    printf("%f\n", difftime(end, start));
    printf("%ld\n", CLOCKS_PER_SEC);
    return 0;
}

