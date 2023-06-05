#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <bits/stdc++.h>

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vll vector<ll>
using namespace std;

ll mod = 1e9 + 7;

ll func(vll &price, vll &pages, ll idx, ll x, vector<vector<ll>> &dp)
{
    if (idx < 0)
        return 0;
    if (dp[idx][x] != -1)
        return dp[idx][x];
    if (price[idx] <= x)
    {
        return dp[idx][x] = max(pages[idx] + func(price, pages, idx - 1, x - price[idx], dp), func(price, pages, idx - 1, x, dp));
    }
    else
    {
        return dp[idx][x] = func(price, pages, idx - 1, x, dp);
    }
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> price(n);
    vector<int> pages(n);
    rep(i, n)
    {
        cin >> price[i];
    }
    rep(i, n)
    {
        cin >> pages[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    // cout << func(price, pages, n - 1, x, dp) << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j >= price[i - 1])
            {
                dp[i][j] = max(pages[i - 1] + dp[i - 1][j - price[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][x] << endl;
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