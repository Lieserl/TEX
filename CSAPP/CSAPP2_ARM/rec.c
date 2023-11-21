int func4(int n, int e2)
{
    if (n <= 0) return 0;
    if (n == 1) return e2;
    return func4(n - 1, e2) + e2 + func4(n - 2, e2);
}

// 调用 func(5, elem2);