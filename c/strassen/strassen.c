/*
 * =====================================================================================
 *
 *       Filename:  strassen.c
 *
 *    Description:  implementation of strassen matrix multiplies.
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
#include <stdlib.h>
#include "strassen.h"

int g_break = 16;

/**
 * @brief       split a given array into 4 equal sub-arrays.
 *
 * @param a     an input {2n x 2n} array
 * @param n     the dimension of new arrays, i.e. {n x n}.
 *
 * @return      a pointer to 4 arrays.
 *
 * | AAAABBBB |
 * | AAAABBBB |
 * | AAAABBBB |     | AAAA |   | BBBB |   | CCCC |   | DDDD |
 * | AAAABBBB | ->  | AAAA | , | BBBB | , | CCCC | , | DDDD |
 * | CCCCDDDD |     | AAAA |   | BBBB |   | CCCC |   | DDDD |
 * | CCCCDDDD |     | AAAA |   | BBBB |   | CCCC |   | DDDD |
 * | CCCCDDDD |
 * | CCCCDDDD |
 */
double*** arr_qsplit(double** a, int n)
{
    int i;
    double*** r;

    r = (double***)malloc(sizeof(double**) * 4);
    for(i = 0; i < 4; i++)
    {
        r[i] = (double**)malloc(sizeof(double*) * n);
    }
    for(i = 0; i < n; i++)
    {
        r[0][i] = a[i];
        r[1][i] = a[i] + n;
        r[2][i] = a[i + n];
        r[3][i] = a[i + n] + n;
    }
    return r;
}

/**
 * @brief       release the resources allocated for array split.
 *
 * @param a     a pointer to 4 arrays.
 */
void arr_qsplit_recall(double*** a)
{
    int i;
    for(i = 0; i < 4; i++)
    {
        free(a[i]);
    }
    free(a);
}

/**
 * @brief       perform the strassen multiply for matrices.
 *
 * @param n     the dimension of the input and output matrices.
 * @param a     the first input matrix
 * @param b     the second input matrix
 * @param c     the result of matrix a multiplies matrix b.
 * @param d     the scratchpad for calculation.
 *
 * @note        the algorithm is refer to wiki,
 *              https://en.wikipedia.org/wiki/Strassen_algorithm
 *
 *              if the dimension of input matrices are less than g_break,
 *              perform a normal O(N^3) matrix multiply operation.
 *              else, divide the matrices and perform strassen algorithm.
 */
void s_mul(int n, double** a, double** b, double** c, double** d)
{
    if (n <= g_break)
    {
        double sum, **p = a, **q = b, **r = c;
        int i, j, k;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                for (sum = 0., k = 0; k < n; k++)
                    sum += p[i][k] * q[k][j];
                r[i][j] = sum;
            }
        }
    }
    else
    {
        double ***p, ***q, ***r, ***s;
        n /= 2;
        p = arr_qsplit(a, n);
        q = arr_qsplit(b, n);
        r = arr_qsplit(c, n);
        s = arr_qsplit(d, n);

        s_sub(n, a12, a22, d11);       /* D11 = A12 - A22 */
        s_add(n, b21, b22, d12);       /* D12 = B21 + B22 */
        s_mul(n, d11, d12, c11, d21);  /* C11 = (A12 - A22)(B21 + B22), M7 */
        s_sub(n, a21, a11, d11);       /* D11 = A21 - A11 */
        s_add(n, b11, b12, d12);       /* D12 = B11 + B12 */
        s_mul(n, d11, d12, c22, d21);  /* C22 = (A21 - A11)(B11 + B12), M6 */
        s_add(n, a11, a12, d11);       /* D11 = A11 + A12 */
        s_mul(n, d11, b22, c12, d12);  /* C12 = (A11 + A12)B22, M5 */
        s_sub(n, c11, c12, c11);       /* C11 = M7 - M5 */
        s_sub(n, b21, b11, d11);       /* D11 = B21 - B11 */
        s_mul(n, a22, d11, c21, d12);  /* C21 = A22(B21 - B11), M4 */
        s_add(n, c21, c11, c11);       /* C11 = M4 + M7 - M5 */
        s_sub(n, b12, b22, d11);       /* D11 = B12 - B22 */
        s_mul(n, a11, d11, d12, d21);  /* D12 = A11(B12 - B22), M3 */
        s_add(n, d12, c12, c12);       /* C12 = M3 + M5 */
        s_add(n, d12, c22, c22);       /* C22 = M3 + M6 */
        s_add(n, a21, a22, d11);       /* D11 = A21 + A22 */
        s_mul(n, d11, b11, d12, d21);  /* D12 = (A21 + A22)B11, M2 */
        s_add(n, d12, c21, c21);       /* C21 = M2 + M4 */
        s_sub(n, c22, d12, c22);       /* C22 = M3 + M6 - M2 */
        s_add(n, a11, a22, d11);       /* D11 = A11 + A22 */
        s_add(n, b11, b22, d12);       /* D12 = B11 + B22 */
        s_mul(n, d11, d12, d21, d22);  /* D21 = (A11 + A22)(B11 + B22), M1 */
        s_add(n, d21, c11, c11);       /* C11 = M1 + M4 - M5 + M7 */
        s_add(n, d21, c22, c22);       /* C22 = M1 - M2 + M3 + M6 */

        arr_qsplit_recall(p);
        arr_qsplit_recall(q);
        arr_qsplit_recall(r);
        arr_qsplit_recall(s);
    }
}

/**
 * @brief       perform the addition operation of matrices with
 *              matrices dividing.
 *
 * @param n     the dimension of the input and output matrices.
 * @param a     the first input matrix
 * @param b     the second input matrix
 * @param c     the result of matrix a adds matrix b.
 *
 *              if the dimension of input matrices are less than g_break,
 *              perform a normal matrix substraction operation.
 *              else, divide the matrices and calculate the result of each sub matrices.
 */
void s_add(int n, double** a, double** b, double** c)
{
    if (n <= g_break)
    {
        double **p = a, **q = b, **r = c;
        int i, j;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                r[i][j] = p[i][j] + q[i][j];
            }
        }
    }
    else
    {
        double ***p, ***q, ***r;
        n /= 2;
        p = arr_qsplit(a, n);
        q = arr_qsplit(b, n);
        r = arr_qsplit(c, n);

        s_add(n, a11, b11, c11);
        s_add(n, a12, b12, c12);
        s_add(n, a21, b21, c21);
        s_add(n, a22, b22, c22);

        arr_qsplit_recall(p);
        arr_qsplit_recall(q);
        arr_qsplit_recall(r);
    }
}

/**
 * @brief       perform the substraction operation of matrices with 
 *              matrices dividing.
 *
 * @param n     the dimension of the input and output matrices.
 * @param a     the first input matrix
 * @param b     the second input matrix
 * @param c     the result of matrix a substracts matrix b.
 *
 *              if the dimension of input matrices are less than g_break,
 *              perform a normal matrix addition operation.
 *              else, divide the matrices and calculate the result of each sub matrices.
 */
void s_sub(int n, double** a, double** b, double** c)
{
    if (n <= g_break)
    {
        double **p = a, **q = b, **r = c;
        int i, j;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                r[i][j] = p[i][j] - q[i][j];
            }
        }
    }
    else
    {
        double ***p, ***q, ***r;
        n /= 2;
        p = arr_qsplit(a, n);
        q = arr_qsplit(b, n);
        r = arr_qsplit(c, n);

        s_sub(n, a11, b11, c11);
        s_sub(n, a12, b12, c12);
        s_sub(n, a21, b21, c21);
        s_sub(n, a22, b22, c22);

        arr_qsplit_recall(p);
        arr_qsplit_recall(q);
        arr_qsplit_recall(r);
    }
}
