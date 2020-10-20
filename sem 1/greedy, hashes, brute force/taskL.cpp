#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
 
using namespace std;
 
class hash_set
{
private:
    vector<list<int>> a;
    size_t _size, min_size, counter;
 
    void resize()
    {
        if (3 * counter > 2 * _size)
        {
            hash_set hs(2 * _size);
            for (size_t i = 0; i < _size; ++i)
            {
                for (int& j : a[i])
                {
                    hs.resize_insert(j);
                }
            }
            swap(*this, hs);
        }
    }
 
    explicit hash_set(size_t new_size) : min_size(100), _size(new_size), counter()
    {
        a.resize(new_size);
    }
 
    void resize_insert(int inp)
    {
        a[cnt_pos(inp)].push_back(inp);
        counter++;
    }
 
    size_t cnt_pos(int inp)
    {
        return inp < 0 ? ((-inp) % _size) : (inp % _size);
    }
 
public:
    hash_set() : min_size(100), _size(), counter(), a()
    {
        _size = min_size;
        a.resize(min_size);
    }
 
    bool find(int inp)
    {
        size_t pos = cnt_pos(inp);
        for (int& i : a[pos])
        {
            if (i == inp)
            {
                return true;
            }
        }
        return false;
    }
 
    void insert(int inp)
    {
        if (!find(inp))
        {
            a[cnt_pos(inp)].push_back(inp);
            counter++;
            resize();
        }
    }
 
    void erase(int inp)
    {
        if (find(inp))
        {
            a[cnt_pos(inp)].remove(inp);
        }
    }
};
 
 
void print(int n, vector<int> pr)
{
    for (int i = 0; i < n; ++i)
    {
        cout << pr[i] << " ";
    }
    cout << endl;
}
 
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    hash_set hs;
    string s;
    int inp;
    while (cin >> s)
    {
        cin >> inp;
        if (s[0] == 'i') {
            hs.insert(inp);
        } else if (s[0] == 'd') {
            hs.erase(inp);
        } else if (s[0] == 'e') {
            cout << (hs.find(inp) ? "true" : "false") << '\n';
        }
    }
 
 
    return 0;
}