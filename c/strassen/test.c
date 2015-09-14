/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  implementation of test basis for array multiply comparision.
 *
 *        Version:  1.0
 *        Created:  09/14/2015 11:08:07 AM
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
//#include <float.h>
#include <time.h>
#include "matrix.h"
#include "arr.h"
#include "strassen.h"
#include "test.h"

test_t* new_test(int n)
{
    test_t* r;
    r = (test_t*)malloc(sizeof(test_t));
    r->n = n;
    r->rn = round_up_power_of_two(r->n);
    r->a = new_matrix(new_arr(r->rn, r->rn));
    r->b = new_matrix(new_arr(r->rn, r->rn));
    r->c = new_matrix(new_arr(r->rn, r->rn));
    r->d = new_matrix(new_arr(r->rn, r->rn));
    /*printf("dimension %d, %d\n", r->n, r->rn);*/
    return r;
}

void del_test(test_t* r)
{
    del_arr(r->d->a, r->rn);
    del_arr(r->c->a, r->rn);
    del_arr(r->b->a, r->rn);
    del_arr(r->a->a, r->rn);
    del_matrix(r->d);
    del_matrix(r->c);
    del_matrix(r->b);
    del_matrix(r->a);
    free(r);
}

void dump_result(test_t* t)
{
#if 0
    dump_arr(t->a->a, t->n, t->n);
    dump_arr(t->b->a, t->n, t->n);
    dump_arr(t->c->a, t->n, t->n);
    dump_arr(t->d->a, t->n, t->n);
#endif
}

void init_test_data(test_t* t, int mode)
{
    if(mode == DATA_RANDOM)
    {
        set_ones_arr(t->a->a, t->n, t->n);
        set_ones_arr(t->b->a, t->n, t->n);
    }
    else if(mode == DATA_ONES)
    {
        set_ones_arr(t->a->a, t->n, t->n);
        set_ones_arr(t->b->a, t->n, t->n);
    }
}

int test_strassen_multiply(test_t* t)
{
    double** tmp;
    tmp = new_arr(t->rn, t->rn);
    s_mul(t->rn, t->a->a, t->b->a, tmp, t->d->a);
    s_add(t->rn, t->a->a, tmp, t->c->a);
    del_arr(tmp, t->rn);

    return 0;
}

int test_normal_multiply(test_t* t)
{
    double** tmp;
    tmp = new_arr(t->rn, t->rn);
    arr_mul(t->a->a, t->b->a, tmp, t->n);
    arr_add(t->a->a, tmp, t->d->a, t->n);
    del_arr(tmp, t->rn);

    return 0;
}

int test_check_result(test_t* t)
{
    int i, j;
    double** a;
    a = new_arr(t->n, t->n);
    arr_sub(t->c->a, t->d->a, a, t->n);

    for (i = 0; i < t->n; i++) {
        for (j = 0; j < t->n; j++) {
            if(a[i][j] != 0)
            {
                del_arr(a, t->n);
                return -1;
            }
        }
    }
    del_arr(a, t->n);
    return 0;
}

int test_check_data(test_t* t)
{
    int i, j;
    for (i = 0; i < t->n; i++) {
        for (j = 0; j < t->n; j++) {
            if(t->a->a[i][j] > MAX_DATA_VALUE ||
               t->a->a[i][j] < MIN_DATA_VALUE)
            {
                return -1;
            }
        }
    }
    return 0;
}

int is_power_of_two(unsigned int n)
{
      return ((n != 0) && !(n & (n - 1)));
}

int round_down_power_of_two(int n)
{
    int tmp = 1;
    while(tmp <= n)
    {
        tmp *= 2;
    }
    return tmp / 2;
}

int test_tweak_breaks(int n)
{
    if(n < 2)
    {
        n = 2;
    }
    else if(g_break > MAX_DIM)
    {
        n = round_down_power_of_two(MAX_DIM);
    }
    else
    {
        n = round_down_power_of_two(n);
    }
    return n;
}

double test_case(int n, int ops)
{
    int result;
    clock_t end, start;
    test_t* p;
    /* start of test */
    p = new_test(n);

    /* init test data */
    init_test_data(p, DATA_RANDOM);

    /* operations and tests */

    start = clock();
    switch(ops)
    {
        case OP_STRASSEN_MULTIPLY:
            result = test_strassen_multiply(p);
            break;
        case OP_NORMAL_MULTIPLY:
            result = test_normal_multiply(p);
            break;
        case OP_VERIFY_CORRECTNESS:
            test_strassen_multiply(p);
            test_normal_multiply(p);
            result = test_check_result(p);
            /*
             *printf("%s\n", (test_check_result(p) == 0) ?
             *       "passed": "failed");
             */
            break;
        default:
            printf("%s\n", "invalid ops!");
            break;
    }
    end = clock();

    /* end of test */
    dump_result(p);
    del_test(p);
    printf("%4d, %4d, %4d, %.3f sec, %s\n",
            n,
            ops,
            g_break,
            difftime(end, start) / (double)CLOCKS_PER_SEC,
            (result == 0) ? "passed": "failed");
    return difftime(end, start);
}

void test(int n, int ops)
{
    /*printf("strassen breaks = %d\n", g_break = test_tweak_breaks(g_break));*/
    if(n < 2)
    {
        test_case(2, ops);
    }
    else if( n > MAX_DIM)
    {
        test_case(MAX_DIM, ops);
    }
    else
    {
        test_case(n, ops);
    }
}

