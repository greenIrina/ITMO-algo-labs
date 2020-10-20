#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//0 indexation
class SegmentTree
{
public:
    int n, x;
    vector<int> t;

    void build(vector<int>& v)
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
            t[j] = min(t[2 * j + 1], t[2 * j + 2]);
            j--;
        }
    }

    void modify(int i, int data)
    {
        t[i - 1 + x] = data;
        int v = i - 1 + x;
        while (v > 0) {
            v = (v - 1) / 2;
            t[v] = min(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    int rmq(int v, int l, int r, int a, int b)
    {
        if ((a > r) || (b < l)) {
            return numeric_limits<int>::max();
        }
        if ((a <= l) && (b >= r)) {
            return t[v];
        }
        int m = (l + r) / 2;
        return min(rmq(2 * v + 1, l, m, a, b), rmq(2 * v + 2, m + 1, r, a, b));
    }

    explicit SegmentTree(int n) : n(n), t(), x()
    {
        t.resize(static_cast<unsigned int>(n * 4), numeric_limits<int>::max());
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream fin("parking.in");
    ofstream fout("parking.out");
    int n, m;
    int inf = numeric_limits<int>::max();
    vector<int> nums;
    fin >> n >> m;
    nums.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        nums.push_back(i);
    }
    string s;
    SegmentTree tree(n);
    tree.build(nums);
    for (auto i = 0; i < m; ++i) {
        fin >> s;
        int a, b;
        fin >> a;
        if (s == "enter") {
            b = tree.rmq(0, 0, tree.x - 1, a - 1, n - 1);
            if (b > n - 1) {
                b = tree.rmq(0, 0, tree.x - 1, 0, n - 1);
                tree.modify(b, inf);
                fout << b + 1 << endl;
            } else {
                tree.modify(b, inf);
                fout << b + 1 << endl;
            }
        } else {
            tree.modify(a - 1, a - 1);
        }
    }
    fin.close();
    fout.close();
    return 0;
}
