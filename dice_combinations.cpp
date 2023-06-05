#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll mod = 1e9 + 7;

ll func(ll n, vector<ll> &dp)
{
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    ll res = 0;
    if (n >= 1)
        res += func(n - 1, dp) % mod;
    if (n >= 2)
        res += func(n - 2, dp) % mod;
    if (n >= 3)
        res += func(n - 3, dp) % mod;
    if (n >= 4)
        res += func(n - 4, dp) % mod;
    if (n >= 5)
        res += func(n - 5, dp) % mod;
    if (n >= 6)
        res += func(n - 6, dp) % mod;
    return dp[n] = res % mod;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, -1);
    cout << func(n, dp) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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