#include <bits/stdc++.h>

using namespace std;

struct SegmentSet
{

    typedef typename set<pair<int, int>>::iterator Itr;

    set<pair<int, int>> s;
    int cnt = 0;

    void erase(Itr it)
    {
        cnt -= it->second - it->first + 1;
        s.erase(it);
    }

    void insert(int l, int r)
    {
        s.insert(make_pair(l, r));
        cnt += r - l + 1;
    }

    void add(int l, int r)
    {
        if (s.empty()) {
            insert(l, r);
            return;
        }
        Itr q, f = q = s.lower_bound(make_pair(l, l - 1));
        if (f != s.begin() && (--f)->second >= l - 1) {
            if (f->second >= r) {
                return;
            }
            l = f->first;
            erase(f);
        }
        while (q != s.end() && q->first <= r + 1)
            if (q->second > r) {
                r = q->second;
                erase(q);
                break;
            } else {
                erase(q++);
            }
        insert(l, r);
    }

    void del(int l, int r)
    {
        if (s.empty()) {
            return;
        }
        Itr q, f = q = s.lower_bound(make_pair(l, l - 1));
        if (f != s.begin() && (--f)->second >= l) {
            insert(f->first, l - 1);
            if (f->second > r) {
                insert(r + 1, f->second);
                erase(f);
                return;
            }
            erase(f);
        }
        while (q != s.end() && q->first <= r) {
            if (r <= q->second) {
                if (r + 1 <= q->second) {
                    insert(r + 1, q->second);
                }
                erase(q);
                break;
            } else {
                erase(q++);
            }
        }
    }

    int length()
    {
        return cnt;
    }

    int size()
    {
        return s.size();
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    SegmentSet sg;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        int x, l, y;
        cin >> c >> x >> l;
        y = x + l - 1;
        if (c == 'W') {
            sg.del(x, y);
        } else {
            sg.add(x, y);
        }
        cout << sg.size() << " " << sg.length() << endl;
    }
    return 0;
}
