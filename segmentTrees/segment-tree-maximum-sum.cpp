#include <bits/stdc++.h>
using namespace std;
struct Data
{
    long long int sum, seg, pref, suf;

    void update(Data &lother, Data &rother)
    {
        sum = lother.sum + rother.sum;
        seg = max({lother.seg, rother.seg, lother.suf + rother.pref});
        pref = max(lother.pref, lother.sum + rother.pref);
        suf = max(rother.suf, rother.sum + lother.suf);
    }
    void set(long long int v)
    {
        sum = v, seg = v, pref = v, suf = v;
    }
};
// 0-indexed tree representation
struct Segtree
{
    int size;
    vector<Data> tree;

    void init(int n)
    {
        size = 1;
        // This is because we may need to pad, even if n=5, we need not vector of size 10, we need vector of size 16
        while (size < n)
        {
            size *= 2;
        }
        tree.assign(2 * size, Data{0, 0, 0, 0});
    }

    void update(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x].set(v);
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
        Data dl = tree[2 * x + 1], dr = tree[2 * x + 2];
        tree[x].update(dl, dr);
    }

    void update(int i, int v)
    {
        update(i, v, 0, 0, size);
    }

    Data query(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
        {
            return Data{0, 0, 0, 0};
        }
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        int m = (lx + rx) / 2;
        Data dl = query(l, r, 2 * x + 1, lx, m), dr = query(l, r, 2 * x + 2, m, rx);
        return Data{dl.sum + dr.sum, max({dl.seg, dr.seg, dl.suf + dr.pref}), max(dl.pref, dl.sum + dr.pref), max(dr.suf, dr.sum + dl.suf)};
    }
    Data query(int l, int r)
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
    Data res = st.query(0, n);
    cout << max(0LL, res.seg) << endl;
    while (m--)
    {
        int i, v;
        cin >> i >> v;
        st.update(i, v);
        Data res = st.query(0, n);
        cout << max(0LL, res.seg) << endl;
    }
}