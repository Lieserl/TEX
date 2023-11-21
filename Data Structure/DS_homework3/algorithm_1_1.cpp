Status InitStack(SqStack &tws)
{
    tws.base = (ElemType *)malloc(M * sizeof(ElemType));
    if (!tws.base) exit("OVERFLOW");

    tws.top1 = tws.base;
    tws.top2 = tws.base + M - 1;
    tws.stacksize = M;

    return OK;
}


