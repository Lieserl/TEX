void algo3(Queue &Q)
{
    Stack S; int d;
    InitStack(S);

    while (!QeueuEmpty(Q))
    {
        DeQueue(Q, d);
        Push(S, d);
    }
    
    while (!StackEmpty(S))
    {
        Pop(S, d);
        EnQueue(Q, d);
    }
}