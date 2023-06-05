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

ll func(int n, ll target, vector<vector<ll>> &dp)
{
    if (target < 0 || n < 0)
        return 0;
    if (target == 0)
        return 1;
    if (dp[n][target] != -1)
        return dp[n][target];
    return dp[n][target] = (func(n - 1, target - n, dp) % mod + func(n - 1, target, dp) % mod) % mod;
}

void solve()
{
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0)
    {
        cout << 0 << endl;
        return;
    }
    sum /= 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    // cout << func(n, sum, dp) / 2 << endl;
    dp[0][0] = 1;
    for (int s = 0; s <= sum; s++)
    {
        for (int i = 1; i < n; i++)
        {
            dp[i][s] = dp[i - 1][s];
            if (s - i >= 0)
            {
                dp[i][s] += dp[i - 1][s - i];
                dp[i][s] %= mod;
            }
        }
    }
    cout << dp[n - 1][sum] << endl;
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