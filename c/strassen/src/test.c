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
#include <time.h>
#include "arr.h"
#include "strassen.h"
#include "test.h"

/**
 * @brief       create a new test object.
 *
 * @param n     the dimension of a matrix.
 *
 * @return a    pointer to new test object.
 */
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
    return r;
}

/**
 * @brief       delete a test object and release its resources.
 *
 * @param r     a test object.
 */
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

/**
 * @brief       dump test result
 *
 * @param t     a test object
 */
void dump_result(test_t* t)
{
#if TEST_DUMP_RESULT
    dump_arr(t->a->a, t->n, t->n);
    dump_arr(t->b->a, t->n, t->n);
    dump_arr(t->c->a, t->n, t->n);
    dump_arr(t->d->a, t->n, t->n);
#endif
}

/**
 * @brief               set up data data for input marices.
 *
 * @param t             a test object.
 * @param pattern       the pattern of given data.
 *
 *  PATTERN_RANDOM      apply random data to the test object input.
 *  PATTERN_ONES        apply all 1's to the test object input.
 *  PATTERN_SEQS        apply sequential data, {0, 1, 2, .., n-1} for
 *                      each row, to the object input.
 */
void init_test_data(test_t* t, int pattern)
{
    if(pattern == PATTERN_RANDOM)
    {
        set_ones_arr(t->a->a, t->n, t->n);
        set_ones_arr(t->b->a, t->n, t->n);
    }
    else if(pattern == PATTERN_ONES)
    {
        set_ones_arr(t->a->a, t->n, t->n);
        set_ones_arr(t->b->a, t->n, t->n);
    }
    else if(pattern == PATTERN_SEQS)
    {
        set_seqs_arr(t->a->a, t->n, t->n);
        set_seqs_arr(t->b->a, t->n, t->n);
    }
}

/**
 * @brief       perform C = A + S(A, B), while strassen algorithm
 *              is applied in S().
 *
 * @param t     a test object.
 *
 * @return      0 as passed.
 */
int test_strassen_multiply(test_t* t)
{
    double** tmp;
    tmp = new_arr(t->rn, t->rn);
    s_mul(t->rn, t->a->a, t->b->a, tmp, t->d->a);
    s_add(t->rn, t->a->a, tmp, t->c->a);
    del_arr(tmp, t->rn);

    return 0;
}

/**
 * @brief       perform C = A + M(A, B), while a normal matrix multiply
 *              function is applied in M().
 *
 * @param t     a test object.
 *
 * @return      0 as passed.
 */
int test_normal_multiply(test_t* t)
{
    double** tmp;
    tmp = new_arr(t->rn, t->rn);
    arr_mul(t->a->a, t->b->a, tmp, t->n);
    arr_add(t->a->a, tmp, t->d->a, t->n);
    del_arr(tmp, t->rn);

    return 0;
}

/**
 * @brief       check if the result of matrix c and d in test object are equal.
 *
 * @param t     the test object.
 *
 * @return      0 as equal;, and -1 as inequal.
 */
int test_check_result(test_t* t)
{
    int i, j;
    double** a;
    a = new_arr(t->n, t->n);
    arr_sub(t->c->a, t->d->a, a, t->n);

    for (i = 0; i < t->n; i++)
    {
        for (j = 0; j < t->n; j++)
        {
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

/**
 * @brief       validate each element test object input matrix is valid.
 *
 * @param t     the test object
 *
 * @return      0 as all data are valid.
 *              -1 as input matrix a is invalid.
 *              -2 as input matrix b is invalid.
 */
int test_valid_data(test_t* t)
{
    int i, j;
    for (i = 0; i < t->n; i++)
    {
        for (j = 0; j < t->n; j++)
        {
            if(t->a->a[i][j] > MAX_DATA_VALUE ||
                    t->a->a[i][j] < MIN_DATA_VALUE)
            {
                return -1;
            }
            if(t->b->a[i][j] > MAX_DATA_VALUE ||
                    t->b->a[i][j] < MIN_DATA_VALUE)
            {
                return -2;
            }
        }
    }
    return 0;
}

/**
 * @brief       round down a number to be power-of-two one.
 *
 * @param n     the number to be rounded-down
 *
 * @return      the rounded-down number
 */
int round_down_power_of_two(int n)
{
    int tmp = 1;
    while(tmp <= n)
    {
        tmp *= 2;
    }
    return tmp / 2;
}

/**
 * @brief       validate the value of g_break and tweak it.
 *
 * @param n     the number to be validated and tweaked.
 *
 * @return      the number has been tweaked.
 *
 * @note        MAX_DIM is a predefined number for max dimension of the matrices.
 */
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

/**
 * @brief       a test case for this matrix operation test.
 *
 * @param n     the dimension of input metrices.
 * @param ops   the operations for this test.
 *
 * @return      the elapsed time in mini-second.
 *
 * @note        the users can modify the time elapse functions in their
 *              specific platform to calculate the performance of the
 *              matrix operation test.
 */
double test_case(int n, int ops)
{
    int result;
    clock_t end, start;
    test_t* p;
    /* start of test */
    p = new_test(n);

    /* init test data */
    init_test_data(p, PATTERN_RANDOM);

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
    return (difftime(end, start) / (double)CLOCKS_PER_SEC);
}

/**
 * @brief       entry of test.
 *
 * @param n     the dimension of input matrices.
 * @param ops   the operation code of test
 *
 * OP_STRASSEN_MULTIPLY     perform C = A + S(A, B), where {A, B, C} are mapped to
 *                          {a, b, c} in test object.
 * OP_NORMAL_MULTIPLY       perform D = A + M(A, B), where {A, B, D} are mapped to
 *                          {a, b, d} in test object.
 * OP_VERIFY_CORRECTNESS    per form C = A + S(A, B) and D = A + M(A, B), where
 *                          {A, B, C, D} are mapped to {a, b, c, d} in test object.
 *                          And then, compare the matrix C and D to see if the results
 *                          are the same.
 */
void test(int n, int ops)
{
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

