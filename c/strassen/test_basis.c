/*
 * =====================================================================================
 *
 *       Filename:  test_basis.c
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
#include <float.h>
#include "matrix.h"
#include "arr.h"

typedef struct _test_t
{
    int n;
    int rn;
    matrix* a;
    matrix* b;
    matrix* c;
    matrix* d;
} test_t;

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
    printf("dimension %d, %d\n", r->n, r->rn);
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

void dump_result(test_t* r)
{
#if 0
    dump_arr(r->a->a, r->n, r->n);
    dump_arr(r->b->a, r->n, r->n);
    dump_arr(r->c->a, r->n, r->n);
#endif
    /*
     *printf("time strassen = %f\n", r->t[1] - r->t[0]);
     *printf("time normal   = %f\n", r->t[3] - r->t[2]);
     *printf("%f\n", clock() * 1000000);
     */
}

void test_main(int n)
{
    test_t* p;
    /* start of test */
    p = new_test(n);
    printf("test arr = %d\n", n);

    set_ones_arr(p->a->a, p->n, p->n);
    set_ones_arr(p->b->a, p->n, p->n);

    arr_mul(p->a->a, p->b->a, p->c->a, p->rn);

    /* end of test */
    dump_result(p);
    del_test(p);
}

void test(int n)
{
    if(n < 2)
    {
        test_main(2);
    }
    else
    {
        test_main(n);
    }
}


