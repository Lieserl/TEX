#include "queue.hpp"
#include <stdlib.h>

Priority_Queue* initQueue(int capacity)
{
    Priority_Queue* temp = (Priority_Queue*)malloc(sizeof(Priority_Queue));
    
    if (temp == NULL) return NULL;
    
    temp->base     = (QNode*)malloc((capacity + 1) * sizeof(QNode));
    temp->size     = 0;
    temp->capacity = capacity + 1;
    
    return temp;
}

void destroyQueue(Priority_Queue* q)
{
    if (q == NULL) return;
    
    if (q->base) free(q->base);
    free(q);
}

void heapSwap(Priority_Queue* q, int a, int b)
{
    QNode temp = q->base[a];
    q->base[a] = q->base[b];
    q->base[b] = temp;
}

void adjustDown(Priority_Queue* q, int u)
{
    int temp = u, lc = u << 1, rc = lc | 1;
    if (lc <= q->size && q->base[lc].weight < q->base[temp].weight) temp = lc;
    if (rc <= q->size && q->base[rc].weight < q->base[temp].weight) temp = rc;
    if (u != temp)
    {
        heapSwap(q, u, temp);
        adjustDown(q, temp);
    }
}

void adjustUp(Priority_Queue* q, int u)
{
    while (u >> 1 && q->base[u].weight < q->base[u >> 1].weight)
    {
        heapSwap(q, u, u >> 1);
        u >>= 1;
    }
}

void enQueue(Priority_Queue* q, int idx, int weight)
{
    if (q == NULL || idx <= 0 || weight < 0) return;
    
    q->base[ ++ q->size] = {idx, weight};
    adjustUp(q, q->size);
}

int deQueue(Priority_Queue* q)
{
    if (q == NULL) return -1;
    
    int idx = q->base[1].index;
    heapSwap(q, 1, q->size);
    q->size -- ;
    adjustDown(q, 1);
    
    return idx;
}

