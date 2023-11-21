void DeleteRange(SqList &L, ElemType x, ElemType y)
{
    if (y < x) return;

    int q = 0;
    for (int p = 0; p < L.length; p ++ )
        if (L.elem[p] < x || L.elem[p] > y)
        {
            L.elem[q] = L.elem[p];
            q ++ ;
        } 

    L.length = q;
}