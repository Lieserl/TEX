#include "bmp.hpp"
#include "queue.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bmpStatistic(int** w, unsigned char** pixel, const char* file_name)
{
    FILE* file            = fopen(file_name, "r");
    int tw[MAX_PIXEL_VAL] = {0};

    if (file == NULL)
    {
        puts("Fail to open the file.");
        return -1;
    }

    for (int i = 0; i < BMP_HEADER_SIZE; i ++ )
        if (getc(file) == EOF) return -1;
    
    unsigned char pi;
    while (fread(&pi, sizeof(unsigned char), 1, file)) tw[pi] ++ ;
    
    int n = 0, idx = 0;
    for (int i = 0; i < MAX_PIXEL_VAL; i ++ )
        if (tw[i]) n ++ ;

    *w  = (int*)malloc((n + 1) * sizeof(int));
    *pixel = (unsigned char*)malloc((n + 1) * sizeof(char));

    for (int i = 0; i < MAX_PIXEL_VAL; i ++ )
        if (tw[i])
        {
            (*w)[ ++ idx] = tw[i];
            (*pixel)[idx] = i;
        }

    fclose(file);

    return idx;
}

Bmptree* buildBmpHT(int w[], unsigned char pixel[], int n)
{
    Bmptree* temp = (Bmptree*)malloc(sizeof(Bmptree));
    int size      = (n << 1) - 1;
    temp->num     = n;
    temp->data    = (BmpNode*)malloc((size + 1) * sizeof(BmpNode));

    Priority_Queue* heap = initQueue(n);

    for (int i = 1; i <= n; i ++ )
    {
        temp->data[i] = {0, 0, 0, w[i], pixel[i]};
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

void destroyBmpHT(Bmptree* bmp)
{
    if (bmp == NULL) return;
    
    if (bmp->data) free(bmp->data);
    free(bmp);
}

BCode* bmpCoding(Bmptree* bmp)
{
    BCode* temp = (BCode*)malloc(sizeof(BCode));
    int n       = temp->size = bmp->num;
    temp->data  = (BNode*)malloc((n + 1) * sizeof(BNode));
    char* cd    = (char*)malloc(n * sizeof(char));
    cd[n - 1]   = '\0';

    for (int i = 1; i <= n; i ++ )
    {
        int start           = n - 1;
        temp->data[i].pixel = bmp->data[i].pixel;
        
        for (int u = i, f = bmp->data[i].parent; f; u = f, f = bmp->data[f].parent)
        {
            if (bmp->data[f].lChild == u) cd[ -- start] = '0';
            else cd[ -- start] = '1';
        }

        temp->data[i].cd = (char*)malloc((n - start) * sizeof(char));
        strcpy(temp->data[i].cd, &cd[start]);
    }
    
    free(cd);

    return temp;
}

void destroyBmpCode(BCode* bc)
{
    if (bc == NULL) return;
    
    if (bc->data) free(bc->data);
    free(bc);
}
