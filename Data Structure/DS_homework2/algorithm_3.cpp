void ListDel_L(LinkList L, int k)
{
    if (!L || k <= 0) return;

    LNode *p = L, *q = L;
    for (int i = 0; i < k; i ++ )
        if (!p->next) return;       
        else p = p->next;

    while (p->next)
    {
        p = p->next;
        q = q->next;
    }
    
    LNode *temp = q->next;
    q->next = q->next->next;

    free(temp);

    return;
}