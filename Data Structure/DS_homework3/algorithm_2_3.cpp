Status DeQueue(LinkQueue &Q, ElemType &e)
{
    if (Q.rear->next = Q.rear)
    {
        printf("Queue Underflow\n");
        return ERROR;
    }

    QueuePtr headNode = Q.rear->next;
    QueuePtr headElem = headNode->next;
    e = headElem->data;

    if (headElem == Q.rear)
    {
        Q.rear = headNode;
    }    
    
    headNode->next = headElem->next;
    free(headElem);

    return OK;
}