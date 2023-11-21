void GetMemory(char** p, int num)
{
    *p = (char *)malloc(sizeof(char) * num);
}

void Test(void)
{
    char *str = NULL;
    GetMemory(&str, 100);  // str 仍然为 NULL
    strcpy(str, "hello"); // 运行错误
}