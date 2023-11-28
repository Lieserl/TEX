#ifndef bmp_hpp
#define bmp_hpp

#define MAX_PIXEL_VAL 256
#define BMP_HEADER_SIZE 1078

typedef struct
{
    int parent, lChild, rChild;
    int weight;
    unsigned char pixel;
} BmpNode;

typedef struct
{
    BmpNode* data;
    int num;
} Bmptree;

typedef struct
{
    char* cd;
    unsigned char pixel;
} BNode;

typedef struct
{
    BNode* data;
    int size;
} BCode;

int bmpStatistic(int** w, unsigned char** ch, const char* file_name);

Bmptree* buildBmpHT(int w[], unsigned char ch[], int n);

void destroyBmpHT(Bmptree* bmp);

BCode* bmpCoding(Bmptree* bmp);

#endif /* bmp_hpp */
