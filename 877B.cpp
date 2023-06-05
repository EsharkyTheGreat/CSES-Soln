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

void solve()
{
    ll n;
    cin >> n;
    vll arr(n + 1, 0);
    ll sum = 0;
    ll natsum = 0;
    vll res;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        natsum += i;
        if (natsum == sum && i != 1)
        {
            res.push_back(i);
            // cout << "Adding i: " << i << endl;
        }
    }
    if (res.size() == 1)
    {
        cout << 1 << " " << 1 << endl;
        return;
    }
    cout << res[0] << " " << res[res.size() - 1] << endl;
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

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}