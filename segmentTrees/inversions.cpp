#include <bits/stdc++.h>
using namespace std;
template <class T>
string toString(vector<T> &vec)
{
    stringstream ss;
    copy(vec.begin(), vec.end(), ostream_iterator<T>(ss, " "));
    return ss.str().c_str();
}
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
            tree[x] = 1; // value at leaf node
            return;
        }
        int m = (lx + rx) / 2;
        if (v <= m)
        {
            update(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            update(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void update(int i, int v)
    {
        update(i, v, 0, 0, size);
    }

    int query(int v, int x, int lx, int rx)
    {
        if (rx <= v)
        {
            return 0;
        }
        if (lx >= v)
        {
            return tree[x];
        }
        int m = (lx + rx) / 2;
        int sl = query(v, 2 * x + 1, lx, m);
        int sr = query(v, 2 * x + 2, m, rx);
        return sl + sr;
    }
    int query(int v)
    {
        return query(v, 0, 0, size);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    cin >> n;
    Segtree st;
    st.init(n); // empty segtree
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        ans[i] = st.query(p); // or is it here?
        st.update(i, p);
    }
    cout << toString(ans) << endl;
}