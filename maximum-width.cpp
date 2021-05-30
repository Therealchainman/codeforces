#include <bits/stdc++.h>
using namespace std;
#define Max(x, y) ((x) > (y) ? x : y)
#define For(i, x, y) for (i = x; i <= (y); i++)
#define Down(i, x, y) for (i = x; i >= (y); i--)
string s, t;
int pos[200005];
int main()
{
    int n, m, i, j, mx = 0;
    cin >> n >> m >> s >> t;
    j = s.size();
    Down(i, t.size(), 1)
    {
        while (t[i - 1] != s[j - 1])
            j--;
        pos[i] = j--;
    }
    j = 1;
    For(i, 1, t.size())
    {
        while (t[i - 1] != s[j - 1])
            j++;
        mx = Max(mx, pos[i + 1] - j);
        j++;
    }
    cout << mx;
    return 0;
}