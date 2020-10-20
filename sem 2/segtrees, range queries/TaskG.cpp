#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

typedef long long ll;


class SegmentTree
{
public:
    int n, x;
    int inf = numeric_limits<int>::max();
    vector<pair<int, int>> t;
    vector<int> d;

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
            t[j] = max(t[2 * j + 1], t[2 * j + 2]);
            j--;
        }
    }

    void push(int v)
    {
        apply(v, 1);
        apply(v, 2);
        d[v] = 0;
    }

    void apply(int v, int u)
    {
        t[2 * v + u].first += d[v];
        d[2 * v + u] += d[v];
    }

    void update(int v, int l, int r, int a, int b, int val)
    {
        if ((l > b) || (r < a)) {
            return;
        }
        if ((l >= a) && (r <= b)) {
            d[v] += val;
            t[v].first += val;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        update(2 * v + 1, l, m, a, b, val);
        update(2 * v + 2, m + 1, r, a, b, val);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }

    pair<int, int> query(int v, int l, int r, int a, int b)
    {
        if ((l > b) || (r < a)) {
            return {0, 0};
        }
        if ((l >= a) && (r <= b)) {
            return t[v];
        }
        push(v);
        int m = (l + r) / 2;
        auto x = max(query(2 * v + 1, l, m, a, b), query(2 * v + 2, m + 1, r, a, b));
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
        return x;
    }

    explicit SegmentTree(int n) : n(n), t(), d(), x()
    {
        t.resize(static_cast<unsigned int>(4 * n), mp(0, 0));
        d.resize(static_cast<unsigned int>(4 * n), 0);
        build();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, x1, y1, x2, y2, shift = 200000;
    cin >> m;
    tuple<int, int, int> answer = make_tuple(0, 0, 0);  //answer: count, x, y
    vector<tuple<int, int, int, int>> v;                //coordinates
    vector<tuple<int, int, int>> a;                     //type of x coordinate
    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        v.emplace_back(make_tuple(x1 + shift, y1 + shift, x2 + shift, y2 + shift));
        a.emplace_back(make_tuple(x1 + shift, 0, i));   //opening x, upper left
        a.emplace_back(make_tuple(x2 + shift, 1, i));   //closing x, lower right
    }
    n = 400000;
    SegmentTree st(n);
    stable_sort(a.begin(), a.end());
    for (int i = 0; i < 2 * m; ++i) {
        int x = get<0>(a[i]);
        int Y1 = get<1>(v[get<2>(a[i])]);
        int Y2 = get<3>(v[get<2>(a[i])]);
        if (get<1>(a[i]) == 0) {
            st.update(0, 0, st.x - 1, Y1, Y2, 1);
            pair<int, int> q = st.query(0, 0, st.x - 1, Y1, Y2);
            if (get<0>(answer) < q.first) {
                answer = make_tuple(q.first, x, q.second);
            }
        }
        if (i != 2 * m - 1 && get<1>(a[i]) == 1) {
            st.update(0, 0, st.x - 1, Y1, Y2, -1);
        }
    }
    cout << get<0>(answer) << '\n' << get<1>(answer) - shift << " " << get<2>(answer) - shift << '\n';
    return 0;
}
