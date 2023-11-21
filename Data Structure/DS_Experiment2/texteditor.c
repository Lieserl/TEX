#pragma once
#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "linklist.h"
#include "oprtstack.h"

typedef struct
{
    LinkList* text;
} TextEditor;

TextEditor* init_editor(void);

void destory_editor(TextEditor* editor, int oprt);

void show_menu(void);

bool read_file(TextEditor** editor, const char* file_name);

bool save_file(TextEditor* editor, const char* file_name);

void print_text(TextEditor* editor, int start, int end);

bool check_oprt(TextEditor* editor);

#endif // !TEXTEDITOR_H
