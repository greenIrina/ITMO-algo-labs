#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
 
using namespace std;
 
//vector<int> apples_down, apples_up, number;
vector<tuple<int, int, int>> apples_up, apples_down;
 
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("apples.in", "r", stdin);
    freopen("apples.out", "w", stdout);
#endif
    int n, height;
    cin >> n >> height;
 
    for (int i = 0, a, b; i < n; ++i)
    {
 
        cin >> a >> b;
        if (b - a > 0)
        {
            apples_up.emplace_back(make_tuple(a, b, i + 1));
        } else
        {
            apples_down.emplace_back(make_tuple(a, b, i + 1));
        }
    }
 
//    sort(apples_up.begin(), apples_up.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
//        return (get<0>(a) < get<0>(b));
//    });
    sort(apples_up.begin(), apples_up.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
        if (get<0>(a) == get<0>(b)) {
            return  get<1>(a) > get<1>(b);
        } else {
            return get<0>(a) < get<0>(b);
        }
    });
 
//    sort(apples_down.begin(), apples_down.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
//        return (get<1>(a) > get<1>(b));
//    });
    sort(apples_down.begin(), apples_down.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
        if (get<1>(a) == get<1>(b)) {
            return get<0>(a) < get<0>(b);
        } else {
            return get<1>(a) > get<1>(b);
        }
    });
 
    int up = apples_up.size();
    int down = apples_down.size();
 
    //out
 
//    cout << "apples_up\n";
//    for (int i = 0; i < up; ++i)
//    {
//        cout << get<0>(apples_up[i]) << " " << get<1>(apples_up[i]) << " #" << get<2>(apples_up[i]) << endl;
//    }
//    cout << "apples_down\n";
//    for (int i = 0; i < down; ++i)
//    {
//        cout << get<1>(apples_down[i]) << " " << get<0>(apples_down[i])<< " #" << get<2>(apples_down[i])  << endl;
//    }
 
    int new_height = height;
    for (int i = 0; i < up; ++i)
    {
        new_height -= get<0>(apples_up[i]);
        if (new_height <= 0)
        {
            cout << -1 << endl;
            return 0;
        }
        new_height += get<1>(apples_up[i]);
    }
    for (int i = 0; i < down; ++i)
    {
        new_height -= get<0>(apples_down[i]);
        if (new_height <= 0)
        {
            cout << -1 << endl;
            return 0;
        }
        new_height += get<1>(apples_down[i]);
 
    }
    for (int i = 0; i < up; ++i)
    {
        cout << get<2>(apples_up[i]) << " ";
    }
    for (int i = 0; i < down; ++i)
    {
        cout << get<2>(apples_down[i]) << " ";
    }
    cout << endl;
 
    return 0;
}