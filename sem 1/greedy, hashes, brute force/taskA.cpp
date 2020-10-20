#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("cobbler.in", "r", stdin);
    freopen("cobbler.out", "w", stdout);
#endif
    size_t n, k;
    cin >> k >> n;
    vector<size_t> time;
    time.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> time[i];
    }
    sort(time.begin(), time.end());
    size_t cnt = 0, ans = 0;
    while (cnt < n && ans < k)
    {
        ans += time[cnt];
        if (ans <= k)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
 
 
}