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

/**
 * @brief       create a new matrix structure.
 *
 * @param a     the pointer to a matrix with type 'double' elements.
 *
 * @return 
 *
 * @note        the matrix structure can be expanded as necessary.
 */
matrix* new_matrix(double** a)
{
    matrix* r;
    r = (matrix*)malloc(sizeof(matrix));
    r->a = a;
    return r;
}

/**
 * @brief       release the resource of a matrix
 *
 * @param a     the pointer to the matrix.
 */
void del_matrix(matrix* a)
{
    free(a);
}


