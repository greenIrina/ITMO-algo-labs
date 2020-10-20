#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//0 indexation
class SegmentTree
{
public:
    int n, x;
    vector<ll> t;

    void build(vector<ll>& v)
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
            t[j] = t[2 * j + 1] + t[2 * j + 2];
            j--;
        }
    }

    void modify(ll i, ll data)
    {
        t[i - 1 + x] = data;
        ll v = i - 1 + x;
        while (v > 0) {
            v = (v - 1) / 2;
            t[v] = t[2 * v + 1] + t[2 * v + 2];
        }
    }

    ll query(int v, int l, int r, int a, int b)
    {
        if ((a > r) || (b < l)) {
            return 0;
        }
        if ((a <= l) && (b >= r)) {
            return t[v];
        }
        int m = (l + r) / 2;
        return query(2 * v + 1, l, m, a, b) + query(2 * v + 2, m + 1, r, a, b);
    }

    explicit SegmentTree(int n) : n(n), t(), x()
    {
        t.resize(static_cast<unsigned int>(n * 4), 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    ll m;
    vector<ll> nums;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        nums.push_back(m);
    }
    SegmentTree tree(n);
    tree.build(nums);
    int cnt = 0;
    while (cin >> s) {
        int a;
        ll b;
        cin >> a >> b;
        if (s == "sum") {
            cout << tree.query(0, 0, tree.x - 1, a - 1, static_cast<int>(b - 1)) << endl;
        } else {
            tree.modify(a - 1, b);
        }
        cnt++;
    }
    return 0;
}
