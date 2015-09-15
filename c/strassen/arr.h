/*
 * =====================================================================================
 *
 *       Filename:  arr.h
 *
 *    Description:  abstract of array functions.
 *
 *        Version:  1.0
 *        Created:  09/14/2015 10:12:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Danny Jiang (), xinyi904314@yahoo.com.tw
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __ARR_H__
#define __ARR_H__

extern int round_up_power_of_two(int n);
extern void arr_mul(double** a, double** b, double** c, int n);
extern void arr_add(double** a, double** b, double** c, int n);
extern void arr_sub(double** a, double** b, double** c, int n);
extern double** new_arr(int m, int n);
extern void del_arr(double** r, int m);
extern double** new_arr_p(int m);
extern void del_arr_p(double** r);
extern void dump_arr(double** r, int m, int n);
extern void copy_arr(double** dest, double** src, int m, int n);
extern void rand_arr(double** r, int m, int n);
extern void set_ones_arr(double** r, int m, int n);
extern void set_seqs_arr(double** r, int m, int n);
extern void sub_arr(double** a, double** b, double** c, int m, int n);
extern int comp_arr(double** a, double** b, int m, int n);

#endif
