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
            tree[x] = v;
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
        printf("leafs left=%d, right=%d\n", tree[2 * x + 1], tree[2 * x + 2]);
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
        printf("tree[%d]=%d\n", x, tree[x]);
        flush(cout);
    }

    void update(int i, int v)
    {
        update(i, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
        {
            return INT_MAX;
        }
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        int m = (lx + rx) / 2;
        int s1 = query(l, r, 2 * x + 1, lx, m);
        int s2 = query(l, r, 2 * x + 2, m, rx);
        return min(s1, s2);
    }
    int query(int l, int r)
    {
        return query(l, r, 0, 0, size);
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
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            printf("update\n");
            flush(cout);
            int i, v;
            cin >> i >> v;
            st.update(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int res = st.query(l, r);
            cout << res << endl;
        }
    }
}