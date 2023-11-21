#include "texteditor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    TextEditor* editor = init_editor();
    int oprt = 0;
    
    do
    {
        show_menu();
        scanf("%d", &oprt);
        
        switch (oprt) 
        {
            case 0:
            {
                exit(0);
            }
            case 1:
            {
                char file_name[20] = "";
                puts("Please enter the file name.");
                scanf("%s", file_name);
                if (read_file(&editor, file_name)) puts("Load Success.");
                else puts("Load Failed.");
                break;
            }
            case 2:
            {
                int start, end;
                puts("Please enter the start and end position.");
                scanf("%d%d", &start, &end);
                print_text(editor, start, end);
                break;
            }
            case 3:
            {
                int pos = 0;
                char buffer[1024];
                puts("Please enter the row you want to insert.");
                scanf("%d", &pos);
                while (getchar() != '\n');
                
                puts("Please enter the words.");
                fgets(buffer, 1024, stdin);
                if (insert_linklist(editor->text, pos, 0, buffer)) puts("Insert Success.");
                else puts("Insert Failed.");
                break;
            }
            case 4:
            {
                int pos = 0, len = 0;
                puts("Please enter the row you want to delete, and the length.");
                scanf("%d%d", &pos, &len);
                if (delete_linklist(editor->text, pos, len)) puts("Delete Success.");
                else puts("Delete Failed.");
                break;
            }
            case 5:
            {
                int row_pos = 0, col_pos = 0;
                char buffer[1024];
                puts("Please enter the row and column you want to insert.");
                scanf("%d%d ",&row_pos, &col_pos);
                while (getchar() != '\n');
                
                puts("Please enter the words.");
                fgets(buffer, 1024, stdin);
                if (insert_substring(get_row(editor->text, row_pos)->line, col_pos, buffer)) puts("Insert Success.");
                else puts("Insert Failed.");
                break;
            }
            case 6:
            {
                int row_pos = 0, col_pos = 0, len = 0;
                puts("Please enter the row and column you want to delete, and the length.");
                scanf("%d%d%d",&row_pos, &col_pos, &len);
                if (delete_substring(get_row(editor->text, row_pos)->line, col_pos, len)) puts("Delete Success.");
                else puts("Delete Failed.");
                break;
            }
            case 7:
            {
                int row_pos = 0;
                char pattern[1024];
                puts("Please enter the row.");
                scanf("%d",&row_pos);
                while (getchar() != '\n');
                
                puts("Please enter the pattern string.");
                fgets(pattern, 1024, stdin);
                pattern[strlen(pattern) - 1] = '\0';
                printf("%d\n", find_substring(get_row(editor->text, row_pos)->line, pattern));
                break;
            }
            case 8:
            {
                puts("Please enter the file name.");
                char file_name[20] = "";
                scanf("%s", file_name);
                if (save_file(editor, file_name)) puts("Save Success.");
                else puts("Save Failed.");
                break;
            }
            case 9:
            {
                if (check_oprt(editor)) puts("OK");
                else puts("ERROR");
                break;
            }
            default:
                puts("Mistaken input, try again");
                break;
        }
    } while (oprt);
    
    
    return 0;
}
