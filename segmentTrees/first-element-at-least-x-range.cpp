#include <bits/stdc++.h>
using namespace std;
// 0-indexed tree representation
struct Segtree
{
    int size;
    vector<int> tree;

    void init(int n)
    {
        size = 1;
        // This is because we may need to pad, even if n=5, we need not vector of size 10, we need vector of size 16
        while (size < n)
        {
            size *= 2;
        }
        tree.assign(2 * size, 0);
    }

    void update(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v; // leaf node set single value
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
        {
            update(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            update(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v)
    {
        update(i, v, 0, 0, size);
    }

    int query(int y, int x, int lx, int rx, int l)
    {
        if (tree[x] < y || rx <= l)
        {
            return -1;
        }
        if (rx - lx == 1)
        {
            return lx;
        }
        int m = (lx + rx) / 2;
        int res = query(y, 2 * x + 1, lx, m, l);
        if (res == -1)
        {
            return query(y, 2 * x + 2, m, rx, l);
        }
        return res;
    }

    int query(int y, int l)
    {
        return query(y, 0, 0, size, l);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a;
    cin >> n >> m;
    Segtree st;
    st.init(n); // empty segtree
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        st.update(i, a);
    }
    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, v;
            cin >> i >> v;
            st.update(i, v);
        }
        else
        {
            int x, l;
            cin >> x >> l;
            int res = st.query(x, l);
            cout << res << endl;
        }
    }
}