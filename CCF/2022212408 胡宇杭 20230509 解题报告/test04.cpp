#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int maxn = 1e5 + 10;

struct Node
{
    Node(int ee, long long v) : e(ee), val(v) {}

    int e;
    long long val;

    bool operator<(const Node &n) const
    {
        if (this->val == n.val)
            return this->e < n.e;
        return this->val > n.val;
    }
};

struct Info
{
    Info(int uu, int vv, long long v) : u(uu), v(vv), val(v) {}
    int u, v;
    long long val;
};

set<Node> node[maxn];
map<pair<int, int>, long long> mem;
vector<Info> t[maxn];
int n, m, u, v, x, y, k, l, id, p, q, ln = 0, pn = 0;

inline int read()
{
    int f = 1, k = 0;
    char c = getchar();

    while (c < '0' || c > '9')
    {
        c = getchar();
    }

    while (c >= '0' && c <= '9')
    {
        k = k * 10 + c - '0';
        c = getchar();
    }
    return f * k;
}

inline bool islonely(int s)
{
    if (node[s].begin()->val == 0 || node[s].begin()->e == s)
        return true;
    return false;
}

inline bool ispair(int s)
{
    if (islonely(s))
        return false;
    if (!islonely(node[s].begin()->e) && node[node[s].begin()->e].begin()->e == s)
        return true;
    return false;
}

inline void oprt(int u, int v, long long val)
{
    long long pre_val = mem[make_pair(u, v)];
    mem[make_pair(u, v)] += val;

    ln -= islonely(u);
    pn -= ispair(u);

    Node temp(v, pre_val);
    node[u].erase(temp);
    node[u].emplace(v, mem[make_pair(u, v)]);

    ln += islonely(u);
    pn += ispair(u);
}

int main()
{
    n = read(), m = read();
    ln = n;

    for (int i = 1; i <= m; i++)
    {
        for (auto &j : t[i])
        {
            oprt(j.u, j.v, j.val);
            oprt(j.v, j.u, j.val);
        }

        k = read();
        for (int j = 1; j <= k; j++)
        {
            u = read(), v = read(), x = read(), y = read();
            if (i + y <= m)
                t[i + y].emplace_back(u, v, -x);
            oprt(u, v, x);
            oprt(v, u, x);
        }

        l = read();
        for (int j = 1; j <= l; j++)
        {
            id = read();
            if (islonely(id))
                printf("0\n");
            else
                printf("%d\n", node[id].begin()->e);
        }

        p = read(), q = read();
        if (p)
            printf("%d\n", ln);
        if (q)
            printf("%d\n", pn);
    }

    // system("pause");

    return 0;
}
