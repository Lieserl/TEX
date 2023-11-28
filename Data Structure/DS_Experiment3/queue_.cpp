#ifndef queue_hpp
#define queue_hpp

typedef struct
{
    int index;
    int weight;
} QNode;

typedef struct
{
    QNode* base;
    int size;
    int capacity;
} Priority_Queue;

Priority_Queue* initQueue(int capacity);

void destroyQueue(Priority_Queue* q);

void heapSwap(Priority_Queue* q, int a, int b);

void adjustDown(int u);

void adjustUp(int u);

void enQueue(Priority_Queue* q, int index, int weight);

int deQueue(Priority_Queue* q);

#endif /* queue_hpp */
