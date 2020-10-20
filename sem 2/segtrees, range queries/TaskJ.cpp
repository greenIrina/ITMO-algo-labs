#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <limits>

using namespace std;

#define mp make_pair

typedef long long ll;

class SegmentTree
{
public:
    int n, x;
    ll inf = numeric_limits<ll>::max();
    vector<pair<ll, int>> t;
    vector<ll> d;

    void build()
    {
        x = 1;
        while (x < n) {
            x <<= 1;
        }
        for (int i = 0; i < n; i++) {
            t[x + i - 1] = {0, i};
        }
        int j = x - 2;
        while (j > -1) {
            t[j] = min(t[2 * j + 1], t[2 * j + 2]);
            j--;
        }
    }

    void push(int v)
    {
        if (d[v] == -1) {
            return;
        }
        apply(v, 1);
        apply(v, 2);

        d[v] = -1;
    }

    void apply(int v, int u)
    {
        if (t[2 * v + u].first < d[v]) {
            t[2 * v + u].first = d[v];
            d[2 * v + u] = d[v];
        }
    }

    void update(int v, int l, int r, int a, int b, ll val, string& s)
    {
        if ((l > b) || (r < a)) {
            return;
        }
        if ((l >= a) && (r <= b)) {
            if (t[v].first < val) {
                d[v] = val;
                t[v].first = val;
            }
            return;
        }
        push(v);
        int m = (l + r) / 2;
        update(2 * v + 1, l, m, a, b, val, s);
        update(2 * v + 2, m + 1, r, a, b, val, s);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }

    pair<ll, int> query(int v, int l, int r, int a, int b)
    {
        if ((l > b) || (r < a)) {
            return {inf, -1};
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
        t.resize(static_cast<unsigned int>(n * 4), mp(inf, -1));
        d.resize(static_cast<unsigned int>(n * 4), -1);
        build();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    SegmentTree sg(n);
    vector<ll> a;
    string s = "set";
    for (int i = 0; i < m; i++) {
        int l, r, x;
        string type;
        cin >> type;
        cin >> l >> r;
        if (type == "defend") {
            cin >> x;
            sg.update(0, 0, sg.x - 1, l - 1, r - 1, x, s);
            continue;
        }
        auto ans = sg.query(0, 0, sg.x - 1, l - 1, r - 1);
        cout << ans.first << ' ' << (ans.second + 1) << endl;
    }
    return 0;
}
