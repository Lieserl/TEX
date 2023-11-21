L = (LinkList)malloc(sizeof(LNode));
p = L;

for (i = 1; i <= 4; i ++ )
{
    P->next = (LinkList)malloc(sizeof(LNode));
    P = P->next; P->data = i * 2 - 1;
}

P->next = NULL;
for (i = 4; i >= 1; i -- )
    Ins_LinkList(L,i + 1, i * 2);

for (i = 1; i <= 3; i ++ ) 
    Del_LinkList(L,i);