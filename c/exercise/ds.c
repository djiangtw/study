/*
 * =====================================================================================
 *
 *       Filename:  ds.c
 *
 *    Description:  data structure implementation.
 *
 *        Version:  1.0
 *        Created:  2016年01月12日 10時37分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

// 太棒了，可以用中文註釋!

#include <stdio.h>
#include <stdlib.h>
#define pass        0
#define fail        -1
#define fail_full   -2
#define fail_empty  -3
#define in_test     1
#define null        0

typedef struct queue_t_
{
    int index_head;
    int index_tail;
    int size;
    int count;
    int* slot;
} queue_t;

typedef queue_t stack_t;

int pushq(queue_t* p, int data)
{

    if(p->count == p->size)
    {
        return fail_full;
    }
    else
    {
        p->count++;
        p->slot[p->index_head] = data;
        p->index_head = (p->index_head + 1) % p->size;
        return pass;
    }
}

int popq(queue_t* p, int* data)
{
    if(p->count == 0)
    {
        return fail_empty;
    }
    else
    {
        p->count--;
        *data = p->slot[p->index_tail];
        p->index_tail = (p->index_tail + 1) % p->size;
        return pass;
    }
}

int pushs()
{
    return pass;
}

int pops()
{
    return pass;
}

int new_queue(queue_t* p, int count)
{
    p->index_head = 0;
    p->index_tail = 0;
    p->size = count;
    p->slot = (int*)malloc(count * sizeof(int));
    return (p->slot == null) ? fail : pass;
}

int del_queue(queue_t* p)
{
    free(p->slot);
    return pass;
}

int print_queue(queue_t* p)
{
    int i;
    printf("(p, q, c) = %d, %d, %d : ", p->index_head, p->index_tail, p->count);
    for (i = 0; i < p->count; i++) {
        printf("%4d ", p->slot[(p->index_tail + i) % p->size]);
    }
    printf("\n");
    return pass;
}

#if in_test
int main(int argc, const char *argv[])
{
    queue_t* a;
    int data;
    int i;

    a = (queue_t*)malloc(sizeof(queue_t));
    new_queue(a, 10);

    print_queue(a);
    pushq(a, 2);
    print_queue(a);
    popq(a, &data);
    print_queue(a);
    pushq(a, 3);
    print_queue(a);
    for(i = 0; i < a->size + 3; i++)
    {
        pushq(a, i);
        print_queue(a);
    }
    for(i = 0; i < a->size + 3; i++)
    {
        popq(a, &data);
        print_queue(a);
        printf("data: %d\n", data);
    }

    del_queue(a);
    free(a);
    return 0;
}
#endif
