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
    ll t, n, p, stop, idx;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> P(n, 0);
        vector<pair<ll, ll>> mono;
        for (int i = 0; i < n; i++)
        {
            cin >> p;
            P[i] = p;
        }
        stop = n;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!mono.empty() && mono.back().first < P[i])
            {
                mono.pop_back();
            }
            mono.push_back({P[i], i});
        }
        vector<ll> order;
        for (int i = 0; i < mono.size(); i++)
        {
            tie(p, idx) = mono[i];
            for (int j = idx; j < stop; j++)
            {
                order.push_back(P[j]);
            }
            stop = idx;
        }
        for (int i = 0; i < n; i++)
        {
            cout << order[i] << " ";
        }
        cout << endl;
    }
}