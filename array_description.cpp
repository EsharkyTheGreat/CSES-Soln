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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));
    if (arr[0] != 0)
    {
        dp[0][arr[0]] = 1;
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i] == 0)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 1)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                if (j + 1 <= m)
                {
                    dp[i][j] += dp[i - 1][j + 1];
                }
                dp[i][j] %= mod;
            }
            else
            {
                if (arr[i] == j)
                {
                    dp[i][j] = dp[i - 1][j];
                    if (j - 1 >= 1)
                    {
                        dp[i][j] += dp[i - 1][j - 1];
                    }
                    if (j + 1 <= m)
                    {
                        dp[i][j] += dp[i - 1][j + 1];
                    }
                    dp[i][j] %= mod;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += dp[n - 1][i];
        ans %= mod;
    }
    cout << ans << endl;
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