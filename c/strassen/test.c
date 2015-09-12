#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "strassen.h"
#include "s.h"
#include "test_config.h"
#include <float.h>
#include <math.h>

/*double max_arr_value = floor(sqrt(DBL_MAX));*/
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

void arr_multiply(double** a, double** b, double** c, int n)
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
#if 0
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
#endif
/*****************************************************************
* Function:
*
* Abstract:
*
* Input/Output:
*
* Return:
*
* Notices:
*   new implementation from new to
****************************************************************/
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

void testxx1(void)
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

typedef struct strassen_test_object_t
{
    int dim;
    int dim_r;
    double t[4];
    /*
     *double** a;
     *double** b;
     *double** c; [> strassen multuply result <]
     *double** d; [> strassen scratch; normal multiply result <]
     */
    matrix_s a;
    matrix_s b;
    matrix_s c; /* strassen multuply result */
    matrix_s d; /* strassen scratch; normal multiply result */
} strassen_test_object;

strassen_test_object* new_strassen_test_object(int n)
{
    strassen_test_object* r;
    r = (strassen_test_object*)malloc(sizeof(strassen_test_object));
    r->dim = n;
    r->dim_r = round_up_power_of_two(r->dim);
    r->a = new_matrix_s(new_arr(r->dim_r, r->dim_r));
    r->b = new_matrix_s(new_arr(r->dim_r, r->dim_r));
    r->c = new_matrix_s(new_arr(r->dim_r, r->dim_r));
    r->d = new_matrix_s(new_arr(r->dim_r, r->dim_r));
    printf("dimension %d, %d\n", r->dim, r->dim_r);
    return r;
}

void del_strassen_test_object(strassen_test_object* r)
{
    del_arr(r->d->d, r->dim_r);
    del_arr(r->c->d, r->dim_r);
    del_arr(r->b->d, r->dim_r);
    del_arr(r->a->d, r->dim_r);
    del_matrix_s(r->d);
    del_matrix_s(r->c);
    del_matrix_s(r->b);
    del_matrix_s(r->a);
    free(r);
}

void dump_result(strassen_test_object* r)
{
    /*dump_arr(t->a->d, t->dim_r, t->dim_r);*/
    /*dump_arr(t->b->d, t->dim_r, t->dim_r);*/
    /*dump_arr(t->c->d, t->dim_r, t->dim_r);*/
    /*dump_arr(t->d->d, t->dim_r, t->dim_r);*/
#if 0
    dump_arr(r->a->d, r->dim_r, r->dim_r);
    dump_arr(r->c->d, r->dim_r, r->dim_r);
    dump_arr(r->d->d, r->dim_r, r->dim_r);
#endif
    /*
     *printf("time strassen = %f\n", r->t[1] - r->t[0]);
     *printf("time normal   = %f\n", r->t[3] - r->t[2]);
     *printf("%f\n", clock() * 1000000);
     */
}

void test_update_s(matrix_s a, int n)
{
    update_matrix_s(a, n);
    dump_arr(a->d, n, n);
    dump_arr(a->p[0]->d, n, n);
}

void test_main(int n)
{
    strassen_test_object* t;

    t = new_strassen_test_object(n);
    /* set test pattern */
//    rand_arr(t->a->d, t->dim, t->dim);
//    rand_arr(t->b->d, t->dim, t->dim);
    set_ones_arr(t->a->d, t->dim, t->dim);
    set_ones_arr(t->b->d, t->dim, t->dim);

    /*test_update_s(t->a, t->dim_r);*/
    /* perform strassen algorithm */
    /*t->t[0] = clock();*/
    /* multiply(t->dim_r, t->a, t->b, t->c, t->d); */
    s_mul(t->dim_r, t->a->d, t->b->d, t->c->d, t->d->d);
//    s_sub(t->dim_r, t->a->d, t->b->d, t->c->d);
    /*t->t[1] = clock();*/

    /* perform normal */
    /*t->t[2] = clock();*/
    arr_multiply(t->a->d, t->b->d, t->d->d, t->dim);
//    arr_sub(t->a->d, t->b->d, t->d->d, t->dim);
    /*t->t[3] = clock();*/
    arr_sub(t->c->d, t->d->d, t->b->d, t->dim);

    dump_result(t);
    printf("comp c, d = %d\n", comp_arr(t->c->d, t->d->d, t->dim, t->dim));
    del_strassen_test_object(t);
}

void test(int n)
{
    /*testxx();*/
    /*testxx1();*/
    /*testxx2();*/
    /*testxx3();*/
    if(n < 2)
    {
        test_main(2);
    }
    else
    {
        test_main(n);
    }
}
