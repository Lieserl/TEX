#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 100005

int n, m, k, q, t[maxn], c[maxn];

int main()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        cin >> t[i] >> c[i];

    for (int i = 1; i <= m; i++)
    {
        cin >> q;
        int l = q + k, ans = 0;
        for (int j = 1; j <= n; j++)
        {
            int r = l + c[j] - 1;
            if (l <= t[j] && t[j] <= r)
                ans++;
        }
        cout << ans << endl;
    }

    // system("pause");

    return 0;
}