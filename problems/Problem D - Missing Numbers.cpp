#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> s;
    
    int highest = a.back(); 
    for (int i = 1; i <= highest; i++) {
        s.insert(i);
    }

    for (int i = 0; i < n; i++) {
        s.erase(a[i]);
    }

    if (s.empty()) {
        cout << "good job\n";
    } else {
        for (auto x : s) {
            cout << x << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}
