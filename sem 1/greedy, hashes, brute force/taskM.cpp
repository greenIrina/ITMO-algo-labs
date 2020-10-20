#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
 
using namespace std;
 
 
class hash_map
{
private:
    vector<list<tuple<string, string, int>>> a;
    size_t _size, counter;
    vector<int> p;
    static const int PARAM = 31, MOD = (int) 1e9 + 7;
 
    size_t hash_pos(string& s)
    {
        size_t ans = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            ans += (1ll * (s[i] - 'a' + 1) * p[i]) % MOD;
        }
        return ans;
    }
 
    explicit hash_map(size_t new_size) : _size(new_size), counter()
    {
        p.resize(20);
        p[0] = 1;
        for (int i = 1; i < 20; ++i)
        {
            p[i] = (p[i - 1] * PARAM) % MOD;
        }
        a.resize(_size);
    }
 
    void resize_insert(const tuple<string, string, int>& tu)
    {
        a[get<2>(tu) % _size].push_back(tu);
        ++counter;
    }
 
    void resize()
    {
        if (3 * counter > 2 * _size)
        {
            hash_map hm(2 * _size);
            for (size_t i = 0; i < _size; ++i)
            {
                for (auto& j : a[i])
                {
                    hm.resize_insert(j);
                }
            }
            swap(*this, hm);
        }
    }
 
 
public:
    hash_map() : hash_map(100)
    {
    }
 
    bool find(string& key)
    {
        size_t pos = hash_pos(key) % _size;
        for (auto& i : a[pos])
        {
            if (get<0>(i) == key)
            {
                return true;
            }
        }
        return false;
    }
 
    void insert(string& key, string& val)
    {
        size_t pos = hash_pos(key) % _size;
        if (!find(key))
        {
            a[pos].push_back({key, val, hash_pos(key)});
            ++counter;
            resize();
        } else
        {
            for (auto& i : a[pos])
            {
                if (get<0>(i) == key)
                {
                    get<1>(i) = val;
                    return;
                }
            }
        }
    }
 
    void erase(string& key)
    {
        size_t pos = hash_pos(key) % _size;
        if (find(key))
        {
            a[pos].remove_if([key](tuple<string, string, size_t> tu) {
                return get<0>(tu) == key;
            });
            --counter;
        }
    }
 
    string get_elem(string& key)
    {
        size_t pos = hash_pos(key) % _size;
        for (auto& i : a[pos])
        {
            if (get<0>(i) == key)
            {
                return get<1>(i);
            }
        }
        return "none";
    }
};
 
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    hash_map hm;
    string s, inp, inp2;
    while (cin >> s)
    {
        cin >> inp;
        if (s[0] == 'p')
        {
            cin >> inp2;
            hm.insert(inp, inp2);
        } else if (s[0] == 'd')
        {
            hm.erase(inp);
        } else if (s[0] == 'g')
        {
            cout << hm.get_elem(inp) << '\n';
        }
    }
}