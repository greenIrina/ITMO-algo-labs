#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
 
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("request.in", "r", stdin);
    freopen("request.out", "w", stdout);
#endif
    size_t n;
    cin >> n;
    vector<pair<size_t, size_t>> a;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<size_t, size_t>& f, pair<size_t, size_t>& s) {
        return f.second < s.second;
    });
 
    int cnt = 1;
 
    pair<size_t, size_t> c = a[0];
    for (auto it = ++a.cbegin(); it != a.cend(); ++it)
    {
        if (c.second <= it->first)
        {
            c = *it;
            ++cnt;
        }
    }
    cout << cnt << endl;
}