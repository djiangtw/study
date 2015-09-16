/*
 * =====================================================================================
 *
 *       Filename:  arr.c
 *
 *    Description:  implementation of array functions
 *
 *        Version:  1.0
 *        Created:  09/14/2015 09:59:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Danny Jiang (), xinyi904314@yahoo.com.tw
 *   Organization:  Freelancer
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arr.h"

/**
 * @brief       round up a number to power of two. it's used to expand the array
 *              with its dimension to be power-of-two.
 *
 * @param n     the number to be rounded-up
 *
 * @return      the rounded-up number
 */
int round_up_power_of_two(int n)
{
    int ret = 1;
    while(ret < n)
    {
        ret *= 2;
        if(ret > MAX_DIM)
            return -1;
    }
    return ret;
}

/**
 * @brief       perform matrices multiply, C = A mul B.
 *
 * @param a     the input matrix A
 * @param b     the input matrix B
 * @param c     the result of matrices multiply operation.
 * @param n     the dimension of input/output matrices
 */
void arr_mul(double** a, double** b, double** c, int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

/**
 * @brief       perform matrices addition, C = A + B.
 *
 * @param a     the input matrix A
 * @param b     the input matrix B
 * @param c     the result of matrices operation.
 * @param n     the dimension of input/output matrices
 */
void arr_add(double** a, double** b, double** c, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

/**
 * @brief       perform matrices subtraction, C = A + B.
 *
 * @param a     the input matrix A
 * @param b     the input matrix B
 * @param c     the result of matrices operation.
 * @param n     the dimension of input/output matrices
 */
void arr_sub(double** a, double** b, double** c, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

/**
 * @brief       create a new array with dimension m by n.
 *
 * @param m     the row size of an array.
 * @param n     the column size of an array.
 *
 * @return      an array with dimension m by n.
 */
double** new_arr(int m, int n)
{
    int i, j;
    double** r;
    r = (double**)malloc(sizeof(double*) * m);
    for (i = 0; i < m; i++)
    {
        r[i] = (double*)malloc(sizeof(double) * n);
        for (j = 0; j < n; j++)
        {
            r[i][j] = 0;
        }
    }
    return r;
}

/**
 * @brief       release the resource of an array.
 *
 * @param r     the pointer to an array.
 * @param m     the row size of an array.
 */
void del_arr(double** r, int m)
{
    int i;
    for (i = 0; i < m; i++)
    {
        free(r[i]);
    }
    free(r);
}

/**
 * @brief       dump the content of an array
 *
 * @param r     the pointer to the array
 * @param m     the row size of the array
 * @param n     the column size of the array
 */
void dump_arr(double** r, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%6.1f ", r[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief       copy the content of an array to another one.
 *
 * @param dest  the pointer to the destination array.
 * @param src   the pointer to the source array.
 * @param m     the row size of the arrays.
 * @param n     the column size of the arrays.
 */
void copy_arr(double** dest, double** src, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            dest[i][j] = src[i][j];
        }
    }
}

/**
 * @brief       assign random data to an array.
 *
 * @param r     the pointer to an array.
 * @param m     the row size of the array.
 * @param n     the column size of the array.
 */
void rand_arr(double** r, int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            r[i][j] = (double)(rand() % MAX_DATA_VALUE);
        }
    }
}

/**
 * @brief       assign all 1's data to an array.
 *
 * @param r     the pointer to an array.
 * @param m     the row size of the array.
 * @param n     the column size of the array.
 */
void set_ones_arr(double** r, int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
{
            r[i][j] = 1.0;
        }
    }
}

/**
 * @brief       assign sequential data to an array, i.e. all rows contains
 *              data {0, 1, 2, .. , n - 1}.
 *
 * @param r     the pointer to an array.
 * @param m     the row size of the array.
 * @param n     the column size of the array.
 */
void set_seqs_arr(double** r, int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            r[i][j] = (double)(j);
        }
    }
}

/**
 * @brief       compare the content of two arrays.
 *
 * @param a     the pointer to array A.
 * @param b     the pointer to array B.
 * @param m     the row size of the arrays.
 * @param n     the column size of the arrays.
 *
 * @return      0 indicates A and B are the same.
 *              1 inticates A and B are different.
 */
int comp_arr(double** a, double** b, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if((a[i][j] - b[i][j]) != 0)
                return (-1);
        }
    }
    return 0;
}

