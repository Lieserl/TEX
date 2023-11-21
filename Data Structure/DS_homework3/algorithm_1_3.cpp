Status pop(SqStack &tws, int i, ElemType &e)
{
    if (i == 0)
    {
        if (tws.top1 == tws.base)
        {
            printf("Stack1 Underflow\n");
            return ERROR;
        } 

        e = * -- wts.top1;
    }
    else if (i == 1)
    {
        if (tws.top2 == tws.base + tws.stacksize - 1)
        {
            printf("Stack2 Underflow\n");
            return ERROR;
        } 

        e = * ++ wts.top2;
    }

    return OK;
}