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

#define MAX_DIM 10000

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

void arr_mul(double** a, double** b, double** c, int n)
{
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void arr_add(double** a, double** b, double** c, int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void arr_sub(double** a, double** b, double** c, int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

double** new_arr(int m, int n)
{
    int i, j;
    double** r;
    r = (double**)malloc(sizeof(double*) * m);
    for (i = 0; i < m; i++) {
        r[i] = (double*)malloc(sizeof(double) * n);
        for (j = 0; j < n; j++)
        {
            r[i][j] = 0;
        }
    }
    return r;
}

void del_arr(double** r, int m)
{
    int i;
    for (i = 0; i < m; i++) {
        free(r[i]);
    }
    free(r);
}

double** new_arr_p(int m)
{
    double** r;
    r = (double**)malloc(sizeof(double*) * m);
    return r;
}

void del_arr_p(double** r)
{
    free(r);
}

void dump_arr(double** r, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%6.1f ", r[i][j]);
        }
        printf("\n");
    }
}

void copy_arr(double** dest, double** src, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

void rand_arr(double** r, int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            r[i][j] = (double)(rand() % 100);
        }
    }
}

void set_ones_arr(double** r, int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            r[i][j] = (double)(j);
        }
    }
}

void sub_arr(double** a, double** b, double** c, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

int comp_arr(double** a, double** b, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if((a[i][j] - b[i][j]) != 0)
                return (-1);
        }
    }
    return 0;
}

#if 0
void init_two_arrays(void)
{
    int i, j;
    int m = 10;
    int n = 10;
    cc1p = new_arr(m, n);
    cc2p = new_arr(m, n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cc1p[i][j] = cc1[i][j];
            cc2p[i][j] = cc2[i][j];
        }
    }
}

void del_two_arrays(void)
{
    del_arr(cc1p, 10);
    del_arr(cc2p, 10);
}

void arr_test1(void)
{
    int m = 5;
    int n = 5;
    int i;
    double** a[5];

    for (i = 0; i < 5; i++) {
        a[i] = new_arr(m, n);
    }

    copy_arr(a[0], cc1p, m, n);
    copy_arr(a[1], cc2p, m, n);

    for (i = 0; i < 5; i++) {
        dump_arr(a[i], m, n);
        printf("\n");
    }

    for (i = 0; i < 5; i++) {
        del_arr(a[i], m);
    }
}

matrix_s new_matrix_s(double** a)
{
    matrix_s s;
    s = (matrix_s)malloc(sizeof(double**));
    s->d = a;
    /*printf("%x\n", (unsigned int)s->p[0]);*/
    /*printf("%x\n", (unsigned int)s->p[1]);*/
    /*printf("%x\n", (unsigned int)s->p[2]);*/
    return s;
}

matrix_s new_matrix_s_1(double** a)
{
    matrix_s s;
    s = (matrix_s)malloc(sizeof(double**)*4);
    s->d = a;
    s->p[0] = s;
    s->p[1] = s;
    s->p[2] = s;
    s->p[3] = s;
    /*
     *s->p = &s;
     */
    return s;
}

void del_matrix_s(matrix_s a)
{
    free(a);
}

void testxx2_finish(void)
{
    del_arr(a, dim_r);
    del_arr(b, dim_r);
    del_arr(c, dim_r);
    del_arr(d, dim_r);
    del_two_arrays();
    del_matrix_s(aa);
    del_matrix_s(bb);
    del_matrix_s(cc);
    del_matrix_s(dd);
}

void testxx2_init(void)
{
    a = new_arr(dim_r, dim_r);
    b = new_arr(dim_r, dim_r);
    c = new_arr(dim_r, dim_r);
    d = new_arr(dim_r, dim_r);
    init_two_arrays();
    aa = new_matrix_s(a);
    bb = new_matrix_s(b);
    cc = new_matrix_s(c);
    dd = new_matrix_s(d);
    /*
     *aa->d = a;
     *bb->d = b;
     *cc->d = c;
     *dd->d = d;
     */
}

/*****************************************************************
* Function: testxx2
*
* Abstract: first good trial of strassen algorithm.
*
* Input/Output:
*
* Return:
*
* Notices:
****************************************************************/
void testxx2(void)
{
    dim_r = round_up_power_of_two(dim);
    testxx2_init();
    printf("%s\n", __func__);
    copy_arr(a, cc1p, dim, dim);
    copy_arr(b, cc1p, dim, dim);
    dump_arr(cc1p, 10, 10);
    dump_arr(a, dim_r, dim_r);
    dump_arr(b, dim_r, dim_r);

    multiply(dim_r, aa, bb, cc, dd);

    dump_arr(c, dim_r, dim_r);
    testxx2_finish();
}

void testxx3(void)
{
    double** a;
    double** b;
    double** c;
    srand(time(NULL));
    a = new_arr(dim, dim);
    b = new_arr(dim, dim);
    c = new_arr(dim, dim);
    rand_arr(a, dim, dim);
    /*copy_arr(b, a, dim, dim);*/
    rand_arr(b, dim, dim);
    sub_arr(a, b, c, dim, dim);
    printf("comp a, b, = %d\n", comp_arr(a, b, dim, dim));

    dump_arr(a, dim, dim);
    dump_arr(b, dim, dim);
    dump_arr(c, dim, dim);

    del_arr(a, dim);
    del_arr(b, dim);
    del_arr(c, dim);
    /*
     *printf("%f\n", sqrt(DBL_MAX));
     *printf("%f\n", (DBL_MAX));
     */
}

#endif
