#include <stdio.h>
#include <stdlib.h>
#include "strassen.h"

int g_break = 16;
//extern void add(int n, matrix_s a, matrix_s b, matrix_s c);
#define a11 p[0]
#define a12 p[1]
#define a21 p[2]
#define a22 p[3]
#define b11 q[0]
#define b12 q[1]
#define b21 q[2]
#define b22 q[3]
#define c11 r[0]
#define c12 r[1]
#define c21 r[2]
#define c22 r[3]
#define d11 s[0]
#define d12 s[1]
#define d21 s[2]
#define d22 s[3]

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

void arr_qsplit_recall(double*** a)
{
    int i;
    for(i = 0; i < 4; i++)
    {
        free(a[i]);
    }
    free(a);
}

void s_mul(int n, double** a, double** b, double** c, double** d)
{
    if (n <= g_break) {
        double sum, **p = a, **q = b, **r = c;
        int i, j, k;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (sum = 0., k = 0; k < n; k++)
                    sum += p[i][k] * q[k][j];
                r[i][j] = sum;
            }
        }
    } else {
        double ***p, ***q, ***r, ***s;
        n /= 2;
        p = arr_qsplit(a, n);
        q = arr_qsplit(b, n);
        r = arr_qsplit(c, n);
        s = arr_qsplit(d, n);

        s_sub(n, a12, a22, d11);
        s_add(n, b21, b22, d12);
        s_mul(n, d11, d12, c11, d21);
        s_sub(n, a21, a11, d11);
        s_add(n, b11, b12, d12);
        s_mul(n, d11, d12, c22, d21);
        s_add(n, a11, a12, d11);
        s_mul(n, d11, b22, c12, d12);
        s_sub(n, c11, c12, c11);
        s_sub(n, b21, b11, d11);
        s_mul(n, a22, d11, c21, d12);
        s_add(n, c21, c11, c11);
        s_sub(n, b12, b22, d11);
        s_mul(n, a11, d11, d12, d21);
        s_add(n, d12, c12, c12);
        s_add(n, d12, c22, c22);
        s_add(n, a21, a22, d11);
        s_mul(n, d11, b11, d12, d21);
        s_add(n, d12, c21, c21);
        s_sub(n, c22, d12, c22);
        s_add(n, a11, a22, d11);
        s_add(n, b11, b22, d12);
        s_mul(n, d11, d12, d21, d22);
        s_add(n, d21, c11, c11);
        s_add(n, d21, c22, c22);

        arr_qsplit_recall(p);
        arr_qsplit_recall(q);
        arr_qsplit_recall(r);
        arr_qsplit_recall(s);
    }
}

void s_add(int n, double** a, double** b, double** c)
{
    if (n <= g_break) {
        double **p = a, **q = b, **r = c;
        int i, j;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                r[i][j] = p[i][j] + q[i][j];
            }
        }
    } else {
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

void s_sub(int n, double** a, double** b, double** c)
{
    if (n <= g_break) {
        double **p = a, **q = b, **r = c;
        int i, j;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                r[i][j] = p[i][j] - q[i][j];
            }
        }
    } else {
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
