#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    stack<int> st;
    vector<int> notPrinted;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '1') {
            st.push(i + 1);
        }
        else if (c == '2') {
            if (!st.empty()) {
                st.pop();

                notPrinted.push_back(i + 1);
            }
        }
    }

    while (!st.empty()) {
        notPrinted.push_back(st.top());
        st.pop();
    }

    sort(notPrinted.begin(), notPrinted.end());

    cout << notPrinted.size() << '\n';

    for (int x : notPrinted) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
