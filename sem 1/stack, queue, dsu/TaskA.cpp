#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n = 0;
    size_t k;
    cin >> k;
    vector<int> m(k + 2);
    for (size_t i = 0; i < k; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int num;
            cin >> num;
            m[n] = (n > 0) ? min(m[n - 1], num) : num;
            n++;
        } else if (op == 2) {
            n--;
        } else {
            cout << m[n - 1] << endl;
        }
    }
    return 0;
}
