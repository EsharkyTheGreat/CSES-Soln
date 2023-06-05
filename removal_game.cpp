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

ll func(vll &arr, ll l, ll r, bool a, ll sum, vector<vector<ll>> &dp)
{
    // printf("Calling : l : %d, r: %d, a: %d, sum: %d\n", l, r, a, sum);
    if (dp[l][r] != -1 && a)
        return dp[l][r];
    if (r == l + 1 && a)
    {
        return dp[l][r] = max(arr[l], arr[r]);
    }
    if (a)
    {
        return dp[l][r] = max(
                   arr[l] + func(arr, l + 1, r, false, sum - arr[l], dp),
                   arr[r] + func(arr, l, r - 1, false, sum - arr[r], dp));
    }
    else
    {
        dp[l][r] = func(arr, l, r, true, sum, dp);
        return sum - dp[l][r];
    }
}

void solve()
{
    int n;
    cin >> n;
    vll arr(n);
    ll sum = 0;
    for (auto &i : arr)
    {
        cin >> i;
        sum += i;
    }
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    cout << func(arr, 0, n - 1, true, sum, dp);
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