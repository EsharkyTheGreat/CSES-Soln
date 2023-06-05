#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <bits/stdc++.h>

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vll vector<ll>
#define vi vector<int>
using namespace std;

ll mod = 1e9 + 7;

char mat[1001][1001];
bool vis[1001][1001] = {false};

void dfs(int i, int j)
{
    if (mat[i][j] != '.')
        return;
    mat[i][j] = '#';
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> mat[i][j];
        }
    }
    int res = 0;
    rep(i, n)
    {
        rep(j, m)
        {
            if (mat[i][j] == '.')
            {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << endl;
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