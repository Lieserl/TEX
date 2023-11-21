Status InitQueue(LinkQueue &Q)
{
    Q.rear = (QueuePtr)malloc(sizeof(Qnode));
    if (!Q.rear) exit("OVERFLOW");

    Q.rear->next = Q.rear;

    return OK;
}


