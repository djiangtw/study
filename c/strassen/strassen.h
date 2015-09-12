#ifndef __STRASSEN_H
#define __STRASSEN_H
extern void s_mul(int n, double** a, double** b, double** c, double** d);
extern void s_add(int n, double** a, double** b, double** c);
extern void s_sub(int n, double** a, double** b, double** c);
#endif // __STRASSEN_H
