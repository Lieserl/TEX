void reverse(SqList &L int start, int end)
{
    while (start < end)
    {
        // swap(L.elem[start], L.elem[end])
        ElemType temp = L.elem[start];
        L.elem[start] = L.elem[end];
        L.elem[end] = temp;
        start ++ ; end -- ;
    }

    return;
}

void shift(SqList &L, int k)
{
    reverse(L, 0, k - 1);
    reverse(L, k, L.length - 1);
    reverse(L, 0, L.length - 1);
}