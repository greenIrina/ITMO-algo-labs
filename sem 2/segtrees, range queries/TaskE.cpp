#include <bits/stdc++.h>

using namespace std;


class SegmentTree
{
public:
    int n, x;
    vector<tuple<int, int, int, int>> t;

    tuple<int, int, int, int> multiply(tuple<int, int, int, int> a, tuple<int, int, int, int> b, int r)
    {
        return make_tuple((get<0>(a) * get<0>(b) + get<1>(a) * get<2>(b)) % r,
                          (get<0>(a) * get<1>(b) + get<1>(a) * get<3>(b)) % r,
                          (get<2>(a) * get<0>(b) + get<3>(a) * get<2>(b)) % r,
                          (get<2>(a) * get<1>(b) + get<3>(a) * get<3>(b)) % r);
    }

    void build(vector<tuple<int, int, int, int>>& v, int r)
    {
        x = 1;
        int si = static_cast<int>(v.size());
        while (x < si) {
            x <<= 1;
        }
        for (int i = 0; i < si; i++) {
            t[x + i - 1] = v[i];
        }
        int j = x - 2;
        while (j > -1) {
            t[j] = multiply(t[2 * j + 1], t[2 * j + 2], r);
            j--;
        }
    }

    tuple<int, int, int, int> query(int v, int l, int r, int a, int b, int re)
    {
        if ((a > r) || (b < l)) {
            return make_tuple(1, 0, 0, 1);
        }
        if ((a <= l) && (b >= r)) {
            return t[v];
        }
        int m = (l + r) / 2;
        return multiply(query(2 * v + 1, l, m, a, b, re), query(2 * v + 2, m + 1, r, a, b, re), re);
    }

    explicit SegmentTree(int n) : n(n), t(), x()
    {
        t.resize(static_cast<unsigned int>(n * 4), make_tuple(1, 0, 0, 1));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream fin("crypto.in");
    ofstream fout("crypto.out");
    int r, n, m, a1, a2, a3, a4, left, right, ind;
    vector<tuple<int, int, int, int>> nums;
    fin >> r >> n >> m;
    for (int i = 0; i < n; ++i) {
        fin >> a1 >> a2 >> a3 >> a4;
        nums.emplace_back(make_tuple(a1, a2, a3, a4));
    }

    SegmentTree tree(n);
    tree.build(nums, r);

    for (int j = 0; j < m; ++j) {
        fin >> left >> right;
        if (left == right) {
            ind = left - 1;
            fout << get<0>(nums[ind]) << " " << get<1>(nums[ind]) << '\n' << get<2>(nums[ind]) << " "
                 << get<3>(nums[ind]) << '\n' << '\n';
        } else {
            tuple<int, int, int, int> a = tree.query(0, 0, tree.x - 1, left - 1, right - 1, r);
            fout << get<0>(a) << " " << get<1>(a) << '\n' << get<2>(a) << " " << get<3>(a) << '\n' << '\n';
        }
    }
    fin.close();
    fout.close();
    return 0;
}
