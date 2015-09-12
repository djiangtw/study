#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "strassen.h"
#include "test_config.h"

void matrix_multiply(matrix* a, matrix* b, matrix* c)
{
    int i, j, k;
    for (i = 0; i < c->n; i++) {
        for (j = 0; j < c->n; j++) {
            c->arr[i][j] = 0;
            for (k = 0; k < c->n; k++) {
                c->arr[i][j] += a->arr[i][k] * b->arr[k][j];
            }
        }
    }
}

void matrix_add(matrix* a, matrix* b, matrix* c)
{
    int i, j;
    for (i = 0; i < c->n; i++) {
        for (j = 0; j < c->n; j++) {
            c->arr[i][j] = a->arr[i][j] + b->arr[i][j];
        }
    }
}

void matrix_dump(matrix* a)
{
    int i, j;
#if MATRIX_DUMPALL
    for (i = 0; i < a->rn; i++) {
        for (j = 0; j < a->rn; j++) {
            printf("%6.2f", a->arr[i][j]);
            /*printf("%d, %d = %6.2f ", i, j, a->arr[i][j]);*/
        }
        printf("\n");
    }
#else
    for (i = 0; i < a->n; i++) {
        for (j = 0; j < a->n; j++) {
            printf("%8.2f ", a->arr[i][j]);
        }
        printf("\n");
    }
#endif
    printf("\n");
}

void array_dump(double** a, int size)
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%8.2f ", a[i][j]);
        }
        printf("\n");
    }

}
void array_copy(double** dest, double* src, int size)
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            dest[i][j] = src[i * 10 + j];
            /*
             *printf("%d, %d = %.1f", i, j, dest[i][j]);
             */
        }
        /*
         *printf(" %.1f %.1f", dest[i][size+1], dest[i][size+2]);
         */
        printf("\n");
    }
}

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

matrix* matrix_init(int n)
{
    int i;
    matrix* ret;
    ret = (matrix*)malloc(sizeof(matrix));
    ret->n = n;
    ret->rn = round_up_power_of_two(ret->n);
    ret->arr = (double**)malloc(sizeof(double*) * ret->rn);
    /*printf("%d, %d\n", ret->n, ret->rn);*/
    for (i = 0; i < ret->rn; i++) {
        ret->arr[i] = (double*)malloc(sizeof(double) * ret->rn);
    }
    /*printf("\n");*/
    return ret;
}

void matrix_delete(matrix* m)
{
    int i;
    for (i = 0; i < m->rn; i++) {
        free(m->arr[i]);
    }
    free(m->arr);
    free(m);
}

matrix_s strassen_matrix_init(matrix* a)
{
    int i, j;
    matrix_s ret;

    ret = (matrix_s)malloc(sizeof(matrix_s));
    ret->d = (double**)malloc(sizeof(double*) * a->rn);
    for (i = 0; i < a->rn; i++) {
        ret->d[i] = (double*)malloc(sizeof(double) * a->rn);
        for (j = 0; j < a->rn; j++) {
            ret->d[i][j] = a->arr[i][j];
        }
    }

    return ret;
}

void strassen_matrix_delete(matrix_s a)
{
    free(a->d);

    free(a);
}

void strassen_matrix_copy(double** a, double** b, int size)
{
    int i;
    a = b;
    for (i = 0; i < size; i++) {
        a[i] = b[i];
    }
}

void strassen_matrix_multiply(matrix* a, matrix* b, matrix* c, matrix* d)
{
    matrix_s sa;
    matrix_s sb;
    matrix_s sc;
    matrix_s sd;

    sa = strassen_matrix_init(a);
    sb = strassen_matrix_init(b);
    sc = strassen_matrix_init(c);
    sd = strassen_matrix_init(d);

    printf("%s\n", "start strassen algorithm");
    sa->d = a->arr;
    sb->d = b->arr;
    sc->d = c->arr;
    sd->d = d->arr;

    /*printf("%d\n", c->rn);*/
    /*multiply(c->rn, sa, sb, sc, sd);*/
    array_dump(sc->d, c->rn);

    strassen_matrix_delete(sa);
    strassen_matrix_delete(sb);
    strassen_matrix_delete(sc);
    strassen_matrix_delete(sd);
}

void testxx(void)
{
    matrix* a;
    matrix* b;
    matrix* c;
    matrix* d;
    matrix* e;
    matrix* f;

    a = matrix_init(DIM);
    b = matrix_init(DIM);
    c = matrix_init(DIM);
    d = matrix_init(DIM);
    e = matrix_init(DIM);
    f = matrix_init(DIM);

    /*matrix_dump(a);*/
    /*matrix_dump(b);*/
    array_dump(a->arr, 8);
    array_copy(a->arr, (double*)cc1, a->n);
    array_copy(b->arr, (double*)cc2, b->n);

    /*matrix_add(a, b, c);*/
    /*matrix_multiply(a, b, d);*/
    strassen_matrix_multiply(a, b, c, e);

    printf("%d\n", a->rn);
    /*matrix_dump(a);*/
    /*matrix_dump(b);*/
    /*
     *matrix_dump(c);
     *matrix_dump(d);
     *matrix_dump(e);
     *matrix_dump(f);
     */

    matrix_delete(a);
    matrix_delete(b);
    matrix_delete(c);
    matrix_delete(d);
    matrix_delete(e);
    matrix_delete(f);
}

void testxx1(void)
{
}

void test(void)
{
    testxx();
    testxx1();
#if 0
    a.n = 3;
    b.n = 3;
    a.arr = (double**)malloc(sizeof(double) * 9);
    b.arr = (double**)malloc(sizeof(double) * 9);
    /*
     *a.arr = (double**)cc1;
     *b.arr = (double**)cc2;
     */
    printf("%s\n", "test");
    printf("%.2f\n", cc1[0][0]);
    printf("%x, %x\n", a.arr, cc1);
    printf("%x\n", &a);
    matrix_dump(&a);
    matrix_dump(&b);
#endif
}
