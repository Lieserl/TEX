#include <stdio.h>
#include <stdlib.h>
#include "queue.hpp"
#include "huffman.hpp"
#include "bmp.hpp"

void testSaveLoadFuction()
{
    int* w;
    char* ch;
    int n = statistic(&w, &ch, "ToBeTran.txt");
    
    HuffmanTree* source = buildHT(w, ch, n);
    
    if (w) free(w);
    if (ch) free(ch);
    
    saveHT(source, "hfmTree.dat");
    
    HuffmanTree* copy = loadHT("hfmTree.dat");
    
    puts("The source data:");
    for (int i = 1; i <= 2 * n - 1; i ++ )
        if (i <= n) printf("char: %c parent: %d lchild: %d rchild: %d weight: %d\n", source->data[i].ch, source->data[i].parent, source->data[i].lChild, source->data[i].rChild, source->data[i].weight);
        else printf("EMPTY   parent: %d lchild: %d rchild: %d weight: %d\n", source->data[i].parent, source->data[i].lChild, source->data[i].rChild, source->data[i].weight);
        
    puts("");
    
    puts("The copy data:");
    for (int i = 1; i <= 2 * n - 1; i ++ )
        if (i <= n) printf("char: %c parent: %d lchild: %d rchild: %d weight: %d\n", copy->data[i].ch, copy->data[i].parent, copy->data[i].lChild, copy->data[i].rChild, copy->data[i].weight);
        else printf("EMPTY   parent: %d lchild: %d rchild: %d weight: %d\n", copy->data[i].parent, copy->data[i].lChild, copy->data[i].rChild, copy->data[i].weight);
    
    destroyHT(source);
    destroyHT(copy);
}

void testHT()
{
    int* w;
    char* ch;
    int n = statistic(&w, &ch, "ToBeTran.txt");
    
    HuffmanTree* ht = buildHT(w, ch, n);
    HCode* hc = huffmanCoding(ht);
    
    if (w) free(w);
    if (ch) free(ch);
    
    for (int i = 1; i <= n; i ++ ) printf("%c: %s\n", hc->data[i].ch, hc->data[i].cd);
    
    destroyHT(ht);
}

void testCodeFunction()
{
    HuffmanTree* ht = loadHT("hfmTree.dat");
    
    enCodeText(ht, "ToBeTran.txt", "CodeFile.txt");
    deCodeText(ht, "CodeFile.txt", "TextFile.txt");
    
    destroyHT(ht);
}

void testBmpCodeFunction()
{
    int* w;
    unsigned char* pixel;
    int n = bmpStatistic(&w, &pixel, "lena.bmp");
    
    Bmptree* bmp = buildBmpHT(w, pixel, n);
    BCode* bc = bmpCoding(bmp);
    
    for (int i = 1; i <= n; i ++ ) printf("pixel %d: weight: %d code:%s\n", bc->data[i].pixel, w[i], bc->data[i].cd);
    
    printf("The sum of the pixel is %d\n", bmp->data[2 * n - 1].weight);
    
    if (w) free(w);
    if (pixel) free(pixel);
    
    destroyBmpHT(bmp);
    destroyBmpCode(bc);
}

int main()
{
    // testHT();
    
    // testSaveLoadFuction();
    
    // testCodeFunction();
    
     testBmpCodeFunction();
    
    return 0;
}
