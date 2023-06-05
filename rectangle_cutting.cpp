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
int solve2(int a, int b)
{
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else if (i > j)
            {
                dp[i][j] = 1 + dp[i - j][j];
            }
            else
            {
                dp[i][j] = 1 + dp[i][j - i];
            }
        }
    }
    return dp[a][b];
}

int solve1(int a, int b)
{
    // int a, b;
    // cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = INT_MAX;
                for (int h = 1; h < i; h++)
                {
                    dp[i][j] = min(dp[i][j], dp[h][j] + dp[i - h][j] + 1);
                }
                for (int h = 1; h < j; h++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][h] + dp[i][j - h] + 1);
                }
            }
            // printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }
    // cout << dp[a][b] << endl;
    return dp[a][b];
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
    int a = 1;
    int b = 1;
    cout << solve1(404, 288) << endl;
    cout << solve2(404, 288) << endl;
    for (int a = 1; a <= 100; a++)
    {
        for (int b = 1; b <= 100; b++)
        {
            int res1 = solve1(a, b);
            int res2 = solve2(a, b);
            if (res1 != res2)
            {
                cout << " Res1 : " << res1 << " RES2: " << res2 << " a: " << a << " b: " << b << endl;
            }
        }
    }
}