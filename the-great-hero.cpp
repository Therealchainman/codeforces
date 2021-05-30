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

bool heroWins(vector<ll> a, vector<ll> b, ll A, ll B)
{
    int n = a.size(), i = 0;
    ll x, y, strongest = 0, damage;
    for (int i = 0; i < n; i++)
    {
        {
            x = b[i] % A != 0 || b[i] < A ? b[i] / A + 1 : b[i] / A;
            strongest = max(strongest, a[i]);
            damage = x * a[i];
            B -= damage;
        }
    }
    if (B < 1)
    {
        B += strongest;
    }
    return B > 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    ll A, B, temp;
    cin >> t;
    while (t--)
    {
        cin >> A >> B >> n;
        vector<ll> a = vector<ll>(n, 0);
        vector<ll> b = vector<ll>(n, 0);
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            a[j] = temp;
        }
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            b[j] = temp;
        }
        if (heroWins(a, b, A, B))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}