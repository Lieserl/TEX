Status EnQueue(LinkQueue &Q, ElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(Qnode));
    if (!p) exit("OVERFLOW");

    p->data = e;
    p->next = Q.rear->next;
    Q.rear->next = p;
    Q.rear = p;

    return OK;
}
