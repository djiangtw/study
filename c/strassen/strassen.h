/*
 * =====================================================================================
 *
 *       Filename:  strassen.h
 *
 *    Description:  abstract of strassen matrix multiplies.
 *
 *        Version:  1.0
 *        Created:  09/14/2015 02:26:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Danny Jiang (), xinyi904314@yahoo.com.tw
 *   Organization:  Freelancer
 *
 * =====================================================================================
 */
#ifndef __STRASSEN_H
#define __STRASSEN_H

/* brief notation for split arrys */
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

extern int g_break;

extern double*** arr_qsplit(double** a, int n);
extern void arr_qsplit_recall(double*** a);
extern void s_mul(int n, double** a, double** b, double** c, double** d);
extern void s_add(int n, double** a, double** b, double** c);
extern void s_sub(int n, double** a, double** b, double** c);
#endif // __STRASSEN_H
