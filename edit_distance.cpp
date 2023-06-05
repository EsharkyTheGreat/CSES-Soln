#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <bits/stdc++.h>

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vll vector<ll>
#define vi vector<int>
using namespace std;

ll mod = 1e9 + 7;

int func(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == s1.size() && j == s2.size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == s1.size() && j != s2.size())
    {
        return dp[i][j] = s2.size() - j;
    }
    if (i != s1.size() && j == s2.size())
    {
        return dp[i][j] = s1.size() - i;
    }
    if (s1[i] == s2[j])
    {
        return dp[i][j] = func(s1, s2, i + 1, j + 1, dp);
    }
    return dp[i][j] = 1 + min(min(func(s1, s2, i + 1, j, dp), func(s1, s2, i + 1, j + 1, dp)), func(s1, s2, i, j + 1, dp));
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << func(s1, s2, 0, 0, dp) << endl;
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