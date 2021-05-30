#include <bits/stdc++.h>
using namespace std;

struct Segtree
{
    int size;
    vector<pair<int, int>> tree;

    void init(int n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        tree.assign(size * 2, {0, 0});
    }

    pair<int, int> merge(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
        {
            return make_pair(a.first, a.second + b.second);
        }
        return a.first < b.first ? a : b;
    }

    void update(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = {v, 1}; // leaf nodes have count of 1
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
        pair<int, int> lp = tree[2 * x + 1];
        pair<int, int> rp = tree[2 * x + 2];
        tree[x] = merge(lp, rp);
    }

    void update(int i, int v)
    {
        update(i, v, 0, 0, size);
    }

    pair<int, int> query(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l)
        {
            return {INT_MAX, 0};
        }
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        int m = (lx + rx) / 2;
        pair<int, int> s1 = query(l, r, 2 * x + 1, lx, m);
        pair<int, int> s2 = query(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
        
    }

    pair<int, int> query(int l, int r)
    {
        return query(l, r, 0, 0, size);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Segtree st;
    st.init(n);
    for (int i = 0; i < n; i++)
    {
        int a;
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
            int l, r;
            cin >> l >> r;
            pair<int, int> res = st.query(l, r);
            cout << res.first << " " << res.second << endl;
        }
    }
}