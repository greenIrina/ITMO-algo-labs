#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class FenwickTree
{
public:
    vector<vector<vector<int>>> t;
    int n;

    int sum(int x, int y, int z)
    {
        int res = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                for (int k = z; k >= 0; k = (k & (k + 1)) - 1) {
                    res += t[i][j][k];
                }
            }
        }
        return res;
    }

    void modify(int x, int y, int z, int val)
    {
        for (int i = x; i < n; i |= i + 1) {
            for (int j = y; j < n; j |= j + 1) {
                for (int k = z; k < n; k |= k + 1) {
                    t[i][j][k] += val;
                }
            }
        }
    }


    int sum(int x1, int y1, int z1, int x2, int y2, int z2)
    {
        return sum(x2, y2, z2) - sum(x1 - 1, y2, z2) - sum(x2, y1 - 1, z2) - sum(x2, y2, z1 - 1) +
               sum(x1 - 1, y1 - 1, z2) + sum(x1 - 1, y2, z1 - 1) + sum(x2, y1 - 1, z1 - 1) -
               sum(x1 - 1, y1 - 1, z1 - 1);
    }

    explicit FenwickTree(int n) : n(n)
    {
        auto l = static_cast<size_t>(n + 1);
        t.resize(l, vector<vector<int> >(l, vector<int>(l)));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    FenwickTree ft(n);

    while (true) {
        int type, x, y, z;

        cin >> type;
        if (type == 3) {
            break;
        }

        cin >> x >> y >> z;
        if (type == 2) {
            int x1, y1, z1;
            cin >> x1 >> y1 >> z1;
            cout << ft.sum(x, y, z, x1, y1, z1) << endl;
        } else {
            int k;
            cin >> k;
            ft.modify(x, y, z, k);
        }
    }
    return 0;
}
