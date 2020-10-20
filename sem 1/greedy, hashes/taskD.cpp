#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
 
using namespace std;
 
vector<pair<int, int>> a, ans;
 
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
#endif
    int n, sum = 0;
    cin >> n;
    a.resize(static_cast<unsigned int>(n));
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
        sum += a[i].first;
    }
    if (sum % 2 == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    int sum_half = sum, ind_1 = 0, ind_2 = -1, sum_2 = 0;
    bool found = false;
    sort(a.begin(), a.end());
    for (int i = n - 1; i >= 0; --i)
    {
        sum_half -= a[i].first;
        if (sum_half == sum / 2)
        {
            ans.push_back(a[i]);
            found = true;
            break;
        }
        if (sum_half < sum / 2)
        {
            sum_half += a[i].first;
            continue;
        }
        ans.push_back(a[i]);
    }
    if (!found)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for (auto& an : ans)
    {
        cout << an.second << " ";
    }
 
 
    return 0;
}