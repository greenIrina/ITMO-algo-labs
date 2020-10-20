#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void print(int n, const vector<pair<int, int>>& pr)
{
    for (int i = 0; i < n; ++i)
    {
        cout << pr[i].first << " " << pr[i].second << endl;
    }
    cout << endl;
}
 
 
long long merge(vector<pair<int, int>>& arr, vector<pair<int, int>>& tmp,
          int left, int mid, int right)
{
    long long res = 0;
    int i = left;
    int j = mid;
    int k = left;
    while (i < mid && j <= right)
    {
        if (arr[i].second <= arr[j].second)
        {
            tmp[k++] = arr[i++];
        } else
        {
            tmp[k++] = arr[j++];
            res += mid - i;
        }
    }
    while (j <= right)
    {
        tmp[k++] = arr[j++];
    }
    while (i < mid)
    {
        tmp[k++] = arr[i++];
    }
 
 
    for (i = left; i <= right; i++)
    {
        arr[i] = tmp[i];
    }
    return res;
}
 
long long calc(vector<pair<int, int>>& arr, vector<pair<int, int>>& temp,
         int left, int right)
{
    long long res = 0;
    if (right > left)
    {
        int mid = (right + left) / 2;
        res = calc(arr, temp, left, mid);
        res += calc(arr, temp, mid + 1, right);
        res += merge(arr, temp, left, mid + 1, right);
    }
    return res;
}
 
 
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("john.in", "r", stdin);
    freopen("john.out", "w", stdout);
#endif
    size_t n;
    cin >> n;
    vector<pair<int, int>> a, tmp;
    a.resize(n), tmp.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<int, int>& f, pair<int, int>& s) {
        if (f.first == s.first)
        {
            return f.second < s.second;
        }
        return f.first < s.first;
    });
//    print(n, a);
    long long ans = calc(a, tmp, 0, n - 1);
    cout << ans << endl;
 
 
}