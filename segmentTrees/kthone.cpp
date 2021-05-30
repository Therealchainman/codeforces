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
        tree.assign(2 * size, 0LL);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    void update(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] ^= 1;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
        {
            update(i, 2 * x + 1, lx, m);
        }
        else
        {
            update(i, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void update(int i)
    {
        update(i, 0, 0, size);
    }

    int query(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            printf("lx=%d\n", lx);
            flush(cout);
            return lx;
        }
        int m = (lx + rx) / 2;
        int sl = tree[2 * x + 1];
        if (k < sl)
        {
            return query(k, 2 * x + 1, lx, m);
        }
        return query(k - sl, 2 * x + 2, m, rx);
    }
    int query(int k)
    {
        return query(k, 0, 0, size);
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
        st.set(i, a);
    }
    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i;
            cin >> i;
            st.update(i);
        }
        else
        {
            int k;
            cin >> k;
            int res = st.query(k);
            cout << res << endl;
        }
    }
}