#pragma once
#ifndef LINKSTRING_H
#define LINKSTRING_H

#include <stdbool.h>

typedef struct StringNode
{
    char ch;
    struct StringNode* next;
} StringNode;

typedef struct
{
    StringNode* head;
    int length;
} LinkString;

LinkString* init_linkstring(void);

void destory_linkstring(LinkString* ls);

bool insert_substring(LinkString* ls, int pos, const char* substr);

bool delete_substring(LinkString* ls, int pos, int len);

char* get_linkstring(LinkString* ls);

int find_substring(LinkString* ls, const char* pattern);

#endif // !LINKSTRING_H
