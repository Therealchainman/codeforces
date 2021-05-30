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

template <class T>
void printVec(vector<T> vec)
{
    cout << "[";
    for (auto val : vec)
    {
        cout << val << ",";
    }
    cout << "]" << endl;
}

template <class T, class Y>
void printVecPair(vector<pair<T, Y>> vec)
{
    cout << "[" << endl;
    for (auto p : vec)
    {
        cout << "{" << p.first << "," << p.second << "},";
    }
    cout << "]" << endl;
}
template <class T>
void print2DVec(vector<vector<T>> M)
{
    cout << "[" << endl;
    for (vector<T> row : M)
    {
        cout << "[";
        for (auto val : row)
        {
            cout << val << ",";
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;
}

template <class T>
void printMap(T mp)
{
    cout << "{";
    for (auto &v : mp)
    {
        cout << "{" << v.first << "," << v.second << "},";
    }
    cout << "}" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, a, b, ans = INT32_MAX;
    vector<vector<ll>> works;
    vector<pair<ll, int>> stk;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        stk.push_back({a, i});
        stk.push_back({b, i});
        ans = min(ans, a + b);
    }
    cout << ans << endl;
    sort(stk.begin(), stk.end());
    int mxa;
    if (stk[0].second != stk[1].second)
    {
        mxa = stk[1].first;
    }
    else
    {
        mxa = stk[2].first;
    }
    ans = min(ans, mxa);
    cout << ans << endl;
}