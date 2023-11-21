#include "linkstring.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

LinkString* init_linkstring(void)
{
    LinkString* ls = (LinkString*)malloc(sizeof(LinkString));
    ls->head = NULL;
    ls->length = 0;

    return ls;
}

void destory_linkstring(LinkString* ls)
{
    if (ls == NULL) return;

    StringNode* curr = ls->head;

    while (curr)
    {
        StringNode* temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(ls);

    return;
}

bool insert_substring(LinkString* ls, int pos, const char* substr)
{
    if (pos < 0) return false;
    pos = pos > ls->length ? ls->length : pos;

    StringNode* prev = NULL, * curr = ls->head;
    for (int i = 0; i < pos; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    
    for (int i = 0; substr[i] != '\0' && substr[i] != '\n'; i++)
    {
        StringNode* node = (StringNode*)malloc(sizeof(StringNode));
        node->ch = substr[i];
        node->next = curr;

        if (prev) prev->next = node;
        else ls->head = node;
        
        prev = node;
        
        ls->length ++ ;
    }

    return true;
}

bool delete_substring(LinkString* ls, int pos, int len)
{
    if (len < 0 || pos >= ls->length || len == 0) return false;
    len = pos + len > ls->length ? ls->length - pos : len;

    StringNode* prev = NULL, * curr = ls->head;

    for (int i = 0; i < pos; i ++ )
    {
        prev = curr;
        curr = curr->next;
    }

    for (int i = 0; i < len; i++)
    {
        StringNode* temp = curr;
        curr = curr->next;
        free(temp);
        ls->length -- ;
    }

    if (prev) prev->next = curr;
    else ls->head = curr;

    return true;
}

char* get_linkstring(LinkString* ls)
{
    char* res = (char*)malloc((ls->length + 1) * sizeof(char));
    if (res == NULL) return NULL;

    int index = 0;
    StringNode* curr = ls->head;
    while (curr)
    {
        res[index ++ ] = curr->ch;
        curr = curr->next;
    }

    res[index] = '\0';

    return res;
}

int find_substring(LinkString* ls, const char* pattern)
{
    if (ls->head == NULL) return -1;

    int len = (int)strlen(pattern) - 1;
    int* ne = (int*)malloc(len * sizeof(int));
    
    memset(ne, 0, len * sizeof(int));

    for (int i = 2, j = 0; i <= len; i ++ )
    {
        while (j && pattern[i] != pattern[j + 1]) j = ne[j];
        if (pattern[i] == pattern[j + 1]) j ++ ;
        ne[i] = j;
    }

    StringNode* curr = ls->head;
    for (int i = 0, j = 0; curr; curr = curr->next, i ++ )
    {
        while (j && curr->ch != pattern[j + 1]) j = ne[j];
        if (curr->ch == pattern[j + 1]) j ++ ;
        if (j == len) return i - len;
    }

    free(ne);

    return -1;
}
