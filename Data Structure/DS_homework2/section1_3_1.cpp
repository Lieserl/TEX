// L是无头结点的单链表
Status A(LinkedList &L)
{
    if(L && L->next){
        Q = L; L = L->next; P = L;
        while(P->next) P = P->next;
        P->next = Q; Q->next = NULL;
    }
    return OK;
}