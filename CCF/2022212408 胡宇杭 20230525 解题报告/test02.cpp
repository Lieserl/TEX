#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 105;

int n, m, a[maxn][maxn], dp[maxn];

int main()
{
    while ((cin >> n >> m) && n && m)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++)
            for (int j = m; j >= 0; j--)
                for (int k = 1; k <= m; k++)
                    if (j >= k)
                        dp[j] = max(dp[j], dp[j - k] + a[i][k]);

        cout << dp[m] << endl;
    }

    // system("pause");

    return 0;
}