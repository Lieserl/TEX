#include "huffman.hpp"
#include "queue.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int statistic(int** w, char** ch, const char* file_name)
{
    FILE* file           = fopen(file_name, "r");
    int tw[MAX_CHAR_VAL] = {0};

    if (file == NULL)
    {
        puts("Fail to open the file.");
        return -1;
    }
    
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file))
        for (int i = 0; buffer[i] != '\0'; i ++ )
            tw[buffer[i]] ++ ;
    
    
    int n = 0, idx = 0;
    for (int i = 0; i < MAX_CHAR_VAL; i ++ )
        if (tw[i]) n ++ ;

    *w  = (int*)malloc((n + 1) * sizeof(int));
    *ch = (char*)malloc((n + 1) * sizeof(char));

    for (int i = 0; i < MAX_CHAR_VAL; i ++ )
        if (tw[i])
        {
            (*w)[ ++ idx] = tw[i];
            (*ch)[idx]    = char(i);
        }

    fclose(file);

    return idx;
}

HuffmanTree* buildHT(int w[], char ch[], int n)
{
    HuffmanTree* temp = (HuffmanTree*)malloc(sizeof(HuffmanTree));
    int size          = (n << 1) - 1;
    temp->num         = n;
    temp->data        = (HNode*)malloc((size + 1) * sizeof(HNode));

    Priority_Queue* heap = initQueue(n);

    for (int i = 1; i <= n; i ++ )
    {
        temp->data[i] = {0, 0, 0, w[i], ch[i]};
        enQueue(heap, i, temp->data[i].weight);
    }

    for (int i = n + 1; i <= size; i ++ ) temp->data[i] = {0, 0, 0, 0, '\0'};

    for (int i = n + 1; i <= size; i ++ )
    {
        int s1 = deQueue(heap), s2 = deQueue(heap);

        temp->data[s1].parent = temp->data[s2].parent = i;
        temp->data[i].lChild  = s1;
        temp->data[i].rChild  = s2;
        temp->data[i].weight  = temp->data[s1].weight + temp->data[s2].weight;

        enQueue(heap, i, temp->data[i].weight);
    }
    
    destroyQueue(heap);

    return temp;
}

void destroyHT(HuffmanTree* ht)
{
    if (ht == NULL) return;
    
    if (ht->data) free(ht->data);
    free(ht);
}

void saveHT(HuffmanTree* ht, const char* file_name)
{
    if (ht == NULL) return;
    
    FILE* file = fopen(file_name, "wb");
    
    if (file == NULL)
    {
        puts("Fail to open the file.");
        return;
    }
    
    fwrite(&ht->num, sizeof(int), 1, file);
    fwrite(ht->data, sizeof(HNode), (ht->num << 1), file);
    
    fclose(file);
}

HuffmanTree* loadHT(const char* file_name)
{
    HuffmanTree* temp = (HuffmanTree*)malloc(sizeof(HuffmanTree));
    FILE* file        = fopen(file_name, "rb");
    
    if (file == NULL || temp == NULL)
    {
        puts("Fail to load the file.");
        return NULL;
    }
    
    fread(&temp->num, sizeof(int), 1, file);
    
    temp->data = (HNode*)malloc(temp->num << 1 * sizeof(HNode));
    fread(temp->data, sizeof(HNode), temp->num << 1, file);

    fclose(file);
    
    return temp;
}

HCode* huffmanCoding(HuffmanTree* ht)
{
    HCode* temp = (HCode*)malloc(sizeof(HCode));
    int n       = temp->size = ht->num;
    temp->data  = (CNode*)malloc((n + 1) * sizeof(CNode));
    char* cd    = (char*)malloc(n * sizeof(char));
    cd[n - 1]   = '\0';

    for (int i = 1; i <= n; i ++ )
    {
        int start           = n - 1;
        temp->data[i].ch    = ht->data[i].ch;
        
        for (int u = i, f = ht->data[i].parent; f; u = f, f = ht->data[f].parent)
        {
            if (ht->data[f].lChild == u) cd[--start] = '0';
            else cd[--start] = '1';
        }

        temp->data[i].cd = (char*)malloc((n - start) * sizeof(char));
        strcpy(temp->data[i].cd, &cd[start]);
    }
    
    free(cd);

    return temp;
}

void enCodeText(HuffmanTree* ht, const char* input_file_name, const char* output_file_name)
{
    HCode* hc         = huffmanCoding(ht);
    FILE* input_file  = fopen(input_file_name, "r");
    FILE* output_file = fopen(output_file_name, "w");
    
    if (input_file == NULL || output_file == NULL)
    {
        puts("Fail to open the file.");
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file))
    {
        for (int i = 0; buffer[i] != '\0'; i ++ )
        {
            int l = 1, r = hc->size;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (hc->data[mid].ch >= buffer[i]) r = mid;
                else l = mid + 1;
            }

            fputs(hc->data[l].cd, output_file);
        }
    }
 
    fclose(input_file);
    fclose(output_file);
}

void deCodeText(HuffmanTree* ht, const char* input_file_name, const char* output_file_name)
{
    FILE* input_file  = fopen(input_file_name, "r");
    FILE* output_file = fopen(output_file_name, "w");
    int root          = (ht->num << 1) - 1;
    int curr          = root;

    if (input_file == NULL || output_file == NULL)
    {
        puts("Fail to open the file.");
        return;
    }

    char ch;
    while ((ch = fgetc(input_file)) != EOF)
    {
        curr = (ch == '0') ? ht->data[curr].lChild : ht->data[curr].rChild;
        
        if (!ht->data[curr].lChild && !ht->data[curr].rChild)
        {
            fputc(ht->data[curr].ch, output_file);
            curr = root;
        }
    }

    fclose(input_file);
    fclose(output_file);
}
