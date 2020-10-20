#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
 
using namespace std;
 
const int INF = 2147483647;
 
void print(int n, const vector<pair<int, int>>& pr)
{
    for (int i = 0; i < n; ++i)
    {
        cout << pr[i].second << " pages, " << pr[i].first << " for all and " <<
             pr[i].first / double(pr[i].second) << " per list" << endl;
    }
    cout << endl;
}
 
int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        } else
        {
            b -= a;
        }
    }
    return a;
}
 
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
 
bool compare(pair<int, int>& a, pair<int, int>& b, bool com_eq)
{
    int num1 = 0, num2 = 0;
    int _lcm = lcm(a.second, b.second);
    num1 = a.first * (_lcm / a.second);
    num2 = b.first * (_lcm / b.second);
    return com_eq ? (num1 < num2) : (num1 == num2);
}
 
void cnt_ans(vector<pair<int, int>>& price_list, int i, int remain, int cur_ans, int& ans)
{
 

    for (int j = 0; j < 7; ++j)
    {
        if (i == j)
        {
            continue;
        }
        if (price_list[j].second > remain)
        {
            ans = min(ans, cur_ans + price_list[j].first);
            continue;
        }
        int cnt_j = 0, cur_ans_j = cur_ans;
        while (cnt_j < remain)
        {
            cur_ans_j += price_list[j].first;
            cnt_j += price_list[j].second;
        }

        if (cnt_j < remain)
        {
            return;
        }
 
        if (cnt_j == remain)
        {
            ans = min(ans, cur_ans_j);
        } else
        {
            ans = min(ans, cur_ans_j);
            cur_ans_j -= price_list[j].first;
            cnt_j -= price_list[j].second;
            cnt_ans(price_list, j, remain - cnt_j, cur_ans_j, ans);
        }
 
 
    }
}
 
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("printing.in", "r", stdin);
    freopen("printing.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, amount = 1;
    cin >> n;
    vector<pair<int, int>> price_list(7);
    for (int i = 0; i < 7; ++i)
    {
        cin >> price_list[i].first;
        price_list[i].second = amount;
        amount *= 10;
    }
    int ans_takeAll = price_list[0].first * n;
    for (int i = 1; i < 7; ++i)
    {
        int cnt = 0, cur_ans = 0;
        while (cnt < n)
        {
            cur_ans += price_list[i].first;
            cnt += price_list[i].second;
        }
        ans_takeAll = min(ans_takeAll, cur_ans);
    }
 
    //sorting unite price of i < u.p. of i+1
    sort(price_list.begin(), price_list.end(), [](pair<int, int> a, pair<int, int> b) {
        if (compare(a, b, false))           //if unite price of a == u.p. of b
        {
            return a.second < b.second;
        } else
        {
            return compare(a, b, true);     //if unite price of a < u.p. of b
        }
    });
//    print(7, price_list);
 
    int ans = ans_takeAll;
    for (int i = 0; i < 7; ++i)
    {
        int remain = n;
        int cnt = 0, cur_ans = 0;
        while (cnt < n)
        {
            cur_ans += price_list[i].first;
            cnt += price_list[i].second;
        }
        if (cnt > n)
        {
            ans = min(ans, cur_ans);
            cur_ans -= price_list[i].first;
            cnt -= price_list[i].second;
            if (cnt != 0)
            {
                cnt_ans(price_list, i, remain - cnt, cur_ans, ans);
            }
 
        } else
        {
            ans = min(ans, cur_ans);
            continue;
        }
    }
    cout << ans;
 
 
    return 0;
}