/*
 * =====================================================================================
 *
 *       Filename:  class.h
 *
 *    Description:  class for ooc
 *
 *        Version:  1.0
 *        Created:  2016年01月20日 03時38分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Danny Jiang {xinyi904314@yahoo.com.tw}
 *   Organization:  
 *
 * =====================================================================================
 */

typedef struct Class {
    size_t size;
    void * (* ctor) (void * self, va_list * app);
    void * (* dtor) (void * self);
    void * (* clone) (const void * self, const void * b);
    int (* differ) (const void * self, const void * b);
} Class_t;

typedef struct String {
    const void * class;
    char * text;
} String_t;

typedef struct Set {
    const void * class;
    int * val;
} Set_t;
