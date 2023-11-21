#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;

const int maxn = 1e2 + 10;

inline int read()
{
    int f = 1, k = 0;
    char c = getchar();

    while (c < '0' || c > '9')
        c = getchar();

    while (c >= '0' && c <= '9')
    {
        k = k * 10 + c - '0';
        c = getchar();
    }

    return f * k;
}

// Write your code below :)

struct Edge
{
    Edge(int t, int v) : to(t), val(v) {}
    int to, val;
};

vector<Edge> s[maxn];
bool req[maxn][20], flag[maxn];
ll N, M, K, ans = 0, dp[maxn];

inline ll dfs(int u, int fa)
{
    ll maxx = 0;
    for (auto &v : s[u])
    {
        if (v.to == fa)
            continue;
        ll temp = dfs(v.to, u);

        if (flag[v.to])
        {
            flag[u] = true;
            dp[u] += dp[v.to] + v.val * 2;
            maxx = max(maxx, temp + v.val);
        }
    }

    return maxx;
}

// end here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Write your code below :)

    cin >> N >> M >> K;
    int u, v, w;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= K; j++)
            cin >> req[i][j];

    for (int i = 1; i < N; i++)
    {
        cin >> u >> v >> w;
        s[u].emplace_back(v, w);
        s[v].emplace_back(u, w);
    }

    for (int i = 1; i <= K; i++)
    {
        ll temp = 1e19 + 10;
        for (int j = 1; j <= N; j++)
        {
            memset(dp, 0, sizeof(dp));
            memset(flag, false, sizeof(flag));

            for (int k = 1; k <= N; k++)
                flag[k] = req[k][i];

            ll dis = dfs(j, 0);
            temp = min(dp[j] - dis, temp);
        }
        ans = max(ans, temp);
    }

    cout << ans << endl;

    // end here

    return 0;
}