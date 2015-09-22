/*
 * =====================================================================================
 *
 *       Filename:  moveZeros.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2015  4:24:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Danny Jiang (), xinyi904314@yahoo.com.tw
 *   Organization:  Freelancer
 *
 * =====================================================================================
 */
#include <stdio.h>

int n[] = 
{
    1, 3, 4, 0, 0,
    2, 4, 0, 7, 0
};

void swap(int* a, int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void moveZeroes(int* nums, int numsSize) {
    int i;
    int j;
    for(i = 0; i < numsSize; i++)
    {
        if(0 == nums[i])
        {
            numsSize--;
            for(j = i; j < numsSize; j++)
            {
                swap(&nums[j], &nums[j + 1]);
            }
            i--;
        }
    }
}

void print_nums(int* nums, int numsSize)
{
    int i;
    for(i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(int argc, const char *argv[])
{
    print_nums(n, 10);
    moveZeroes(n, 10);
    print_nums(n, 10);
    return 0;
}
