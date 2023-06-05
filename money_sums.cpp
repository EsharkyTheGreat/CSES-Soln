#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <unordered_set>
#include <bits/stdc++.h>

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vll vector<ll>
#define vi vector<int>
using namespace std;

ll mod = 1e9 + 7;

void func(vector<int> &arr, int n, vector<int> &res, int curr_sum)
{
    if (n < 0)
    {
        if (curr_sum != 0)
        {
            res.push_back(curr_sum);
        }
        return;
    }
    func(arr, n - 1, res, curr_sum + arr[n]);
    func(arr, n - 1, res, curr_sum);
}

void solve()
{
    int n;
    cin >> n;
    vi org(n);
    int sum = 0;
    for (auto &i : org)
    {
        cin >> i;
        sum += i;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (dp[i - 1][j])
            {
                dp[i][j] = true;
                dp[i][j + org[i - 1]] = true;
            }
            else if (org[i - 1] == j)
            {
                dp[i][j] = true;
            }
        }
    }
    int count = 0;
    vi res;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[j][i])
            {
                res.push_back(i);
                count++;
                break;
            }
        }
    }
    cout << count << endl;
    for (auto &x : res)
    {
        cout << x << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}