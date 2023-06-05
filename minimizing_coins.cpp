#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll mod = 1e9 + 7;

ll func(vector<ll> &arr, ll target, vector<ll> &dp)
{
    if (target < 0)
        return LLONG_MAX;
    if (target == 0)
        return 0;
    if (dp[target] != -1)
        return dp[target];
    ll res = LLONG_MAX;
    for (auto &x : arr)
    {
        if (x <= target)
        {
            ll ans = func(arr, target - x, dp);
            if (ans != LLONG_MAX)
                res = min(res, 1 + ans);
        }

        return dp[target] = res;
    }
}
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> dp(x + 1, -1);
    ll res = func(arr, x, dp);
    res = (res == LLONG_MAX) ? -1 : res;
    cout << res << endl;
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