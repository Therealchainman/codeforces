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

ll summation(vector<ll> A, ll target)
{
    ll res = 0;
    for (ll x : A)
    {
        res += abs(x - target);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, elem, curSum = 0;
    cin >> n;
    vector<ll> A;
    while (n--)
    {
        cin >> elem;
        curSum += elem;
        A.push_back(elem);
    }
    double cand = (double)curSum / (double)A.size();
    ll lower = curSum / A.size(), upper = (curSum + A.size()) / A.size();
    ll lowerSum = summation(A, lower), upperSum = summation(A, upper);
    if (lowerSum < upperSum)
    {
        cout << lowerSum << endl;
    }
    else
    {
        cout << upperSum << endl;
    }
}