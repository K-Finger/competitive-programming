#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    ll sum = 0;

    for (int& x : a) {
        cin >> x;
        sum += x;
    }

    bool all_ones = true;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > 1) {
            all_ones = false;
        }
    }

    if (!all_ones) {
        cout << sum - 1 << '\n';
    }
    else if (a[0] > 1 || a[n - 1] > 1) {
        cout << sum - (n - 1) << '\n';
    }
    else {
        cout << -1 << '\n';
    }
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
