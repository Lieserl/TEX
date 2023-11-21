Status a1go1(Stack S)
{
    int i, n, A[255];
    n = 0;
    while (!StackEmpty(S)) {n++; Pop(S, A[n]);};
    for (i = 1; i <= n; i ++ ) Push(S, A[i]);
}