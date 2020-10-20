#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;


vector<int> a, factors;

int value(int n, int r)
{
    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        ans += a[i] * a[i + 1];
    }
    return ans % r;
}

bool generate(int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            int m = i + 1;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] < a[m] && a[j] > a[i])
                {
                    m = j;
                }
            }
            swap(a[i], a[m]);
            while (i + 1 < n - 1)
            {
                swap(a[i + 1], a[n - 1]);
                i++;
                n--;
            }
            return true;
        }
    }
    return false;
}

void get_factors(int val)
{
    factors.clear();
    for (int i = 1; i * i <= val; ++i)
    {
        if (val % i == 0)
        {
            if (val / i == i)
            {
                factors.push_back(i);
                continue;
            }
            factors.push_back(i);
            factors.push_back(val / i);
        }
    }

}

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
    freopen("beautiful.in", "r", stdin);
    freopen("beautiful.out", "w", stdout);
#endif
    int n, r;

    cin >> n >> r;
    a.resize(static_cast<unsigned int>(n));
    int val, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        a[i] = i + 1;
    }
    do
    {
        val = value(n, r);
        get_factors(val);
        if (factors.size() % 3 == 0)
        {
            ++ans;
//            cout << "this one: factors are: ";
//            print(factors.size(), factors);
//            cout << "the permutation is: ";
        }
//        cout << "factors are: ";
//        print(factors.size(), factors);
//        print(n, a);
    } while (generate(n));
    cout << ans;

    return 0;
}
