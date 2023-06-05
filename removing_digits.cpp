#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll mod = 1e9 + 7;

ll get_max_digit(ll n)
{
    ll max_digit = 0;
    while (n)
    {
        max_digit = max(max_digit, n % 10);
        n /= 10;
    }
    return max_digit;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n + 1, 0);
    arr[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        arr[i] = 1 + arr[i - get_max_digit(i)];
    }
    cout << arr[n] << endl;
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