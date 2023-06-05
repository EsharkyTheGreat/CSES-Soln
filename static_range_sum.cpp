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

void solve()
{
    ll n, q;
    cin >> n >> q;
    vll arr(n);
    ll sum = 0;
    vll pre(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        pre[i + 1] = sum;
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("error.txt", "w", stderr);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}