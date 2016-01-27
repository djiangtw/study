/*
 * =====================================================================================
 *
 *       Filename:  class.c
 *
 *    Description:  class implementation for ooc
 *
 *        Version:  1.0
 *        Created:  2016年01月20日 03時42分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Danny Jiang {xinyi904314@yahoo.com.tw}
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdarg.h>
#include "class.h"

void * new (const void * _class, ...)
{
    const Class_t * class = _class;
    void * p = calloc(1, class -> size);
}
