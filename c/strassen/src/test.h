/*
 * =====================================================================================
 *
 *       Filename:  test.h
 *
 *    Description:  abstract of test
 *
 *        Version:  1.0
 *        Created:  09/14/2015 12:53:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Danny Jiang (), xinyi904314@yahoo.com.tw
 *   Organization:  Freelancer
 *
 * =====================================================================================
 */

#ifndef __TEST_H__
#define __TEST_H__

#include "matrix.h"

typedef struct _test_t
{
    int n;
    int rn;
    matrix* a; /* input matrix A */
    matrix* b; /* input matrix B */
    matrix* c; /* result of test */
    matrix* d; /* scratchpad for strassen multiply or normal multiply operation */
} test_t;

typedef enum _PATTERN_MODE
{
    PATTERN_RANDOM = 0,
    PATTERN_ONES,
    PATTERN_SEQS,
    NUMBER_OF_PATTERNS,
} PATTERN_MODE;

typedef enum _OPS
{
    OP_STRASSEN_MULTIPLY = 0,
    OP_NORMAL_MULTIPLY,
    OP_VERIFY_CORRECTNESS,
    OP_DUMP_RESULT,
    NUMBER_OF_OPS
} OPS;

extern int g_pattern;

extern test_t* new_test(int n);
extern void del_test(test_t* r);
extern void dump_result(test_t* t);
extern void init_test_data(test_t* t, int pattern);
extern int test_strassen_multiply(test_t* t);
extern int test_normal_multiply(test_t* t);
extern int test_check_result(test_t* t);
extern int test_valid_data(test_t* t);
extern int round_down_power_of_two(int n);
extern int test_tweak_breaks(int n);
extern double test_case(int n, int ops);
extern void test(int n, int ops);
#endif
