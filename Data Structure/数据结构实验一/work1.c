#include <stdio.h>
#include <stdlib.h>

const int N = 1e4 + 10;

// 定义学生结构数组
typedef struct
{
    int m_Id;
    char m_Name[20];
    int m_Age;
} Student;

// 封装至线性表
typedef struct
{
    Student students[N];
    int index; // index 储存线性表表长，以便后续文件读写操作
} StuList;

// 初始化线性表
void init(StuList *L, char *filename)
{
    // 以二进制方式读入文件
    FILE *file = fopen(filename, "rb");
    if (file == NULL) // 如果没有找到文件
    {
        L->index = 0; // 说明没有历史数据，初始化表长为0
        return;
    }
    
    // 有历史数据则会将其读入线性表
    // 先读取表长，再通过表长读取学生结构体数组信息
    fread(&(L->index), sizeof(int), 1, file);
    fread(L->students, sizeof(Student), L->index, file);

    fclose(file); // 关闭文件

    return;
}

// 功能项 1
void func1(StuList *L)
{
    // 五位学生学号相连且递增，所以只需读入第一位学生的学号
    int Stu_Id;

    printf("请输入第一位学生的学号\n");
    scanf("%d", &Stu_Id);

    // 读入学生数据
    for (int i = 1; i <= 5; i ++ )
    {
        L->students[L->index].m_Id = Stu_Id ++ ; // 学生学号每次迭代递增
        printf("请输入第%d位学生的姓名\n", i);
        scanf("%s", L->students[L->index].m_Name);
        printf("请输入第%d位学生的年龄\n", i);
        scanf("%d", &L->students[L->index ++ ].m_Age); // 该名学生信息读入完毕，令 index ++ 指向下一位学生的位置
    }

    return;
}

// 功能项 2
void func2(const StuList *L, const char *filename)
{
    // 以二进制方式写入文件
    FILE *file = fopen(filename, "wb");
    
    // 如果无法打开文件，则抛出异常
    if (file == NULL)
    {
        perror("Fail to open the file.");
        exit(EXIT_FAILURE);
    }

    // 先保存表长，再将学生数组存入文件中
    fwrite(&(L->index), sizeof(int), 1, file);
    fwrite(L->students, sizeof(Student), L->index, file);
    
    fclose(file); // 关闭文件
    
    return;
}

// 功能项 3
void func3(const char *input_file, const char *output_file)
{
    // 创建临时变量
    StuList temp;
    
    // 以二进制方式读入文件
    FILE *file = fopen(input_file, "rb");
    
    // 如果无法打开文件，则抛出异常
    if (file == NULL)
    {
        perror("Fail to open the file.");
        exit(EXIT_FAILURE);
    }
    
    // 先读取表长，再通过表长读取学生结构体数组信息
    fread(&(temp.index), sizeof(int), 1, file);
    fread(temp.students, sizeof(Student),temp.index, file);

    fclose(file); // 关闭文件
    
    // 以二进制方式写入文件
    file = fopen(output_file, "wb");
    
    // 如果无法打开文件，则抛出异常
    if (file == NULL)
    {
        perror("Fail to open the file.");
        exit(EXIT_FAILURE);
    }

    // 读入表长
    fwrite(&(temp.index), sizeof(int), 1, file);
    
    // 要求逆序输出，所以从表尾开始写入
    for (int i = temp.index - 1; i >= 0; i -- )
    {
        fwrite(&(temp.students[i]), sizeof(Student), 1, file);
    }

    fclose(file); // 关闭文件
    
    return;
}

int main(void)
{
    StuList L;

    init(&L, "input.dat");
    
    // for (int i = 0; i < 10; i ++ )
    //    printf("Id:%d, Name:%s, Age:%d\n", L.students[i].m_Id, L.students[i].m_Name, L.students[i].m_Age);
    
    func1(&L);

    func2(&L, "input.dat");
    
    func3("input.dat", "output.dat");
    
    return 0;
}
