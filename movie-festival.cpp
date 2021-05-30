#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <regex>
#include <set>
#include <chrono>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <array>
#include <bitset>
#define rep(i, n) for (i = 0; i < n; ++i)
#define REP(i, k, n) for (i = k; i <= n; ++i)
#define REPR(i, k, n) for (i = k; i >= n; --i)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define uint unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define mxl INT64_MAX
#define mnl INT64_MIN
#define mx INT32_MAX
#define mn INT32_MIN
#define endl '\n'
using namespace std;
using namespace std::chrono;

ll mod(ll a, ll b)
{
    return (a % b + b) % b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0, s, e;
    unordered_map<int, int> dp;
    cin >> n;
    vector<pair<int, int>> A;
    while (n--)
    {
        cin >> s >> e;
        A.push_back({s, e});
        dp[e] = 1;
    }
    sort(begin(A), end(A));
    int m = A.size();
    for (int i = 0; i < m; i++)
    {
        tie(s, e) = A[i];
        for (int j = 0; j < i; j++)
        {
            if (s >= A[j].second)
            {
                dp[e] = max(dp[e], dp[A[j].second] + 1);
            }
        }
        ans = max(ans, dp[e]);
    }
    cout << ans << endl;
}