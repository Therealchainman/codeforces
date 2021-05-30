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

struct p2
{
    int x, y;
    p2() : x(0), y(0) {}
    p2(int x, int y) : x(x), y(y) {}

    p2 &operator+=(const p2 &b)
    {
        x + b.x;
        y + b.y;
        return *this;
    }

    p2 &operator-=(const p2 &b)
    {
        x - b.x;
        y - b.y;
        return *this;
    }

    int &operator[](int index)
    {
        if (index == 0)
        {
            return x;
        }
        return y;
    }
};

bool solve(int X, int Y, string directions)
{
    map<char, p2> dirMap;
    dirMap['R'] = p2(1, 0);
    dirMap['L'] = p2(-1, 0);
    dirMap['U'] = p2(0, 1);
    dirMap['D'] = p2(0, -1);
    map<char, int> count;
    int x = 0, y = 0;
    for (char d : directions)
    {
        count[d]++;
        x += dirMap[d][0];
        y += dirMap[d][1];
    }
    while (x < X && count['L'] > 0)
    {
        count['L']--;
        x++;
    }
    while (x > X && count['R'])
    {
        count['R']--;
        x--;
    }
    while (y < Y && count['D'] > 0)
    {
        count['D']--;
        y++;
    }
    while (y > Y && count['U'] > 0)
    {
        count['U']--;
        y--;
    }
    return x == X && y == Y;
}

int main()
{
    int n, X, Y;
    string directions;
    cin >> n;
    while (n > 0)
    {
        cin >> X >> Y;
        cin >> directions;
        if (solve(X, Y, directions))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        n--;
    }
}