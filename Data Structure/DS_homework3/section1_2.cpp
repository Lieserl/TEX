Status algo2(Stack S, int e)
{
    Stack T; int d;
    InitStack(T);
    
    while (!StackEmpty(S))
    {
        Pop(S, d);
        if (d != e) Push(T, d);
    }

    while (!StackEmpty(T))
    {
        Pop(T, d);
        Push(S, d);
    }
}