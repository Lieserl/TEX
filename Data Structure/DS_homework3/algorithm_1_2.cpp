Status push(SqStack &tws, int i, ElemType e)
{
    if (tws.top1 > tws.top2)
    {
        printf("StackFull\n");
        return ERROR;
    }

    if (i == 0) *tws.top1 ++ = e;
    else if (i == 1) *tws.top2 -- = e;
    else
    {
        printf("Unkown Opeator\n");
        return ERROR;
    }

    return OK;
}