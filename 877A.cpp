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
    vll arr(n);
    bool isz = false;
    bool isneg = false;
    ll negval;
    rep(i, n)
    {
        cin >> arr[i];
        if (arr[i] < 0)
        {
            // cout << arr[i] << endl;
            // return;
            isneg = true;
            negval = arr[i];
        }
        if (arr[i] == 0)
        {
            isz = true;
        }
    }
    if (isneg)
    {
        cout << negval << endl;
        return;
    }

    if (isz)
    {
        cout << *max_element(arr.begin(), arr.end()) << endl;
        return;
    }
    unordered_set<ll> pos;
    for (ll i = 0; i < n - 1; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            pos.insert(abs(arr[i] - arr[j]));
            pos.insert(abs(arr[j] - arr[i]));
        }
    }
    rep(i, n)
    {
        if (pos.find(arr[i]) == pos.end())
        {
            cout << arr[i] << endl;
            return;
        }
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

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}