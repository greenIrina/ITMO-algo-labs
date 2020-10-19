#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{
    multiset<int> s;
    stack<int> st;
    int arr[10000];
    int n, m, r, num;

    vector<string> answer;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    r = 0;
    for (int i = 0; i < n; i++) {
        num = *s.begin();
        s.erase(s.begin());
        if (st.empty()) {
            m = num - 1;
        } else {
            m = st.top();
        }
        while (m != num && r < n) {
            st.push(arr[r++]);
            answer.emplace_back("push");
            m = st.top();
        }
        if (st.top() != num) {
            cout << "impossible";
            return 0;
        }
        st.pop();
        answer.emplace_back("pop");
    }
    for (const auto& i : answer) {
        cout << i << "\n";
    }
    return 0;
}
