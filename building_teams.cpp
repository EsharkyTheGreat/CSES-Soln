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
#define vvi vector<vi>
#define pb push_back

using namespace std;

ll mod = 1e9 + 7;

bool global_success = false;

void dfs(vvi &adj, int i, vi &col, vector<bool> &visited, int parent)
{
    if (visited[i])
    {
        return;
    }
    visited[i] = true;
    int right_col = (parent == 1) ? 2 : 1;
    if (col[i])
        for (auto &x : adj[i])
        {
            dfs(adj, x, col, visited, col[i]);
        }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1);
    vi col(n + 1, 0);
    int start = 0;
    rep(i, m)
    {
        int v, u;
        cin >> v >> u;
        start = v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    // queue<pair<int, int>> q;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(adj, i, col, visited, 1);
        }
    }
    // q.push({start, 1});
    // col[start] = 1;
    // while (!q.empty())
    // {
    //     int node = q.front().first;
    //     int wt = q.front().second;
    //     for (auto &x : adj[node])
    //     {
    //         if (visited[x])
    //         {
    //             continue;
    //         }
    //         visited[x] = true;
    //         if (col[x] == wt)
    //         {
    //             cout << "IMPOSSIBLE" << endl;
    //             return;
    //         }
    //         col[x] = (wt == 1) ? 2 : 1;
    //         q.push({x, col[x]});
    //     }
    // }
    for (int i = 1; i <= n; i++)
    {
        cout << col[i] << " ";
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