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
    vll first(n + 1, 0);
    vll second(n + 1, 0);
    vll third(n + 1, 0);
    ll sum1 = 0;
    ll sum2 = 0;
    ll sum3 = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i - 1];
        if (arr[i - 1] == 1)
        {
            sum1 += 1;
        }
        if (arr[i - 1] == 2)
        {
            sum2 += 1;
        }
        if (arr[i - 1] == 3)
        {
            sum3 += 1;
        }
        first[i] = sum1;
        second[i] = sum2;
        third[i] = sum3;
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << first[b] - first[a - 1] << " " << second[b] - second[a - 1] << " " << third[b] - third[a - 1] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("bcount.in", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("bcount.out", "w", stdout);
#endif

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}