#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    deque<int> q;
    vector<int> pos(static_cast<unsigned int>(1e5 + 2));
    set<pair<int, int>> all;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            if (q.empty()) {
                pos[x] = 0;
            } else {
                pos[x] = -((*all.begin()).first) + 1;
            }
            q.emplace_back(x);
            all.insert({-pos[x], x});
        }
        if (t == 2) {
            all.erase({-pos[q.front()], q.front()});
            q.pop_front();
        }
        if (t == 3) {
            all.erase({-pos[q.back()], q.back()});
            q.pop_back();
        }
        if (t == 4) {
            int x;
            cin >> x;
            cout << pos[x] - pos[q.front()] << endl;
        }
        if (t == 5) {
            cout << q.front() << endl;
        }
    }
    return 0;
}
