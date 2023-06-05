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
#define sz(x) (int)x.size()

using namespace std;

class SegmentTree
{
    // int *sgtree;
    // vector<int> sgtree;
    int sgtree[500001];
    int size_tree;

public:
    SegmentTree(vector<int> &array)
    {
        int n = sz(array);
        size_tree = n;
        // sgtree = (int *)calloc(2 * n, 4);
        // sgtree.resize(2 * n);
        memset(sgtree, 0x0, 500001 * 4);
        buildTree(array, 1, 1, n);
    }
    int query(int left, int right)
    {
        return _query(1, 1, size_tree, left, right);
    }
    void update(int idx, int val)
    {
        int leaf = idx + size_tree - 1;
        sgtree[leaf] = val;
        return _update(leaf / 2);
    }

private:
    void dbg()
    {
        for (int i = 1; i < 2 * size_tree; i++)
        {
            cout << sgtree[i] << " ";
        }
        cout << endl;
    }
    void calculate(int node)
    {
        sgtree[node] = min(sgtree[2 * node], sgtree[2 * node + 1]);
    }
    void _update(int treeIdx)
    {
        calculate(treeIdx);
        if (treeIdx == 0)
            return;
        _update(treeIdx / 2);
    }
    void buildTree(vector<int> &array, int treeIndex, int left, int right)
    {
        if (left == right)
        {
            sgtree[treeIndex] = array[left - 1];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(array, 2 * treeIndex, left, mid);
        buildTree(array, 2 * treeIndex + 1, mid + 1, right);
        calculate(treeIndex);
    }
    int _query(int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if (queryLeft <= left && queryRight >= right)
        {
            return sgtree[treeIndex];
        }
        int ans = INT_MAX;
        int middle = (left + right) / 2;
        if (queryLeft <= middle)
        {
            ans = min(ans, _query(2 * treeIndex, left, middle, queryLeft, queryRight));
        }
        if (queryRight >= middle + 1)
        {
            ans = min(ans, _query(2 * treeIndex + 1, middle + 1, right, queryLeft, queryRight));
        }
        return ans;
    }
};

ll mod = 1e9 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;
    vi arr(n);
    rep(i, n)
    {
        cin >> arr[i];
    }
    SegmentTree *sgt = new SegmentTree(arr);
    while (q--)
    {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1)
        {
            sgt->update(a, b);
        }
        else
        {
            cout << sgt->query(a, b) << endl;
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

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}