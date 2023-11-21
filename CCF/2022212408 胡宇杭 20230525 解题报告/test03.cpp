#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll l, r, num[12], dp[11][11][11][2][2][2];

ll dfs(int pos, int pre_1, int pre_2, bool state, bool flag, bool _4, bool _8)
{
    if (_4 && _8)
        return 0;
    if (pos <= 0)
        return state;
    if (!flag && dp[pos][pre_1][pre_2][state][_4][_8] != -1)
        return dp[pos][pre_1][pre_2][state][_4][_8];

    int lim = flag ? num[pos] : 9;
    ll ret = 0;

    for (int i = 0; i <= lim; i++)
        ret += dfs(pos - 1, i, pre_1, state || (i == pre_2 && i == pre_1), flag && (i == num[pos]), _4 || (i == 4), _8 || (i == 8));

    if (!flag)
        dp[pos][pre_1][pre_2][state][_4][_8] = ret;

    return ret;
}

ll solve(ll x)
{
    if (x < 1e10)
        return 0;

    int len = 0;
    ll ret = 0;
    memset(dp, -1, sizeof(dp));

    while (x)
    {
        num[++len] = x % 10;
        x /= 10;
    }

    for (int i = 1; i <= num[len]; i++)
        ret += dfs(10, i, 0, 0, i == num[len], i == 4, i == 8);

    return ret;
}

int main()
{
    cin >> l >> r;

    cout << solve(r) - solve(l - 1) << endl;

    // system("pause");

    return 0;
}