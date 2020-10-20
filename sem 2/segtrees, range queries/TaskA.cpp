#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = numeric_limits<ll>::max();

ll prefix[20000000];
int c[20000000];


int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    ll x, y, z, t, a_0, b_0, ans = 0;

    cin >> n >> x >> y >> a_0;
    prefix[0] = a_0;
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + (x * a_0 + y) % (1 << 16);
        a_0 = (x * a_0 + y) % (1 << 16);
    }

    cin >> m >> z >> t >> b_0;
    for (int i = 0; i < 2 * m; ++i) {
        c[i] = static_cast<int>(b_0 % n);
        b_0 = (z * b_0 + t + (1 << 30)) % (1 << 30);
    }

    for (int i = 0; i < m; ++i) {
        if (c[2 * i] == c[2 * i + 1]) {
            if (c[2 * i] == 0) {
                ans += prefix[0];
            } else {
                ans += prefix[c[2 * i + 1]] - prefix[c[2 * i] - 1];
            }
        } else {
            if (c[2 * i] == 0 || c[2 * i + 1] == 0) {
                ans += (c[2 * i] > c[2 * i + 1] ? prefix[c[2 * i]] : prefix[c[2 * i + 1]]);
            } else {
                ans += (c[2 * i] > c[2 * i + 1] ? prefix[c[2 * i]] - prefix[c[2 * i + 1] - 1] : prefix[c[2 * i + 1]] -
                                                                                                prefix[c[2 * i] - 1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
