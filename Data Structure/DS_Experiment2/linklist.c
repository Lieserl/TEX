#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

#include "linkstring.h"

typedef struct LNode
{
    LinkString* line;
    struct LNode* next;
} LNode;

typedef struct
{
    LNode* head;
    int length;
} LinkList;

LinkList* init_linklist(void);

LNode* get_row(LinkList* ll, int row_pos);

void destory_linklist(LinkList* ll);

bool insert_linklist(LinkList* ll, int row_pos, int col_pos, const char* s);

bool delete_linklist(LinkList* ll, int pos, int len);

#endif // !LINKLIST_H
