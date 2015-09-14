/*
 * =====================================================================================
 *
 *       Filename:  matrix.c
 *
 *    Description:  implementation of matrix functions
 *
 *        Version:  1.0
 *        Created:  09/14/2015 10:49:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Danny Jiang (), xinyi904314@yahoo.com.tw
 *   Organization:  Freelancer
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include "matrix.h"

matrix* new_matrix(double** a)
{
    matrix* r;
    r = (matrix*)malloc(sizeof(matrix));
    r->a = a;
    return r;
}

void del_matrix(matrix* a)
{
    free(a);
}


