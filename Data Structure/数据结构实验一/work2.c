#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int N = 2048;

int src[N][N], dst[N][N];

void copyij(int src[N][N], int dst[N][N])
{
    int i, j;
    for (i = 0; i < N;i ++ )
        for (j = 0; j < N; j ++ )
            dst[i][j] = src[i][j];
}

void copyji(int src[N][N], int dst[N][N])
{
    int i, j;
    for (j = 0; j < N; j ++ )
        for (i = 0; i < N; i ++ )
            dst[i][j] = src[i][j];
}

int main(void)
{
    // 初始化 src 数组
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )
            src[i][j] = i + j;
    
    // 记录时间
    clock_t start, end;
    
    start = clock();
    copyij(src, dst);
    end = clock();
    
    printf("It takes %f second to run copyij\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    memset(dst, 0, sizeof(dst));
    
    start = clock();
    copyji(src, dst);
    end = clock();
    
    printf("It takes %f second to run copyji\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    return 0;
}
