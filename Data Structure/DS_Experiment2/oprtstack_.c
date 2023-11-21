#include "oprtstack.h"
#include <string.h>
#include <stdlib.h>

OpStack* init_stack(void)
{
    OpStack* s = (OpStack*)malloc(sizeof(OpStack));
    s->base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
    s->top = -1;
    s->stack_size = STACK_INIT_SIZE;

    return s;
}

bool extend_stack(OpStack* s)
{
    char* newBase = NULL;
    int newSize = s->stack_size + STACK_EXTEND_SIZE;
    newBase = (char*)realloc(s->base, newSize * sizeof(char));
    if (!newBase) return false;

    s->base = newBase;
    s->stack_size = newSize;

    return true;
}

void destory_stack(OpStack* s)
{
    if (s->base) free(s->base);
    free(s);

    return;
}

bool push(OpStack* s, char ch)
{
    if (s->top >= s->stack_size)
        if (!extend_stack(s)) return false;

    s->base[ ++ s->top] = ch;

    return true;
}

bool pop(OpStack* s)
{
    if (s->top < 0) return false;

    s->top -- ;

    return true;
}

char top(OpStack* s)
{
    if (s->top >= 0) return s->base[s->top];
    return '\0';
}

bool empty(OpStack* s)
{
    return s->top < 0;
}

