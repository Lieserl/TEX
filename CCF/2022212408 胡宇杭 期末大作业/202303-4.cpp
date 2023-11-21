#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;

const int maxn = 8e5 + 10;
const int INF = 1e9 + 10;

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

#define ls u << 1
#define rs u << 1 | 1

struct Node
{
    int l, r, minn, maxx, cnt, laz;
} t[maxn << 2];

struct Oprt
{
    Oprt(int tt, int idd, string L, string R, string S) : type(tt), id(idd), l(L), r(R), s(S) {}
    int type, id, lr, rr, sr;
    string l, r, s;
};

vector<Oprt> oprt;
vector<string> cord;
int n, q, m;

inline void pushup(int u)
{
    t[u].cnt = t[ls].cnt + t[rs].cnt;
    t[u].maxx = max(t[ls].maxx, t[rs].maxx);
    t[u].minn = min(t[ls].minn, t[rs].minn);
}

inline void pushdown(int u)
{
    if (t[u].l == t[u].r)
        return;
    if (t[u].laz)
    {
        t[ls].laz = t[rs].laz = t[u].laz;
        t[ls].cnt = t[ls].r - t[ls].l + 1;
        t[rs].cnt = t[rs].r - t[rs].l + 1;
        t[ls].maxx = t[ls].minn = t[u].laz;
        t[rs].maxx = t[rs].minn = t[u].laz;
        t[u].laz = 0;
    }
}

inline void build(int u, int l, int r)
{
    t[u] = {l, r, INF, -INF, 0, 0};
    if (l == r)
        return;

    int mid = l + r >> 1;

    build(ls, l, mid);
    build(rs, mid + 1, r);

    pushup(u);
}

inline void query(int u, int l, int r, Node &res)
{
    if (t[u].l == l && t[u].r == r)
    {
        res.cnt += t[u].cnt;
        res.minn = min(res.minn, t[u].minn);
        res.maxx = max(res.maxx, t[u].maxx);
        return;
    }

    pushdown(u);

    int mid = t[u].l + t[u].r >> 1;

    if (l <= mid)
        query(ls, l, min(mid, r), res);
    if (r > mid)
        query(rs, max(mid + 1, l), r, res);
    return;
}

inline int query_2(int u, int s)
{
    if (t[u].l == t[u].r)
        return t[u].minn;

    pushdown(u);

    int mid = t[u].l + t[u].r >> 1;

    if (s <= mid)
        return query_2(ls, s);
    else
        return query_2(rs, s);
}

inline void update(int u, int l, int r, int id)
{
    if (t[u].l == l && t[u].r == r)
    {
        t[u].minn = t[u].maxx = id;
        t[u].cnt = t[u].r - t[u].l + 1;
        t[u].laz = id;
        return;
    }

    pushdown(u);

    int mid = t[u].l + t[u].r >> 1;

    if (l <= mid)
        update(ls, l, min(mid, r), id);
    if (r > mid)
        update(rs, max(mid + 1, l), r, id);

    pushup(u);
}

char carry(char ch)
{
    if (ch == '9')
        return 'a';
    else if (ch == 'f')
        return '0';
    else
        return ch + 1;
}

string add(string s)
{
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ':')
            continue;
        s[i] = carry(s[i]);
        if (s[i] != '0')
            break;
    }
    return s;
}

void discretization()
{
    sort(cord.begin(), cord.end());
    m = unique(cord.begin(), cord.end()) - cord.begin();
    cord.resize(m);

    for (auto &op : oprt)
    {
        if (op.type == 1 || op.type == 3)
        {
            op.lr = lower_bound(cord.begin(), cord.end(), op.l) - cord.begin() + 1;
            op.rr = lower_bound(cord.begin(), cord.end(), op.r) - cord.begin() + 1;
        }
        else
            op.sr = lower_bound(cord.begin(), cord.end(), op.s) - cord.begin() + 1;
    }

    return;
}

// end here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Write your code below :)

    cin >> n >> q;
    int type, id;
    string l, r, s;

    for (int i = 1; i <= q; i++)
    {
        cin >> type;

        if (type == 1)
        {
            cin >> id >> l >> r;
            oprt.emplace_back(type, id, l, r, " ");
        }
        else if (type == 2)
        {
            cin >> s;
            oprt.emplace_back(type, id, " ", " ", s);
        }
        else
        {
            cin >> l >> r;
            oprt.emplace_back(type, 0, l, r, " ");
        }
        if (type == 1 || type == 3)
            cord.push_back(l), cord.push_back(r), cord.push_back(add(r));
        else
            cord.push_back(s), cord.push_back(add(s));
    }

    discretization();
    build(1, 1, m);

    for (auto &op : oprt)
    {
        if (op.type == 1)
        {
            Node res = {op.lr, op.rr, INF, -INF, 0, 0};
            query(1, op.lr, op.rr, res);
            if (res.cnt == 0 || res.maxx == res.minn && res.minn == op.id && res.cnt != op.rr - op.lr + 1)
            {
                cout << "YES" << endl;
                update(1, op.lr, op.rr, op.id);
            }
            else
                cout << "NO" << endl;
        }
        else if (op.type == 2)
        {
            int temp = query_2(1, op.sr);
            if (temp == INF)
                cout << 0 << endl;
            else
                cout << temp << endl;
        }
        else
        {
            Node res = {op.lr, op.rr, INF, -INF, 0, 0};
            query(1, op.lr, op.rr, res);
            if (res.cnt == op.rr - op.lr + 1 && res.maxx == res.minn)
                cout << res.minn << endl;
            else
                cout << 0 << endl;
        }
    }

    // end here

    return 0;
}
