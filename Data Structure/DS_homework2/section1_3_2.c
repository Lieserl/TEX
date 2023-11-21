void BB(LNode *s, LNode *q)
{
    p = s;
    while (p->next != q) p = p->next;
    p->next = s;
}// BB

void AA(LNode *pa, LNode *pb)
{
    // pa和pb分别指向不带头结点单循环链表中的两个结点
    BB(pa, pb);
    BB(pb, pa);
}// AA