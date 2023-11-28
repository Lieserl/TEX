#ifndef huffman_hpp
#define huffman_hpp

#define MAX_CHAR_VAL 128

typedef struct
{
    int parent, lChild, rChild;
    int weight;
    char ch;
} HNode;

typedef struct
{
    HNode* data;
    int num;
} HuffmanTree;

typedef struct
{
    char* cd;
    char ch;
} CNode;

typedef struct
{
    CNode* data;
    int size;
} HCode;

int statistic(int** w, char** ch, const char* file_name);

HuffmanTree* buildHT(int w[], char ch[], int n);

void destroyHT(HuffmanTree* ht);

void saveHT(HuffmanTree* ht, const char* file_name);

HuffmanTree* loadHT(const char* file_name);

HCode* huffmanCoding(HuffmanTree* ht);

void enCodeText(HuffmanTree* ht, const char* input_file_name, const char* output_file_name);

void deCodeText(HuffmanTree* ht, const char* input_file_name, const char* output_file_name);

void destroyHC(HCode* hc);

#endif /* huffman_hpp */