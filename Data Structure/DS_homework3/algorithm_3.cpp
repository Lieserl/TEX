bool testPalindrome(char *s)
{
    int len = strlen(s);
    if (len == 0 || len == 1) return true;

    int stack[N], top = -1;
    for (int i = 0; i < len / 2; i ++ ) stack[ ++ top] = s[i];

    for (int i = len / 2 + 1; i < len; i ++ )
        if (s[top -- ] != s[i])
            return false;
        
    return true;
}