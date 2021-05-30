#include <bits/stdc++.h>
using namespace std;
const int base = 128 * 1024;
long long int tree[base << 1];

void update(int i, int val)
{
    tree[base + i] = val;
    for (int x = base + i >> 1; x >= 1; x >>= 1)
    {
        tree[x] = tree[x << 1] + tree[(x << 1) ^ 1];
    }
}

long long int query(int r)
{
    if (r < 0)
    {
        return 0;
    }
    long long int res = tree[base + r];
    for (int x = base + r; x != 1; x >>= 1)
    {
        if ((x & 1) > 0)
        {
            res += tree[x - 1];
        }
    }
    return res;
}

long long int range(int l, int r)
{
    return query(r - 1) - query(l - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        update(i, a);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, v;
            cin >> i >> v;
            update(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            long long int res = range(l, r);
            cout << res << endl;
        }
    }
}