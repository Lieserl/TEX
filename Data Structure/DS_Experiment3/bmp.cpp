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

int solution(int *target, int **res, int len)
{
    int ptr = 0;
    int flag = 0;
    int id = 0;
    int num = 0;
    for (int i = 1; i < 101; i++)
        res[i] = (int *)malloc(sizeof(int) * 3);
    while (ptr != len)
    {
        if (flag == 0)
        {
            id = target[ptr++];
            flag = 1;
            num = target[ptr++];
        }
        else
        {
            int sum = 0;
            int maxdense = 0;
            for (int i = 0; i < num; i++)
            {
                sum += target[ptr];
                if (maxdense <= target[ptr])
                    maxdense = target[ptr];
                ptr++;
            }
            res[id][0] = id;
            res[id][1] = sum;
            res[id][2] = maxdense;
            flag = 0;
        }
    }

    for (int i = 1; i < id; i++)
    {
        for (int j = 1; j < id - i; j++)
        {
            if (res[j][1] < res[j + 1][1])
            {
                int *tmp = res[j];
                res[j] = res[j + 1];
                res[j + 1] = tmp;
            }
        }
    }

    int sb = 0;
    for (int i = 1; i < id + 1; i++)
    {
        if (res[i][1] < 3000)
        {
            sb = i;
            break;
        }
    }
    for (int i = sb; i < id; i++)
    {
        for (int j = sb; j < id - i + sb; j++)
        {
            if (res[j][2] < res[j + 1][2])
            {
                int *tmp = res[j];
                res[j] = res[j + 1];
                res[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < id; i++)
    {
        res[i][0] = res[i + 1][0];
    }
    return id;
}
