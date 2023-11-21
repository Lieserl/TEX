#include "linklist.h"
#include <stdlib.h>

LinkList* init_linklist(void)
{
    LinkList* ll = (LinkList*)malloc(sizeof(LinkList));
    ll->head = NULL;
    ll->length = 0;

    return ll;
}

void destory_linklist(LinkList* ll)
{
    if (ll == NULL) return;

    LNode* curr = ll->head;

    while (curr)
    {
        LNode* temp = curr;
        destory_linkstring(curr->line);
        curr = curr->next;
        free(temp);
    }

    free(ll);

    return;
}

LNode* get_row(LinkList* ll, int row_pos)
{
    LNode* curr = ll->head;
    for (int i = 0; i < row_pos; i ++ ) curr = curr->next;
    return curr;
}

bool insert_linklist(LinkList* ll, int row_pos, int col_pos, const char* s)
{
    if (row_pos < 0 || row_pos > ll->length) return false;

    LNode* prev = NULL, * curr = ll->head;
    for (int i = 0; i < row_pos; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    LNode* node = (LNode*)malloc(sizeof(LNode));
    node->line = init_linkstring();
    
    insert_substring(node->line, col_pos, s);
    node->next = curr;

    if (prev) prev->next = node;
    else ll->head = node;

    ll->length ++ ;

    return true;
}

bool delete_linklist(LinkList* ll, int pos, int len)
{
    if (len < 0 || pos >= ll->length || len == 0) return false;
    len = pos + len > ll->length ? ll->length - pos : len;

    LNode* prev = NULL, * curr = ll->head;
    for (int i = 0; i < pos; i ++ )
    {
        prev = curr;
        curr = curr->next;
    }

    for (int i = 0; i < len; i++)
    {
        LNode* temp = curr;
        curr = curr->next;
        destory_linkstring(temp->line);
        free(temp);
        ll->length -- ;
    }

    if (prev) prev->next = curr;
    else ll->head = curr;

    return true;
}
