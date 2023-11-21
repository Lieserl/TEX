#pragma once
#ifndef OPRTSTACK_H
#define OPRTSTACK_H

#include <stdbool.h>
#ifndef STACK_INIT_SIZE
#define STACK_INIT_SIZE 50

#ifndef STACK_EXTEND_SIZE
#define STACK_EXTEND_SIZE 20
typedef struct
{
    char* base;
    int top;
    int stack_size;
} OpStack;

OpStack* init_stack(void);

void destory_stack(OpStack* s);

bool extend_stack(OpStack* s);

bool push(OpStack* s, char ch);

bool pop(OpStack* s);

char top(OpStack* s);

bool empty(OpStack* s);

#endif // !STACK_EXTEND_SIZE
#endif // !STACK_INIT_SIZE
#endif // !OPRTSTACK_H
