#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class SegmentTree
{
public:
    int n, x;
    ll inf = numeric_limits<ll>::max();
    vector<ll> t;
    vector<pair<int, ll>> d;

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
            t[j] = min(t[2 * j + 1], t[2 * j + 2]);
            j--;
        }
    }

    void push(int v)
    {
        if (d[v].first == 0) {
            return;
        }
        apply(v, 1);
        apply(v, 2);

        d[v] = make_pair(0, 0);
    }

    void apply(int v, int u)
    {
        if (d[2 * v + u].first == 2 && d[v].first == 1) {
            d[2 * v + u].second += d[v].second;
        } else if (d[2 * v + u].first == 1 && d[v].first == 2) {
            d[2 * v + u].first = 2;
            d[2 * v + u].second = d[v].second;
        } else {
            d[2 * v + u].first = d[v].first;
            d[2 * v + u].second = d[v].second + ((d[v].first == 1) ? d[2 * v + u].second : 0);
        }
        t[2 * v + u] = d[v].second + ((d[v].first == 1) ? t[2 * v + u] : 0);
    }

    void update(int v, int l, int r, int a, int b, ll val, string& s)
    {
        if ((l > b) || (r < a)) {
            return;
        }
        if ((l >= a) && (r <= b)) {
            if (d[v].first == 2 && s == "add") {
                d[v].second += val;
            } else if (d[v].first == 1 && s == "set") {
                d[v].first = 2;
                d[v].second = val;
            } else {
                d[v].first = (s == "add") ? 1 : 2;
                d[v].second = val + ((d[v].first == 1) ? d[v].second : 0);
            }
            t[v] = val + ((s == "add") ? t[v] : 0);
            return;
        }
        push(v);
        int m = (l + r) / 2;
        update(2 * v + 1, l, m, a, b, val, s);
        update(2 * v + 2, m + 1, r, a, b, val, s);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }

    ll query(int v, int l, int r, int a, int b)
    {
        if ((l > b) || (r < a)) {
            return inf;
        }
        if ((l >= a) && (r <= b)) {
            return t[v];
        }
        push(v);
        int m = (l + r) / 2;
        auto x = min(query(2 * v + 1, l, m, a, b), query(2 * v + 2, m + 1, r, a, b));
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
        return x;
    }

    explicit SegmentTree(int n) : n(n), t(), d(), x()
    {
        t.resize(static_cast<unsigned int>(n * 4), inf);
        d.resize(static_cast<unsigned int>(n * 4), make_pair(0, 0));
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

    while (cin >> s) {
        ll val;
        int left, right;
        cin >> left >> right;
        if (s == "min") {
            cout << tree.query(0, 0, tree.x - 1, left - 1, right - 1) << endl;
        } else {
            cin >> val;
            tree.update(0, 0, tree.x - 1, left - 1, right - 1, val, s);
        }
    }
    return 0;
}
