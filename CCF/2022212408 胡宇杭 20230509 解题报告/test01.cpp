#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 100005

int n, k, op1, op2, ans = 0;
bool initial[maxn];

int main()
{
    cin >> n >> k;

    initial[0] = true;
    for (int i = 1; i <= k; i++)
    {
        cin >> op1 >> op2;
        if (initial[op2] == true)
            initial[op1] = true;
        else
            ans++, initial[op1] = true;
    }

    cout << ans << endl;

    // system("pause");

    return 0;
}