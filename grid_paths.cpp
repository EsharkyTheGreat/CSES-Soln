#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll mod = 1e9 + 7;

ll search(vector<vector<char>> &mat, ll i, ll j, ll n)
{
    if (i == n - 1 && j == n - 1)
        return 1;
    if (i >= n || j >= n)
        return 0;
    if (mat[i][j] == '*')
        return 0;
    return search(mat, i + 1, j, n) + search(mat, i, j + 1, n);
}

void solve()
{
    ll n;
    cin >> n;
    vector<vector<char>> mat(n, vector<char>(n, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    // cout << search(mat, 0, 0, n) << endl;
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    bool noStar = true;
    bool noStar2 = true;
    for (ll i = 0; i < n; i++)
    {
        if (mat[0][i] != '*' && noStar)
            dp[0][i] = 1;
        if (mat[i][0] != '*' && noStar2)
            dp[i][0] = 1;
        if (mat[0][i] == '*')
            noStar = false;
        if (mat[i][0] == '*')
            noStar2 = false;
    }
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 1; j < n; j++)
        {
            if (mat[i][j] != '*')
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
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