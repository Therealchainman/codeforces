
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

// template <class T>
// void printMap(T mp)
// {
//     cout << "{";
//     for (auto &v : mp)
//     {
//         cout << "{" << v.first << "," << v.second << "},";
//     }
//     cout << "}" << endl;
// }

unordered_map<int, int> next, prev;
// Find if this the value at index i is a peak, by looking at its right neighbor jj and left neighbor ii.
bool update(int i, vector<int> nums)
{
    int ii = nex[i];
    int jj = pre[i];
    if ((ii == INT_MIN || nums[i] > nums[ii]) && (jj == INT_MIN || nums[i] > nums[jj]))
    {
        return true;
    }
    return false;
}

vector<int> solve(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
    {
        return nums;
    }
    vector<int> ans;
    priority_queue<pair<int, int>> minPeaks;
    nex.clear();
    pre.clear();
    // build the next and previous hash tables
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            pre[i] = INT_MIN;
            nex[i] = i + 1;
        }
        else if (i == n - 1)
        {
            pre[i] = i - 1;
            nex[i] = INT_MIN;
        }
        else
        {
            pre[i] = i - 1;
            nex[i] = i + 1;
        }
    }
    // Find the initial min peaks
    for (int i = 0; i < n; i++)
    {
        int ii = nex[i], jj = pre[i];
        if ((ii == INT_MIN || nums[i] > nums[ii]) && (jj == INT_MIN || nums[i] > nums[jj]))
        {
            minPeaks.push({-nums[i], i});
        }
    }
    while (!minPeaks.empty())
    {
        int peak, i;
        tie(peak, i) = minPeaks.top();
        minPeaks.pop();
        ans.push_back(-peak);
        // next[i]=2, prev[i]=0, so the prev[2]=0, next[0]=2
        // The previous of the next right neighbor index will be the previous of the current index.
        if (nex[i] != INT_MIN)
        {
            pre[nex[i]] = pre[i];
        }
        // The next of the previous left neighbor index will be the next of the current index.
        if (pre[i] != INT_MIN)
        {
            nex[pre[i]] = nex[i];
        }
        for (int cand : {nex[i], pre[i]})
        {
            if (cand == INT_MIN)
            {
                continue;
            }
            if (update(cand, nums))
            {
                minPeaks.push({-nums[cand], cand});
            }
        }
    }
    return ans;
}