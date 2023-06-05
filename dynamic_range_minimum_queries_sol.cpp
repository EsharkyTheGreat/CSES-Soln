#include <algorithm>

#include <iostream>

#include <vector>

using std::cout;

using std::endl;

using std::vector;

/** A data structure that can answer point update & range minimum queries. */

template <class T>
class MinSegmentTree
{

private:
    const T DEFAULT = 1e18; // Will overflow if T is an int

    vector<T> segtree;

    int len;

public:
    MinSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

    /** Sets the value at ind to val. */

    void set(int ind, T val)
    {

        ind += len;

        segtree[ind] = val;

        for (; ind > 1; ind /= 2)
        {

            segtree[ind / 2] = std::min(segtree[ind], segtree[ind ^ 1]);
        }
    }

    /** @return the minimum element in the range [start, end) */

    T range_min(int start, int end)
    {

        T sum = DEFAULT;

        for (start += len, end += len; start < end; start /= 2, end /= 2)
        {

            if (start % 2 == 1)
            {
                sum = std::min(sum, segtree[start++]);
            }

            if (end % 2 == 1)
            {
                sum = std::min(sum, segtree[--end]);
            }
        }

        return sum;
    }
};

int main()
{

    int arr_len;

    int query_num;

    std::cin >> arr_len >> query_num;

    MinSegmentTree<long long> segtree(arr_len);

    for (int i = 0; i < arr_len; i++)
    {

        int n;

        std::cin >> n;

        segtree.set(i, n);
    }

    for (int q = 0; q < query_num; q++)
    {

        int type, arg1, arg2;

        std::cin >> type >> arg1 >> arg2;

        if (type == 1)
        {

            segtree.set(arg1 - 1, arg2);
        }
        else if (type == 2)
        {

            cout << segtree.range_min(arg1 - 1, arg2) << '\n';
        }
    }
}