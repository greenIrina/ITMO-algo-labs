#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf = 2147483647;

int t[200000];

int query(int l, int r, int n)
{
    int res = inf;
    l += n;
    r += n;
    while (l < r) {
        if (l % 2 == 1) {
            res = min(res, t[l]);
            l++;
        }
        if (r % 2 == 1) {
            r--;
            res = min(res, t[r]);
        }
        l /= 2;
        r /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, cnt = 0;
    cin >> n >> m;
    cin >> t[n];
    for (int i = 1; i < n; ++i) {
        t[n + i] = (23 * t[n + i - 1] + 21563) % 16714589;
    }
    for (int i = n - 1; i > 0; --i) {
        t[i] = min(t[i * 2], t[i * 2 + 1]);
    }
    int u, v;
    cin >> u >> v;
    int ans = query(min(u, v) - 1, max(u, v), n);
    for (int i = 2; i < m + 1; ++i) {
        u = ((17 * u + 751 + ans + 2 * (i - 1)) % n) + 1;
        v = ((13 * v + 593 + ans + 5 * (i - 1)) % n) + 1;
        ans = query(min(u, v) - 1, max(u, v), n);
        cnt++;
    }
    cout << u << " " << v << " " << ans << endl;
    return 0;
}