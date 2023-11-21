#include "texteditor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TextEditor* init_editor(void)
{
    TextEditor* editor = (TextEditor*)malloc(sizeof(TextEditor));
    editor->text = init_linklist();

    return editor;
}

void destory_editor(TextEditor* editor, int oprt)
{
    if (editor == NULL) return;
    
    destory_linklist(editor->text);
    
    if (oprt == 0) free(editor);

    return;
}

void show_menu(void)
{
    printf("------------------------------------\n");
    printf("---------- 1. Load File ------------\n");
    printf("---------- 2. Print Text -----------\n");
    printf("---------- 3. Insert Line ----------\n");
    printf("---------- 4. Delete Line ----------\n");
    printf("---------- 5. Insert Text ----------\n");
    printf("---------- 6. Delete Text-----------\n");
    printf("---------- 7. Search Text ----------\n");
    printf("---------- 8. Save File ------------\n");
    printf("---------- 9. Check Oprt -----------\n");
    printf("------------------------------------\n");
    
    return;
}

void print_text(TextEditor* editor, int start, int end)
{
    if (editor->text->head == NULL || start >= editor->text->length) return;
    end = end >= editor->text->length ? editor->text->length - 1 : end;
    
    LNode* curr = editor->text->head;
    for (int i = 0; i < start; i ++ ) curr = curr->next;
    
    for (int i = 0; i <= end - start; i ++ )
    {
        if (curr->line->head)
        {
            char* s = (char*)malloc((curr->line->length + 1) * sizeof(char));
            s = get_linkstring(curr->line);
            printf("%s", s);
        }
        
        puts("");
        
        curr = curr->next;
    }

    return;
}

bool read_file(TextEditor** editor, const char* file_name)
{
    destory_editor((*editor), 1);
    *editor = init_editor();
    FILE* file = fopen(file_name, "r");
    if (file == NULL) return false;

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        insert_linklist((*editor)->text, (*editor)->text->length, 0, line);
    }

    fclose(file);

    return true;
}

bool save_file(TextEditor* editor, const char* file_name)
{
    FILE* file = fopen(file_name, "w");
    if (file == NULL) return false;

    LNode* curr = editor->text->head;
    while (curr)
    {
        LinkString* ls = curr->line;
        char* s = get_linkstring(ls);

        if (s != NULL)
        {
            fputs(s, file);
            free(s);
        }

        fputs("\n", file);
        
        curr = curr->next;
    }

    fclose(file);

    return true;
}

bool check_oprt(TextEditor* editor)
{
    OpStack* bracketStack = init_stack();
    bool isMultiComment = false;
    
    LNode* curr = editor->text->head;

    while (curr)
    {
        StringNode* node = curr->line->head;
        bool isQuote[2];
        memset(isQuote, false, sizeof(isQuote));
        
        if (node && node->ch == '#')
        {
            curr = curr->next;
            continue;
        }
        
        while (node)
        {
            char ch[3] = "\"\'";
            bool isMismatch = false;
            bool isSkip = false;
            
            if (node->ch == '/' && node->next && node->next->ch == '/') break;
            
            if (node->ch == '/' && node->next && node->next->ch == '*') isMultiComment = true;
            else if (node->ch == '*' && node->next && node->next->ch == '/') isMultiComment = false;
            else if (isMultiComment) isSkip = true;
            
            for (int i = 0; i < 2; i ++ )
            {
                if (node->ch == ch[i] && !isQuote[i]) isQuote[i] = true;
                else if (node->ch == ch[i] && isQuote[i]) isQuote[i] = false;
                else if (isQuote[i]) isSkip = true;
            }
            
            if (isSkip)
            {
                node = node->next;
                continue;
            }
            
            if (node->ch == '{' || node->ch == '(') push(bracketStack, node->ch);
            else if (node->ch == '}')
            {
                if (empty(bracketStack)) isMismatch = true;
                else if (top(bracketStack) != '{') isMismatch = true;
                else pop(bracketStack);
            }
            else if (node->ch == ')')
            {
                if (empty(bracketStack)) isMismatch = true;
                else if (top(bracketStack) != '(') isMismatch = true;
                else pop(bracketStack);
            }
            
            if (isMismatch)
            {
                destory_stack(bracketStack);
                return false;
            }
            
            node = node->next;
        }

        curr = curr->next;
    }

    bool flag = empty(bracketStack);
    destory_stack(bracketStack);

    return flag;
}
