#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 6e3 + 10;

vector<int> edge[maxn];
int n, r[maxn], l, k, dp[maxn][2];
bool vis[maxn];

void dfs(int x)
{
    dp[x][0] = 0;
    dp[x][1] = r[x];

    for (auto &i : edge[x])
    {
        dfs(i);
        dp[x][0] += max(dp[i][1], dp[i][0]);
        dp[x][1] += dp[i][0];
    }
}

int main()
{
    cin >> n;
    memset(vis, false, sizeof(vis));

    for (int i = 1; i <= n; i++)
        cin >> r[i];

    for (int i = 1; i < n; i++)
    {
        cin >> l >> k;
        edge[k].push_back(l);
        vis[l] = true;
    }

    int rt = 0;
    while (vis[++rt])
    {
    }

    dfs(rt);

    cout << max(dp[rt][0], dp[rt][1]) << endl;

    // system("pause");

    return 0;
}