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

void solve()
{
    int t;
    cin >> t;
    vector<int> cases(t);
    int max_n = 0;
    for (auto &i : cases)
    {
        cin >> i;
        max_n = max(max_n, i);
    }
    vector<vector<ll>> dp(max_n + 1, vector<ll>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= max_n; i++)
    {
        dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = (4 * dp[i - 1][1] + dp[i - 1][0]) % mod;
    }
    for (auto &i : cases)
    {
        cout << (dp[i][0] + dp[i][1]) % mod << endl;
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