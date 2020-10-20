#include <iostream>
#include <vector>
 
using namespace std;
 
vector<vector<bool>> ans;
 
void _generate(int k, vector<bool>& str, int n)
{
    if (n == k)
    {
        ans.emplace_back(str);
        return;
    }
 
    if (str[n - 1])
    {
        str[n] = false;
        _generate(k, str, n + 1);
    } else
    {
        str[n] = false;
        _generate(k, str, n + 1);
 
        str[n] = true;
        _generate(k, str, n + 1);
    }
}
 
void generate(size_t k)
{
    if (k <= 0)
    {
        return;
    }
 
    vector<bool> str;
    str.resize(k);
 
    str[0] = false;
    _generate(k, str, 1);
 
    str[0] = true;
    _generate(k, str, 1);
}
 
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("vectors2.in", "r", stdin);
    freopen("vectors2.out", "w", stdout);
#endif
    size_t n;
    cin >> n;
    generate(n);
    cout << ans.size() << endl;
    for (auto& an : ans)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << (int) an[j];
        }
        cout << endl;
    }
}