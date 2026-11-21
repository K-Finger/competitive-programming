#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    ll max_element = x[0];
    ll max_deficit = 0;

    for (int i = 1; i < n; i++) {
        if (x[i] < max_element) {
            max_deficit = max(max_deficit, max_element - x[i]);
        }
        max_element = max(max_element, x[i]);
    }

    if (max_deficit == 0) {
        cout << 0 << '\n';
        return;
    }

    ll t = 0;
    while ((1LL << t) - 1 < max_deficit) {
        t++;
    }

    cout << t << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
