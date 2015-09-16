/*
 * =====================================================================================
 *
 *       Filename:  matrix.h
 *
 *    Description:  abstract of matrix functions
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

#ifndef __MATRIX_H__
#define __MATRIX_H__

//#define DIM             5
//#define MAX_DIM         10000
//#define MATRIX_DUMPALL  1
typedef struct matrix_t
{
    /*int n;*/
    /*int rn;*/
    double** a;
} matrix;

extern matrix* new_matrix(double** a);
extern void del_matrix(matrix* a);
#endif

