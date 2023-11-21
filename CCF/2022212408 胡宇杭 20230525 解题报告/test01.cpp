#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1005;

int t, n, c, w[maxn], v[maxn], dp[maxn];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> c;

        for (int i = 1; i <= n; i++)
            cin >> v[i];

        for (int i = 1; i <= n; i++)
            cin >> w[i];

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++)
            for (int j = c; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

        cout << dp[c] << endl;
    }

    // system("pause");

    return 0;
}